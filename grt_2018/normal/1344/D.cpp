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

//~ #define __int128 long long


const int nax = 100*1000+10;
const __int128 INF = 1e27;
int n;
ll k;
ll a[nax];
int odp[nax];
pair<__int128,int>memo[nax];

ll cnt(__int128 border) {
	ll res = 0;
	for(int i = 1; i <= n; ++i) {
		__int128 l = 0, r = a[i] - 1, mid;
		while(l <= r) {
			mid = (l + r)/2;
			__int128 eval = a[i] - (__int128)(3 * mid) * mid - 3 * mid - 1;
			if(eval >= border) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		res += l;
	}
	return res;
}

int main() {_
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	__int128 l = -INF, r = INF, mid;
	while(l <= r) {
		mid = (l+r)/2;
		//cout << mid << "\n";
		if(cnt(mid) < k) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	l--;
	ll upto = l + 1;
	//cout << upto << "\n";
	__int128 ans = 0;
	for(int i = 1; i <= n; ++i) {
		l = 0; r = a[i] - 1;
		while(l <= r) {
			mid = (l + r)/2;
			__int128 eval = a[i] - (__int128)(3 * mid) * mid - 3 * mid - 1;
			if(eval >= upto) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		__int128 used = min(k,(ll)l);
		odp[i] = used;
		ans += used * (a[i] - used*used);
		memo[i] = {a[i] - (__int128)(3 * l) * l - 3 * l - 1, i};
		k -= used;
	}
	sort(memo+1,memo+n+1);
	for(int i = n; i >= 1; --i) {
		if(odp[memo[i].ND] == a[memo[i].ND]) continue;
		if(k == 0) break;
		k--;
		odp[memo[i].ND]++;
		ans += memo[i].ST;
	}
	for(int i = 1; i <= n; ++i) {
		cout << odp[i] << " ";
	}
	//~ cout << ans;
}