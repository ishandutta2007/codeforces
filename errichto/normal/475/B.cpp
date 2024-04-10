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

vector<pii > w[22][22];
char sl[50];
char memo[50];
bool vis[22][22];
int H, W;

bool Ok(int a, int b) {
	return 0 < a && 0 < b && a <= W && b <= H;
}

void Dfs(int a, int b) {
	if(!Ok(a, b)) return;
	vis[a][b] = true;
	for(auto p : w[a][b]) {
		if(!vis[p.first][p.second])
			Dfs(p.first, p.second);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> H >> W;
	cin >> sl;
	RE(y, H) {
		if(sl[y] == '>') RE(x, W) w[x + 1][y + 1].pb(mp(x + 2, y + 1));
		else RE(x, W) w[x + 1][y + 1].pb(mp(x, y + 1));
	}
	RE(y, H) memo[y] = sl[y];
	cin >> sl;
	RE(x, W) {
		if(sl[x] == 'v') RE(y, H) w[x + 1][y + 1].pb(mp(x + 1, y + 2));
		else RE(y, H) w[x + 1][y + 1].pb(mp(x + 1, y));
	}
	
	Dfs(1, 1);
	RI(y, H) RI(x, W) if(!vis[x][y]) {
		cout << "NO";
		return 0;
	}
	RI(y, H) RI(x, W) {
		vis[x][y] = false;
		w[x][y].clear();
	}
	
	RE(x, W) {
		if(sl[x] == '^') RE(y, H) w[x + 1][y + 1].pb(mp(x + 1, y + 2));
		else RE(y, H) w[x + 1][y + 1].pb(mp(x + 1, y));
	}
	
	RE(y, H) {
		if(memo[y] == '<') RE(x, W) w[x + 1][y + 1].pb(mp(x + 2, y + 1));
		else RE(x, W) w[x + 1][y + 1].pb(mp(x, y + 1));
	}
	
	Dfs(1, 1);
	RI(y, H) RI(x, W) if(!vis[x][y]) {
		cout << "NO";
		return 0;
	}
	cout << "YES";
	
	return 0;
}