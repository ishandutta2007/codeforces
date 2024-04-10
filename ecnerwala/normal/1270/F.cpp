#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;

const int MAXN = int(2e5) + 20;
int N;
bool S[MAXN];

const int B = 500;
int mp[MAXN * (B+2)];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string S_; cin >> S_;
	N = int(S_.size());
	for (int i = 0; i < N; i++) {
		S[i] = S_[i] - '0';
	}

	ll ans = 0;
	int k = 0;
	for (; k <= N && k <= B; k++) {
		{
			int v = N;
			mp[v]++;
			for (int i = 0; i < N; i++) {
				v += S[i] ? k : -1;
				ans += mp[v]++;
			}
		}
		{
			int v = N;
			--mp[v];
			for (int i = 0; i < N; i++) {
				v += S[i] ? k : -1;
				--mp[v];
			}
		}
	}
	vector<int> inds;
	inds.push_back(-1);
	for (int i = 0; i < N; i++) {
		if (S[i]) inds.push_back(i);
	}
	inds.push_back(N);
	for (int x = 1; x < int(inds.size())-1; x++) {
		for (int n1 = 1, y = x; y < int(inds.size())-1 && n1 <= N / (k+1); n1++, y++) {
			int len = inds[y] - inds[x] + 1;
			int ea = inds[x] - inds[x-1] - 1;
			int eb = inds[y+1] - inds[y] - 1;
			if (ea > eb) swap(ea, eb);
			assert(ea <= eb);
			// len .. len+ea+eb
			int v0 = max((len + n1 - 1) / n1, k+1);
			int v1 = max((len + ea) / n1, k);
			int v2 = max((len + eb + n1 - 1) / n1, k+1);
			int v3 = max((len + ea + eb) / n1, k);
			ans += ll(v1 - v0 + 1) * ll((v0*n1 - len + 1) + (v1*n1 - len + 1)) / 2;
			ans += ll(v2 - v1 - 1) * ll(ea + 1);
			ans += ll(v3 - v2 + 1) * ll((len+ea+eb - v2*n1 + 1) + (len+ea+eb - v3*n1 + 1)) / 2;
		}
	}
	cout << ans << '\n';

	return 0;
}