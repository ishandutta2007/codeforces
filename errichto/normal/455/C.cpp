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
const int inf=1e9+5, nax=1e6+5;

int gr[nax];
bool vis[nax];
vi odw[nax], w[nax];
int m1[nax], m2[nax];
int wynik[nax];

void dfs(int a, int G) {
	vis[a] = true;
	gr[a] = G;
	odw[G].pb(a);
	m1[a] = 1;
	RE(i, w[a].size()) {
		int b = w[a][i];
		if(!vis[b]) {
			dfs(b, G);
			maxi(m2[a], m1[b] + 1);
			if(m2[a] > m1[a])
				swap(m1[a], m2[a]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, m, ile_zap;
	cin >> n >> m >> ile_zap;
	
	while(m--) {
		int a, b;
		cin >> a >> b;
		w[a].pb(b);
		w[b].pb(a);
	}
	
	RI(a, n) if(!vis[a]) {
		dfs(a, a);
		int r = 0;
		RE(i, odw[a].size()) {
			int x = odw[a][i];
			maxi(r, m1[x]);
			maxi(r, m1[x] + m2[x] - 1);
		}
		wynik[a] = r;
	}
	
	while(ile_zap--) {
		int rodz;
		cin >> rodz;
		if(rodz == 1) {
			int a;
			cin >> a;
			cout << wynik[gr[a]] - 1 << "\n";
		}
		else {
			int a, b;
			cin >> a >> b;
			a = gr[a];
			b = gr[b];
			if(a != b) {
				// b do a
				if(odw[b].size() > odw[a].size())
					swap(a, b);
				maxi(wynik[a], max(wynik[b], (wynik[a] + 2) / 2 + (wynik[b] + 2) / 2));
				RE(i, odw[b].size()) {
					int x = odw[b][i];
					gr[x] = a;
					odw[a].pb(x);
				}
			}
		}
	}
	return 0;
}