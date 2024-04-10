#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin,w.end()
const int inf=1e9+5,nax= 2005;

int t[nax][nax];
vector<pii > kr;
bool vis[nax];
vi w[nax];
int res[nax];
pii heh[nax];

struct cmp {
	bool operator()(int a, int b) {
		if(heh[a] != heh[b]) return heh[a] < heh[b];
		return a < b;
	}
};
set<int, cmp> s;

void dfs(int x) {
	vis[x] = true;
	RE(i, w[x].size()) {
		int b = w[x][i];
		if(!vis[b]) {
			res[b] = res[x] + t[x][b];
			mini(res[b], inf);
			dfs(b);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	if(n == 1) {
		int a;
		cin >> a;
		if(a == 0) cout << "YES";
		else cout << "NO";
		return 0;
	}
	
	RI(i, n) RI(j, n) cin >> t[i][j];
	RI(i, n) RI(j, n) if(t[i][i] != 0 || (i != j && t[i][j] == 0) || t[i][j] != t[j][i]) {
		cout << "NO";
		return 0;
	}
	int bi = 2, bj = 1;
	RI(i, n) RI(j, i - 1) if(t[i][j] < t[bi][bj]) {
		bi = i;
		bj = j;
	}
	RI(i, n) if(i != bi && i != bj) {
		heh[i] = min(mp(t[i][bi], bi), mp(t[i][bj], bj));
		s.insert(i);
	}
	kr.pb(mp(bi, bj));
	vis[bi] = vis[bj] = true;
	while(!s.empty()) {
		int a = *s.begin();
		kr.pb(mp(a, heh[a].second));
		s.erase(s.begin());
		vis[a] = true;
		RI(i, n) if(!vis[i]) {
			s.erase(i);
			mini(heh[i], mp(t[a][i], a));
			s.insert(i);
		}
	}
	if(kr.size() != n - 1) {
		cout << "NO";
		return 0;
	}
	RE(i, kr.size()) {
		pii p = kr[i];
		w[p.first].pb(p.second);
		w[p.second].pb(p.first);
	}
	RI(start, n) {
		RI(a, n) {
			vis[a] = false;
			res[a] = 0;
		}
		dfs(start);
		RI(a, n) if(res[a] != t[start][a]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}