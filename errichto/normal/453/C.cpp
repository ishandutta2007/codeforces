#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e5+5;

vi w[nax], dzieci[nax];
bool x[nax];
bool vis[nax];
int ojc[nax];
vi res;

void dfs1(int a) {
	vis[a] = true;
	RE(i, w[a].size()) {
		int b = w[a][i];
		if(!vis[b]) {
			dzieci[a].pb(b);
			ojc[b] = a;
			dfs1(b);
		}
	}
}

void dfs2(int a) {
	res.pb(a);
	x[a] = !x[a];
	RE(i, dzieci[a].size()) {
		int b = dzieci[a][i];
		dfs2(b);
		res.pb(a);
		x[a] = !x[a];
	}
	if(x[a]) if(ojc[a]) {
		res.pb(ojc[a]);
		x[ ojc[a] ] = !x[ ojc[a] ];
		
		res.pb(a);
		x[a] = !x[a];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
	RE(i, m) {
		int a, b;
		cin >> a >> b;
		w[a].pb(b);
		w[b].pb(a);
	}
	RI(i, n) {
		int a;
		cin >> a;
		x[i] = (a == 1);
	}
	
	int start = 0;
	RI(i, n)
		if(x[i])
			start = i;
	if(start == 0) {
		cout << "0";
		return 0;
	}
	
	dfs1(start);
	
	RI(i, n) if(x[i] && !vis[i]) {
		cout << "-1";
		return 0;
	}
	
	dfs2(start);
	
	if(x[start]) res.pop_back();
	cout << res.size() << "\n";
	RE(i, res.size()) cout << res[i] << " ";
	
	return 0;
}