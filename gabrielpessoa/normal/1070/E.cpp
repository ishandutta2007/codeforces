#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int ms = 1e6+5;

ll n, m, t;
bool canComplete;
int a[ms];

ll solve(int d) {
	canComplete = false;
	int consecutivo = 0;
	ll tempoAcc = 0;;
	ll ans = 0;
	ll curTime = 0;
	for(int i = 0; i < n; i++) {
		if(consecutivo == m) {
			curTime += tempoAcc;
			tempoAcc = 0;
			consecutivo = 0;
		}
		if(a[i] <= d) {
			if(curTime + a[i] > t) return ans;
			consecutivo++;
			tempoAcc += a[i];
			curTime += a[i];
			ans++;
		}
	}
	canComplete = true;
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m >> t;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int lo = 1, hi = min(t, 200000ll);
		while(lo + 1 < hi) {
			int mid = (lo + hi)/2;
			solve(mid);
			if(canComplete) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		ll loAns = solve(lo);
		ll hiAns = solve(hi);
		if(loAns >= hiAns) cout << loAns << ' ' << lo << '\n';
		else cout << hiAns << ' ' << hi << '\n';
		//cout << max(solve(lo), solve(hi)) << '\n';
	}
}