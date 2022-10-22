#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const long long INF = 1e18;
const int inf = 1e9;

int n, m;
vector<int> g[100010];
int ans;
int p[100010];
set<int> S;
vector<int> e;
queue<int> Q;
bool chk[100010];

int Find(int a) {
	return p[a] = p[a] == a ? a : Find(p[a]);
}

int Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	p[b] = a;
} 

int main() {
	fast;

	cin >> n >> m;

	for(int i=0; i<m; i++) {
		int a, b;

		cin >> a >> b;

		g[a].pb(b);
		g[b].pb(a);
	}

	for(int i=1; i<=n; i++) {
		p[i] = i;
		S.insert(i);

		sort(all(g[i]));
	}


	for(int t=1; t<=n; t++) {
		if(chk[t]) continue;
		
		Q.push(t);
		chk[t] = true;
		
		while(Q.size()) {
			int i = Q.front();
			Q.pop();

			set<int>::iterator it = S.begin(), nit;

			for( ; it!=S.end(); it++) {
				if(binary_search(all(g[i]), *it) || Find(i) == Find(*it) || chk[*it]) continue;

				chk[*it] = true;
				e.pb(*it);
				Union(i, *it);
			}

			for(auto j : e) {
				Q.push(j);
				S.erase(j);
			}
			e.clear();
		}
	}

	ans = n-1;
	for(int i=1; i<=n; i++) 
		if(i != Find(i)) ans--;

	cout << ans;
}