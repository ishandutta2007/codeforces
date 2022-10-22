#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define pf push_front
#define mt make_tuple
#define endl '\n'
#define up front()
#define tp top()
#define em empty()
#define all(v) v.begin(),v.end()
#define fr(p) get<0>(p)
#define sc(p) get<1>(p)
#define th(p) get<2>(p)
#define fo(p) get<3>(p)
#define fi(p) get<4>(p)
#define dec(x) cout.setf(ios::fixed); cout.precision(x);
#define t(x) cout << #x << " : " << x << endl ;
#define ta1(a,s,e) cout << #a << " : " ; for (int iter = s; iter < e; iter++) cout << a[iter] << ' ' ; cout << endl ;
#define ta2(a,s,e) cout << #a << " : " ; for (int iter = s; iter <= e; iter++) cout << a[iter] << ' ' ; cout << endl ;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<ll, ll> pll;
typedef tuple<string, int> psi;
typedef tuple<string, ll> psl;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

vector<ll> po, ze, ne;

bool cmpp(ll x, ll y){ return x > y; }
bool cmpn(ll x, ll y){ return x < y; }

int main(){
    Fast;
    int t = 1;
    cin >> t;
    while (t--){
		po.clear(); ne.clear(); ze.clear();
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			ll x;
			cin >> x;
			if (x > 0) po.pb(x);
			else if (x < 0) ne.pb(x);
			else ze.pb(x);
		}
		sort(all(po), cmpp);
		sort(all(ne), cmpn);
		int pc = po.size(), nc = ne.size(), zc = ze.size();
		ll ans = -1e18;
		for (int i = 5; i >= 0; i--){
			if (i > pc) continue;
			for (int j = 5-i; j >= 0; j--){
				if (j > nc) continue;
				if (5-i-j > zc) continue;
				ll res = 1;
				for (int k = 0; k < i; k++) res *= po[k];
				for (int k = 0; k < j; k++) res *= ne[k];
				for (int k = 0; k < 5-i-j; k++) res *= ze[k];
				ans = max(ans, res);
			}
		}
		sort(all(po), cmpn);
		sort(all(ne), cmpp);
		for (int i = 5; i >= 0; i--){
			if (i > pc) continue;
			for (int j = 5-i; j >= 0; j--){
				if (j > nc) continue;
				if (5-i-j > zc) continue;
				ll res = 1;
				for (int k = 0; k < i; k++) res *= po[k];
				for (int k = 0; k < j; k++) res *= ne[k];
				for (int k = 0; k < 5-i-j; k++) res *= ze[k];
				ans = max(ans, res);
			}
		}
		cout << ans << endl;
	}
}