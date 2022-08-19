#include<bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T> void setmin(T& a, const T& b) { if (b < a) a = b; }
template <typename T> void setmax(T& a, const T& b) { if (b > a) a = b; }

optional<vector<int>> getOptimal(vector<pair<int, int>> ranges, int M, ll T) {
	int N = int(ranges.size());
	//sort(ranges.begin(), ranges.end());
	vector<int> ans; ans.reserve(N);

	ll curT = T;
	for (auto it : ranges) curT -= it.first;
	if (curT < 0) return nullopt;

	int idx = 0;

	priority_queue<int, vector<int>, greater<int>> upperBounds;

	int curVal = 0;
	while (int(ans.size()) < N) {
		assert(curT >= 0);
		int nxtVal = M+1;
		if (!upperBounds.empty()) {
			setmin(nxtVal, upperBounds.top());
		}
		if (idx < N) {
			setmin(nxtVal, ranges[idx].first);
		}
		assert(nxtVal <= M);

		assert(nxtVal >= curVal);
		if (int(upperBounds.size()) * ll(nxtVal - curVal) > curT) {
			// can't make it there
			nxtVal = int(curVal + curT / (int(upperBounds.size())));
		}

		curT -= int(upperBounds.size()) * ll(nxtVal - curVal);
		curVal = nxtVal;

		if (idx < N && ranges[idx].first == curVal) {
			upperBounds.push(ranges[idx].second);
			idx++;
		} else {
			assert(!upperBounds.empty());
			// make progress by removing this guy
			ans.push_back(curVal);
			upperBounds.pop();
		}
	}

	//for (auto v : ans) { cerr << v << ' '; } cerr << '\n';

	if (curT > 0) return nullopt;

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int NQ, NS; cin >> NQ >> NS;

	vector<pair<int, int>> questionSolveRanges(NQ);
	for (auto& it : questionSolveRanges) {
		cin >> it.first >> it.second;
	}

	int numRankScore; cin >> numRankScore;
	vector<pair<int, int>> rankScore(numRankScore);
	for (auto& it : rankScore) {
		cin >> it.first >> it.second;
		it.first--;
	}

	ll T; cin >> T;

	vector<int> questionSolves;
	{
		sort(questionSolveRanges.begin(), questionSolveRanges.end());
		auto v = getOptimal(questionSolveRanges, NS, T);
		if (!v) {
			cout << -1 << ' ' << -1 << '\n';
			exit(0);
		}
		questionSolves = std::move(*v);
	}

	vector<ll> minScorePref(NS+1);
	{
		for (int v : questionSolves) minScorePref[NS-v]++;
		for (ll curV = 0, curDiff = 0, i = 0; i <= NS; i++) {
			curDiff += minScorePref[i];
			minScorePref[i] = curV;
			curV += curDiff;
		}
	}

	auto isGoodScore = [&](const vector<int>& scores) -> bool {
		ll pref = 0;
		for (int i = 0; i < NS; i++) {
			pref += scores[i];
			if (pref < minScorePref[i+1]) return false;
		}
		return true;
	};

	vector<pair<int, int>> scoreRanges(NS, {0, NQ});
	for (auto it : rankScore) {
		scoreRanges[NS-1-it.first] = {it.second, it.second};
	}
	for (int i = 1; i < NS; i++) {
		setmax(scoreRanges[i].first, scoreRanges[i-1].first);
	}
	for (int i = NS-1; i > 0; i--) {
		setmin(scoreRanges[i-1].second, scoreRanges[i].second);
	}

	vector<int> optimalScores;
	{
		auto v = getOptimal(scoreRanges, NQ, T);
		if (!v) {
			cout << -1 << ' ' << -1 << '\n';
			exit(0);
		}
		optimalScores = std::move(*v);
	}
	if (!isGoodScore(optimalScores)) {
		cout << -1 << ' ' << -1 << '\n';
		exit(0);
	}

	auto canTie = [&](int numTie, int winningScore) -> bool {
		assert(winningScore >= optimalScores.back());
		vector<pair<int, int>> curRanges = scoreRanges;
		for (int i = 0; i < numTie; i++) {
			if (curRanges[NS-1-i].second < winningScore) {
				return false;
			}
			curRanges[NS-1-i].first = winningScore;
		}
		auto optimal = getOptimal(curRanges, NQ, T);
		if (!optimal) return false;
		return isGoodScore(*optimal);
	};

	auto getNumTie = [&]() -> int {
		int mi = 0, ma = NS+1;
		while (ma - mi > 1) {
			int md = (mi + ma) / 2;
			if (canTie(md, optimalScores.back())) mi = md;
			else ma = md;
		}
		assert(mi >= 1);
		return mi;
	};
	int numTie = getNumTie();

	auto getMaxScore = [&]() -> int {
		int mi = optimalScores.back() - 1, ma = NQ+1;
		while (ma - mi > 1) {
			int md = (mi + ma) / 2;
			if (canTie(numTie, md)) mi = md;
			else ma = md;
		}
		assert(mi >= optimalScores.back());
		return mi;
	};
	int maxScore = getMaxScore();

	cout << numTie << ' ' << maxScore << '\n';
	return 0;
}