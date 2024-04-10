#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 2050;

int makeId(int a) {
	int odd = (a > 0 ? 0 : 1);	
	a = (abs(a) - 1) * 2 + odd;
	return a;
}

int n, m[2];
vi g[2][MAXN], ig[2][MAXN];
int compNum[2], compId[2][MAXN], used[2][MAXN];
vi comps[2][MAXN];
bitset<MAXN> canReach[2][MAXN];
int fxd[2][MAXN], val[2][MAXN];
int sz;
int order[MAXN];
bool solvable[2];
int a, b;

void dfs1(int id, int v) {
	used[id][v] = 1;

	for (auto w: g[id][v])
		if (!used[id][w])
			dfs1(id, w);

	order[sz++] = v; 
}

void dfs2(int id, int v) {
	//cout << compNum[id] << ": " << v << '\n';
	comps[id][compNum[id]].pb(v);
	compId[id][v] = compNum[id];
	used[id][v] = 1;

	for (auto w: ig[id][v])
		if (!used[id][w])
			dfs2(id, w);	
}

void solve2sat(int id) {
	memset(used[id], 0, sizeof(used[id]));

	sz = 0;
	forn(i, 2 * n)
		if (!used[id][i])
			dfs1(id, i);

	reverse(order, order + 2 * n);
	
	memset(used[id], 0, sizeof(used[id]));
    compNum[id] = 0;
	forn(i, 2 * n) {
		int v = order[i];
		if (!used[id][v]) {
			dfs2(id, v);
			compNum[id]++;
		}
	}
	
	//closure
	
	forn(k, 2 * n)
		forn(i, 2 * n)
			if (canReach[id][i][k])
				canReach[id][i] |= canReach[id][k];		
	/*
	cout << id << '\n';
	forn(i, 2 * n)
		cout << compId[id][i] << ' ';
	cout << '\n';
	forn(i, 2 * n) {
		forn(j, 2 * n)
			cout << canReach[id][i][j];
		cout << endl;
	}
	*/
	forn(i, n)
		if (compId[id][2 * i] == compId[id][2 * i + 1]) {
			solvable[id] = 0;
			return;
		}
		
	solvable[id] = 1;
	
	memset(fxd[id], 0, sizeof(fxd[id]));
		
	forn(i, n) {
		assert(!canReach[id][2 * i + 1][2 * i] || !canReach[id][2 * i][2 * i + 1]);
		
		if (canReach[id][2 * i + 1][2 * i]) {
			fxd[id][i] = 1;
			val[id][i] = 1;
		} else if (canReach[id][2 * i][2 * i + 1]) {
			fxd[id][i] = 1;
			val[id][i] = 0;
		}
	}
}

void dfs3(int id, int v) {
	for (auto w: g[id][v]) {
		int z = (w >> 1);
		if (!fxd[id][z]) {
			fxd[id][z] = 1;
			val[id][z] = (w & 1) ^ 1;  
			//cout << "set: " << id << ' ' << z << ' ' << val[id][z] << '\n';
			dfs3(id, (2 * z) ^ val[id][z] ^ 1);
		}
	}
}

void fixVariables(int id) {
	forn(i, n)
		if (fxd[id][i])
			dfs3(id, (2 * i) ^ val[id][i] ^ 1);
}

pii queries[2][MAXN * MAXN];
int result[2];

