#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

vector<ll> arr[300020];
set<pi2> imp;
vector<int> cntv;
map<ll, int> cnt;

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++){
			ll x; cin >> x;
			if (cnt.count(x) == 0){ cnt[x] = 0; }
			cnt[x] += 1;
		}
		while (m--){
			ll a, b; cin >> a >> b;
			imp.insert({a, b});
			imp.insert({b, a});
		}
		for (pl2 p : cnt){
			if (arr[p.sc].empty()){ cntv.push_back(p.sc); }
			arr[p.sc].push_back(p.fr);
		}
		sort( all(cntv) );
		for (int c : cntv){
			sort(all(arr[c]), [](ll a, ll b){ return a > b; });
		}
		int cl = cntv.size();
		ll ans = 0;
		for (int i = cl-1; i >= 0; i--){
			for (int j = i-1; j >= 0; j--){
				int ci = cntv[i], cj = cntv[j];
				for (ll x : arr[ci]){
					for (ll y : arr[cj]){
						ll res = (ci+cj) * (x+y);
						if (res < ans){ break; }
						if (imp.count({x,y}) != 0){ continue; }
						ans = res; break;
					}
				}
			}
		}
		for (int i = 0; i < cl; i++){
			int ci = cntv[i];
			int vl = arr[ci].size();
			for (int j = 0; j < vl; j++){
				for (int k = j+1; k < vl; k++){
					ll res = (ci+ci) * (arr[ci][j] + arr[ci][k]);
					if (res < ans){ break; }
					if (imp.count({ arr[ci][j], arr[ci][k] }) != 0){ continue; }
					ans = res; break;
				}
			}
		}
		cout << ans << endl;
		for (int c : cntv){ arr[c].clear(); }
		imp.clear(); cntv.clear(); cnt.clear();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}