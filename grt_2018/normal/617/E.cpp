#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 100 * 1000 + 10, B = 350;
int n, m, k;

struct Q {
	int a, b, id;
	bool operator < (const Q &he) const {
		return make_pair(a/B, b) < make_pair(he.a/B, he.b);
	}
};

int A[nax];
Q q[nax];
int cnt[4000*1000 + 10];
ll w[nax];

int main() {_
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> A[i];
		A[i] ^= A[i - 1];
	}
	for(int i = 1; i <= m; ++i) {
		cin >> q[i].a >> q[i].b;
		q[i].a--;
		q[i].id = i;
	}
	sort(q + 1, q + m + 1);
	int l = 0, r = 0;
	ll ans = 0;
	cnt[A[0]] = 1;
	for(int i = 1; i <= m; ++i) {
		while(r < q[i].b) {
			r++;
			ans += cnt[A[r] ^ k];
			cnt[A[r]]++;
		}
		while(r > q[i].b) {
			cnt[A[r]]--;
			ans -= cnt[A[r]^k];
			r--;
		}
		while(l < q[i].a) {
			cnt[A[l]]--;
			ans -= cnt[A[l]^k];
			l++;
		}
		while(l > q[i].a) {
			l--;
			ans += cnt[A[l]^k];
			cnt[A[l]]++;
		}
		//~ cout << l << " " << r << ":\n";
		//~ for(int j = 0; j <= 3; ++j) cout << cnt[j] << " ";
		//~ cout << "\n";
		w[q[i].id] = ans;
	}
	for(int i = 1; i <= m; ++i) cout << w[i] << "\n";
			
	
	
}