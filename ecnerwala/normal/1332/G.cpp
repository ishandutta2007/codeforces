#include<bits/stdc++.h>
using namespace std;

template <typename T> void setmax(T& a, const T& b) { if (b > a) a = b; }

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	int Q; cin >> Q;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<array<int, 3>> ans3(N, array<int, 3>({-1, -1, -1}));
	vector<array<int, 4>> ans4(N, array<int, 4>({-1, -1, -1, -1}));

	vector<int> highs;
	vector<int> lows;

	vector<bool> inHighs(N);
	vector<bool> inLows(N);

	set<int> nonHigh;
	set<int> nonLow;
	set<int> neither;

	for (int i = 0; i < N; i++) {
		// insert A[i]
		while (!highs.empty() && A[i] > A[highs.back()]) {
			inHighs[highs.back()] = false;
			nonHigh.insert(highs.back());
			if (!inLows[highs.back()]) {
				neither.insert(highs.back());
			}
			highs.pop_back();
		}
		while (!lows.empty() && A[i] < A[lows.back()]) {
			inLows[lows.back()] = false;
			nonLow.insert(lows.back());
			if (!inHighs[lows.back()]) {
				neither.insert(lows.back());
			}
			lows.pop_back();
		}

		inHighs[i] = inLows[i] = true;
		highs.push_back(i); lows.push_back(i);

		auto highIt = lower_bound(highs.begin(), highs.end(), i, [&A](int x, int y) { return A[x] > A[y]; } );
		auto lowIt = lower_bound(lows.begin(), lows.end(), i, [&A](int x, int y) { return A[x] < A[y]; } );
		int lastHigh = highIt == highs.begin() ? -1 : *--highIt;
		int lastLow = lowIt == lows.begin() ? -1 : *--lowIt;

		if (!highs.empty() && !lows.empty() && !neither.empty() && *neither.begin() < min(lastHigh, lastLow)) {
			auto it = neither.lower_bound(min(lastHigh, lastLow));
			--it;
			int bestNeither = *it;
			int c = *lower_bound(highs.begin(), highs.end(), bestNeither);
			int d = *lower_bound(lows.begin(), lows.end(), bestNeither);
			ans4[i] = {bestNeither, min(c, d), max(c, d), i};
		}

		if (!highs.empty() && !nonHigh.empty() && *nonHigh.begin() < lastHigh) {
			auto it = nonHigh.lower_bound(lastHigh);
			--it;
			int bestNonHigh = *it;
			setmax(ans3[i], {bestNonHigh, *lower_bound(highs.begin(), highs.end(), bestNonHigh), i});
		}
		if (!lows.empty() && !nonLow.empty() && *nonLow.begin() < lastLow) {
			auto it = nonLow.lower_bound(lastLow);
			--it;
			int bestNonLow = *it;
			setmax(ans3[i], {bestNonLow, *lower_bound(lows.begin(), lows.end(), bestNonLow), i});
		}
	}

	for (int i = 1; i < N; i++) {
		ans3[i] = max(ans3[i], ans3[i-1]);
		ans4[i] = max(ans4[i], ans4[i-1]);
	}

	for (int q = 0; q < Q; q++) {
		int L, R; cin >> L >> R;
		L--, R--;
		if (ans4[R][0] >= L) {
			cout << 4 << '\n';
			cout << ans4[R][0]+1 << ' ' << ans4[R][1]+1 << ' ' << ans4[R][2]+1 << ' ' << ans4[R][3]+1 << '\n';
		} else if (ans3[R][0] >= L) {
			cout << 3 << '\n';
			cout << ans3[R][0]+1 << ' ' << ans3[R][1]+1 << ' ' << ans3[R][2]+1 << '\n';
		} else {
			cout << 0 << '\n';
			cout << '\n';
		}
	}

	return 0;
}