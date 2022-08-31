#include<bits/stdc++.h>
using namespace std;

void wssert(bool b) { if(!b) { cout << "GARBAGE" << '\n'; exit(0); } }

using i64 = int64_t;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		i64 N; cin >> N;
		int M; cin >> M;
		i64 K; cin >> K;

		vector<i64> P(M+2);
		P[0] = 0;
		for (int i = 1; i <= M; i++) cin >> P[i];
		P[M+1] = N;

		vector<i64> lens(M+1);
		for (int i = 0; i <= M; i++) {
			lens[i] = P[i+1] - P[i];
		}
		M++;

		auto upVal = [&](){
			i64 mi = 0;
			i64 ma = *max_element(lens.begin(), lens.end());
			while (ma - mi > 1) {
				i64 md = (mi + ma) / 2;
				i64 curK = 0;
				for (i64 l : lens) {
					curK += (l - 1) / md;
				}
				if (curK <= K) {
					ma = md;
				} else {
					mi = md;
				}
			}
			return ma;
		}();
		wssert(upVal <= N);

		auto downVal = [&]() {
			i64 mi = 1;
			i64 ma = *min_element(lens.begin(), lens.end())+1;
			while (ma - mi > 1) {
				i64 md = (mi + ma) / 2;
				i64 curK = 0;
				for (i64 l : lens) {
					curK += l / md - 1;
				}
				if (curK >= K) {
					mi = md;
				} else {
					ma = md;
				}
			}
			return mi;
		}();
		wssert(0 < downVal);

		wssert(downVal <= upVal);

		vector<pair<i64, i64>> options; options.reserve(M);

		for (i64 l : lens) {
			i64 upK = (l - 1) / upVal;
			i64 downK = l / downVal - 1;

			wssert(upK - downK <= 1);

			if (upK - downK == 1) {
				i64 loVal = l / (upK + 1);
				i64 hiVal = (l + downK) / (downK + 1);
				wssert(loVal < downVal && upVal < hiVal);

				options.emplace_back(loVal, hiVal);
			}
		}
		sort(options.begin(), options.end());

		i64 ans = N+1;
		i64 curUpVal = upVal;
		for (int i = 0; i < int(options.size()); i++) {
			ans = min(ans, curUpVal - options[i].first);
			curUpVal = max(curUpVal, options[i].second);
		}
		ans = min(ans, curUpVal - downVal);
		cout << ans << '\n';
	}

	return 0;
}