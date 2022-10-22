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

int t,a,b,q,nww;
int cnt[200*200];

ll result(ll x) {
	ll w = x / nww * cnt[nww];
	w += cnt[x%nww];
	return w;
}

int main() {_
	cin >> t;
	while(t--) {
		cin >> a >> b >> q;
		nww = a*b/(__gcd(a,b));
		for(int i = 1; i <= nww; ++i) {
			cnt[i] = cnt[i-1] + (((i%a)%b) != ((i%b)%a));
		}
		while(q--) {
			ll l,r;
			cin >> l >> r;
			cout << result(r) - result(l-1) << " ";
		}
		cout << "\n";
	}
	
}