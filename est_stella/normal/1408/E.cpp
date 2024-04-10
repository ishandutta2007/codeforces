#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define em emplace
#define mp make_pair
#define pre(a) cout<<fixed; cout.precision(a);
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll; 
typedef long double ld;
const long long INF = 1e18;  
const int inf = 1e9;

int n, m;
int a[100010];
int b[100010];
int p[100010];
vector<pair<int, pii>> v;

vector<int> g[100010];

int Find(int a) { return p[a] ? p[a] = Find(p[a]) : a; }
void Union(int a, int b) { p[Find(b)] = Find(a); }

int main() {
	cin >> m >> n;

	for(int i=1; i<=m; i++) {
		cin >> a[i];
	}

	for(int i=1; i<=n; i++) {
		cin >> b[i];
	}

	ll ans = 0;
	for(int i=1; i<=m; i++) {
		int sz;
		cin >> sz;

		for(int j=1; j<=sz; j++) {
			int x;
			cin >> x;

			ans += a[i] + b[x];
			v.eb(- a[i] - b[x], mp(i, x));
		}
	}

	sort(all(v));


	for(auto i : v) {
		if(g[i.se.fi].size() && Find(g[i.se.fi].back()) == Find(i.se.se)) continue;

		if(g[i.se.fi].size()) Union(g[i.se.fi].back(), i.se.se);
		ans += i.fi;
		g[i.se.fi].eb(i.se.se);
	}

	cout << ans << "\n";
}