void genAnswer(int id) {
	/*
	cout << "ID: " << id << '\n';
	forn(i, n)
		if (fxd[id][i])
			cout << i << " = " << val[id][i] << '\n';
	*/		
	forn(i, n)
		if (!fxd[id][i]) {
			fxd[id][i] = 1;
			if (compId[id][2 * i] < compId[id][2 * i + 1]) {
				val[id][i] = 0;
			} else {
				val[id][i] = 1;	
			}
		}
		
	forn(t, 2) {
		result[t] = 1;
		forn(i, m[t]) {                  
			int v1 = abs(queries[t][i].X) - 1;
			int v2 = abs(queries[t][i].Y) - 1;
			int z1 = (queries[t][i].X > 0 ? 0 : 1);
			int z2 = (queries[t][i].Y > 0 ? 0 : 1);
			
			//cout << v1 << ' ' << z1 << ' ' << v2 << ' ' << z2 << '\n';
			
			result[t] &= ((val[id][v1] ^ z1) || (val[id][v2] ^ z2));
		}
	}
	
	//assert(result[0] != result[1]);
	
	forn(i, n) {
		//cout << val[id][i] << '\n';
		printf("%d%c", val[id][i], " \n"[i == n - 1]);
	}
}

void addEdge(int id, int a, int b) {
	canReach[id][a ^ 1][b] = 1;
	canReach[id][b ^ 1][a] = 1;
	
	g[id][a ^ 1].pb(b);
	ig[id][b].pb(a ^ 1);

	g[id][b ^ 1].pb(a);
	ig[id][a].pb(b ^ 1);
}

int main() {

	scanf("%d%d%d", &n, &m[0], &m[1]);
    forn(id, 2) {
    	forn(j, 2 * n)
    		canReach[id][j][j] = 1;
    		
    	forn(j, m[id]) {
    		scanf("%d%d", &a, &b);
    		queries[id][j] = {a, b};
    		
    		a = makeId(a);
    		b = makeId(b);
    		
    		addEdge(id, a, b);	
    	}
    	
    	solve2sat(id);
    }
	
    if (!solvable[0] && !solvable[1]) {
    	cout << "SIMILAR\n";
    } else if (solvable[0] != solvable[1]) {
    	forn(i, 2)
    		if (solvable[i]) {
    			genAnswer(i);
    			return 0;
    		}
    } else {
    	forn(id, 2)
    		fixVariables(id);
    		
    	forn(i, n) {
    		if ((fxd[0][i] != fxd[1][i]) || (fxd[0][i] && fxd[1][i] && val[0][i] != val[1][i])) {
    			//cout << i << endl;
    		    //cout << fxd[0][i] << ' ' << val[0][i] << '\n';
    		    
    		    int id = 0;
    		    if (fxd[id][i])
    		    	id ^= 1;

    		    if (!fxd[id][i]) {	
    		    	fxd[id][i] = 1;
    				val[id][i] = !val[id ^ 1][i];
    				dfs3(id, (2 * i) ^ val[id][i] ^ 1);
    		    }
    			    			
    			genAnswer(id);
    			return 0;
    		}
    	}
    		
    	forn(i, 2 * n)
    		forn(j, 2 * n) {
    			bool ok = 1;
    			forn(id, 2) {
    				if (fxd[id][i >> 1])
    					ok = 0;
    				if (fxd[id][j >> 1])
    					ok = 0;
    			}
    			
    			if (!ok)
    				continue;
    				
    			if ((i >> 1) != (j >> 1) && canReach[0][i][j] != canReach[1][i][j]) {
    				forn(id, 2)
    					if (canReach[id][i][j]) {
    						//cout << "! " << id << ' ' << i << ' ' << j << endl;
    			
    						int qi = (i >> 1);
    						int qj = (j >> 1);
    						
    						fxd[id ^ 1][qi] = 1;
    						fxd[id ^ 1][qj] = 1;
    						val[id ^ 1][qi] = (i & 1) ^ 1;
    						val[id ^ 1][qj] = (j & 1);
    						
    						dfs3(id ^ 1, (2 * qi) ^ val[id ^ 1][qi] ^ 1);
    						dfs3(id ^ 1, (2 * qj) ^ val[id ^ 1][qj] ^ 1);
    						
    						//cout << val[id ^ 1][0] << ' ' << val[id ^ 1][1] << '\n';
    						
    						genAnswer(id ^ 1);
    						return 0;
    					}
    			}
    		}                                                                        	
    	cout << "SIMILAR\n";
    }
		
	return 0;
}