#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

int t[nax];
int a[nax], b[nax], c[nax];
set<int> s;
vi odw[nax];
bool vis[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	RI(i, 4 * n) {
		s.insert(i);
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		// odw[a[i]].pb(i);
		odw[b[i]].pb(i);
		odw[c[i]].pb(i);
	}
	RI(i, n) t[i] = 4;
	puts("YES");
	while(!s.empty()) {
		int i = *(s.begin());
		vis[i] = true;
		printf("%d ", i);
		//printf("%d, zwiekszam %d i %d\n", i, b[i], c[i]);
		s.erase(s.begin());
		t[a[i]]--;
		t[b[i]]++;
		t[c[i]]++;
		//printf("{%d,%d,%d}\n", t[1], t[2], t[3]);
		vi h = vi{a[i],b[i],c[i]};
		for(int k : h) {
			for(int j : odw[k]) if(!vis[j]) {
				auto it = s.find(j);
				if(it != s.end()) s.erase(it);
				//printf("%d  %d %d\n", k, b[j], c[j]);
				t[a[j]]--;
				t[b[j]]++;
				t[c[j]]++;
				if(t[a[j]] <= 9 && t[b[j]] <= 9 && t[c[j]] <= 9) s.insert(j);
				t[a[j]]++;
				t[b[j]]--;
				t[c[j]]--;
			}
		}
	}
	RI(i, 4 * n) assert(vis[i]);
	puts("");
		
	
	return 0;
}