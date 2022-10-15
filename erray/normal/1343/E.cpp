#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h> 
#define pb emplace_back
#define mp make_pair 
#define st first 
#define nd second 
#define all(v) v.begin(),v.end()
#define umap unordered_map
#define L nd<<1
#define R (L)|1
#define mid ((s + e)>>1)
#define max(aa, bb) (aa > bb ? aa : bb)
#define min(aa, bb) (aa < bb ? aa : bb)
#define ln '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 500005;
int T, n, m, a, b, c, n1, n2, cst, sp[3][N];
vi cs, edge[N];
vector <ll> pref; 
void BFS(int nd, int q){
	queue <int> nds;
	nds.push(nd);
	sp[q][nd] = 0;
	while(!nds.empty()){
		int nnd = nds.front();
		nds.pop();
		for(int e : edge[nnd]){
			if(sp[q][e] == -1){
				nds.push(e);
				sp[q][e] = sp[q][nnd] + 1;
			}
			//else cout << q << " " << e << ln;
		}
	} 
}
void solve(){
	ll ans = (1ll<<62);
	cin >> n >> m >> a >> b >> c;
	--a;--b;--c;
	for(int i = 0; i < n; ++i){sp[0][i] = -1;sp[2][i] = -1;sp[1][i] = -1;edge[i].clear();}
	for(int i = 0; i < m; ++i){
		cin >> cst;
		cs.pb(cst);
	}
	sort(all(cs));
	ll sum = 0;
	for(int i = 0; i < m; ++i, sum += cs[i - 1])pref.pb(sum);
	pref.pb(sum);
	while(m--){
		cin >> n1 >> n2;
		--n1;--n2;
		edge[n1].pb(n2);
		edge[n2].pb(n1);
		//cout << n1 << " " << n2 << ln;
	}
	BFS(a, 0);BFS(b, 1);BFS(c, 2);
	for(int i = 0; i < n; ++i){
		ll bst = 0;
		for(int j = 0; j < 3; ++j){
			bst += sp[j][i];
			//cout << (char)('a' + j) << " --> " << i + 1 << " = " << sp[j][i] << ln;
		}
		if(bst < pref.size())ans = min(ans, pref[bst] + pref[sp[1][i]]);
	}
	cout << ans << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> T;
  while(T--){
  	cs.clear();
  	pref.clear();
  	solve();
  }
}