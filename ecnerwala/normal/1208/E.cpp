#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

const int MAXQ = 1.1e6;
int Q;
const int MAXW = 1.1e6;
int W;
ll ans_const = 0;
ll ans[MAXW];

const int MAXL = MAXW;
int L;
ll A[MAXL];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> Q >> W;
	for (int q = 0; q < Q; q++) {
		cin >> L;
		for (int i = 0; i < L; i++) {
			cin >> A[i];
		}

		if (L + L <= W) {
			ll ma = *max_element(A, A + L);
			ma = max(ma, 0ll); // can always be 0
			ans_const += ma;

			{
				ll v = 0;
				for (int i = 0; i < L; i++) {
					v = max(v, A[i]);
					ans[i] += v - ma;
				}
			}

			{
				ll v = 0;
				for (int i = L-1; i >= 0; i--) {
					v = max(v, A[i]);
					ans[(W-L) + i] += v - ma;
				}
			}

		} else {
			// do each range
			deque<int> dq;
			for (int i = 0; i < W; i++) {
				// it can be anything from [i - (W-L), i]
				// insert i
				if (i < L) {
					while (!dq.empty() && A[dq.back()] <= A[i]) {
						dq.pop_back();
					}
					dq.push_back(i);
				}

				ll v = A[dq.front()];
				if (i >= L || i - (W-L) < 0) v = max(v, 0ll);
				ans[i] += v;

				if (i >= (W-L)) {
					if (!dq.empty() && dq.front() == i - (W-L)) {
						dq.pop_front();
					}
				}
			}
		}

	}

	for (int i = 0; i < W; i++) {
		cout << (ans[i]+ans_const) << " \n"[i+1==W];
	}

	return 0;
}