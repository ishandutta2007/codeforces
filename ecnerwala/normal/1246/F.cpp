#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
int A[MAXN];
int charL[MAXN][27], charR[MAXN][27];
int rangeL[MAXN], rangeR[MAXN];

int leftPar[MAXN][20];
ll leftParSum[MAXN][20];
int rightPar[MAXN][20];
ll rightParSum[MAXN][20];

const int S = 1 << 17;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	{
		string s; cin >> s;
		N = int(s.size());
		for (int i = 1; i <= N; i++) {
			A[i] = s[i-1] - 'a';
		}
		A[0] = A[N+1] = -1;
	}

	for (int c = 0; c < 26; c++) {
		charL[0][c] = 0;
		charR[N+1][c] = N+1;
	}
	for (int i = 1; i <= N; i++) {
		for (int c = 0; c < 26; c++) {
			charL[i][c] = A[i-1] == c ? i-1 : charL[i-1][c];
		}
	}
	for (int i = N; i >= 1; i--) {
		for (int c = 0; c < 26; c++) {
			charR[i][c] = A[i+1] == c ? i+1 : charR[i+1][c];
		}
	}

	for (int i = 1; i <= N; i++) {
		rangeL[i] = max(charL[i][A[i]], 1);
		rangeR[i] = min(charR[i][A[i]], N);
	}
	rangeL[0] = 0;
	rangeR[0] = 0;
	rangeL[N+1] = N+1;
	rangeR[N+1] = N+1;

	{
		vector<pair<int, int>> q;
		q.emplace_back(1, 1);
		for (int z = 0; z < 20; z++) {
			leftPar[0][z] = leftPar[1][z] = 0;
		}
		for (int i = 2; i <= N; i++) {
			leftPar[i][0] = lower_bound(q.begin(), q.end(), pair<int, int>(rangeL[i], -1))->first;
			leftParSum[i][0] = rangeL[i] - 1;
			for (int z = 0; z+1 < 20; z++) {
				leftPar[i][z+1] = leftPar[leftPar[i][z]][z];
				leftParSum[i][z+1] = leftParSum[i][z] + leftParSum[leftPar[i][z]][z];
			}
			while (!q.empty() && q.back().second >= rangeL[i]) {
				q.pop_back();
			}
			q.emplace_back(i, rangeL[i]);
		}
	}

	{
		vector<pair<int, int>> q;
		q.emplace_back(-N, N);
		for (int z = 0; z < 20; z++) {
			rightPar[N+1][z] = rightPar[N][z] = N+1; // parent is the root
		}
		for (int i = N-1; i >= 1; i--) {
			rightPar[i][0] = -lower_bound(q.begin(), q.end(), pair<int, int>(-rangeR[i], -1))->first;
			assert(rightPar[i][0] > i);
			rightParSum[i][0] = N - rangeR[i];
			for (int z = 0; z+1 < 20; z++) {
				rightPar[i][z+1] = rightPar[rightPar[i][z]][z];
				rightParSum[i][z+1] = rightParSum[i][z] + rightParSum[rightPar[i][z]][z];
			}
			while (!q.empty() && q.back().second <= rangeR[i]) {
				q.pop_back();
			}
			q.emplace_back(-i, rangeR[i]);
		}
	}

	/*
	for (int i = 1; i <= N; i++) {
		cerr << "vert " << i << ": ";
		cerr << "rangeL=" << rangeL[i] << ' ';
		cerr << "rangeR=" << rangeR[i] << ' ';
		cerr << "leftPar=" << leftPar[i][0] << ' ';
		cerr << "rightPar=" << rightPar[i][0] << ' ';
		cerr << '\n';
	}
	*/

	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		vector<int> lefts;
		vector<int> rights;
		for (int c = 0; c < 26; c++) {
			if (A[i] == c) continue;
			if (charL[i][c] != 0) {
				lefts.push_back(charL[i][c]);
			}
			if (charR[i][c] != N+1) {
				rights.push_back(charR[i][c]);
			}
		}
		lefts.push_back(0);
		sort(lefts.begin(), lefts.end());
		rights.push_back(N+1);
		sort(rights.begin(), rights.end(), std::greater<int>());

		ans += N-1; // the first step
		//cerr << "Query " << i << '\n';
		int curL = i, curR = i;
		while (curL != 0 || curR != N+1) {
			assert(0 <= curL && curL <= N);
			assert(1 <= curR && curR <= N+1);
			assert(!lefts.empty() || !rights.empty());
			auto isGood = [&](int l, int r) {
				return (!lefts.empty() && rangeL[l] <= lefts.back()) || (!rights.empty() && rangeR[r] >= rights.back());
			};
			if (!isGood(curL, curR)) {
				int z = 0;
				while (!isGood(leftPar[curL][z], rightPar[curR][z])) {
					z++;
				}
				assert(isGood(leftPar[curL][z], rightPar[curR][z]));
				while (z > 0) {
					--z;
					if (!isGood(leftPar[curL][z], rightPar[curR][z])) {
						ans += leftParSum[curL][z] + rightParSum[curR][z];
						curL = leftPar[curL][z];
						curR = rightPar[curR][z];
					}
				}
				assert(!isGood(curL, curR));
				ans += leftParSum[curL][z] + rightParSum[curR][z];
				curL = leftPar[curL][z];
				curR = rightPar[curR][z];
			}
			//assert(isGood(curL, curR));

			int l = rangeL[curL];
			int r = rangeR[curR];
			//cerr << l << ' ' << curL << ' ' << curR << ' ' << r << ' ' << leftParSum[curL][0] + rightParSum[curR][0] << '\n';
			ans += leftParSum[curL][0] + rightParSum[curR][0];
			curL = leftPar[curL][0];
			curR = rightPar[curR][0];
			while (!lefts.empty() && l <= lefts.back()) {
				if (rangeR[lefts.back()] > rangeR[curR]) {
					curR = lefts.back();
				}
				lefts.pop_back();
			}
			while (!rights.empty() && r >= rights.back()) {
				if (rangeL[rights.back()] < rangeL[curL]) {
					curL = rights.back();
				}
				rights.pop_back();
			}
		}
	}

	cout << ans << '\n';
	return 0;
}