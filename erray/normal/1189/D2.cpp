#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair  
#define st first 
#define nd second 
#define all(v)  v.begin(),v.end()
#define max(aa, bb) (aa > bb ? aa : bb)
#define min(aa, bb) (aa < bb ? aa : bb)
#define ln '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
struct E{
	int n1, n2, val;
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	int n, a, b, val;
	cin >> n;
	vector <E> v(n - 1);
	vi edge[n + 1]; 
	for(int i = 0; i < n - 1; ++i){
		cin >> a >> b >> val;
		edge[a].pb(b);
		edge[b].pb(a);
		v[i].n1 = a;
		v[i].n2 = b;
		v[i].val = val;
	}
	for(int i = 1; i <= n; ++i){
		if(edge[i].size() == 2){
			cout << "NO" << ln;
			return 0;
		}
	}
	cout << "YES" << ln;	
	vector <pair <int, pair <int, int> > > ans; 
	for(E ed : v){
		int l1 = 0, l2 = 0, r1 = 0, r2 = 0, d = ed.val>>1;
		function <void(int, int, bool)> dfs = [&](int nd, int par, bool dir){
			if(edge[nd].size() == 1){
				if(!dir){
					if(!l1) l1 = nd;
					l2 = nd;
				}
				else{
					if(!r1) r1 = nd;
					r2 = nd;
				}
			}
			for(int a : edge[nd]){
				if(a != par){
					dfs(a, nd, dir);
				}
			}
		};
		dfs(ed.n1, ed.n2, 0);
		dfs(ed.n2, ed.n1, 1);
		ans.pb(mp(l1, mp(r1, d)));
		ans.pb(mp(l2, mp(r2, d)));
		if(edge[ed.n1].size() != 1)ans.pb(mp(l2, mp(l1, -d)));
		if(edge[ed.n2].size() != 1)ans.pb(mp(r2, mp(r1, -d)));
	}
	cout << ans.size() << ln;
	for(auto pr : ans){
		cout << pr.st << " " << pr.nd.st << " " << pr.nd.nd << ln;
	}
}