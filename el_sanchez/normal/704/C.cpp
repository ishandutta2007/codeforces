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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;
const int MAXN = 100500;
const int MOD = (int)1E9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;	
}

int n, m;
vi a[MAXN];
vi where[MAXN];
int used[MAXN], useda[MAXN];
int put[MAXN];
int ans, mult;
vi st[2], sgn[2];
vi cur[2], dp[2];
vi f[2][2][2];
int collect[2];
vi indexes;

void add() {
	assert(st[0].size() >= 1);
	assert(st[0].size() == st[1].size());
	
	forn(i, 2) {
		sgn[i].clear();
		sgn[i].resize(st[i].size(), 0);
		forn(j, st[i].size())
			if (st[i][j] < 0) {
				sgn[i][j] = 1;
				st[i][j] *= -1;
			}
	}
	
	int curAns[2], tmpAns[2];
	forn(i, 2)
		curAns[i] = 0;
		
	forn(v1, 2)
		forn(v2, 2) {
			forn(i, 2)
				forn(j, st[i].size())
					put[st[i][j]] = -1;
			
			if (st[0][0] == 0 && v1)
				continue;
			if (st[1][0] == 0 && v2)
				continue;
				
			put[st[0][0]] = v1;
			if (put[st[1][0]] != -1 && put[st[1][0]] != v2)
				continue;
				
			put[st[1][0]] = v2;

			forn(i, 2)
				forn(j, 2)
					forn(k, 2) {
						f[i][j][k].clear();	
						f[i][j][k].resize(st[0].size(), 0);
					}
				
			f[v1][v2][(sgn[0][0] ^ v1) || (sgn[1][0] ^ v2)][0] = 1;
			for (int i = 0; i < (int)st[0].size() - 1; i++) {
				forn(l1, 2)
					forn(l2, 2)
						forn(res, 2) 
							if (f[l1][l2][res][i]) {
								put[st[0][i]] = l1;
								put[st[1][i]] = l2;
                    
								forn(w1, 2)
									forn(w2, 2) {
										if (put[st[0][i + 1]] != -1 && put[st[0][i + 1]] != w1)
											continue;
										if (put[st[1][i + 1]] != -1 && put[st[1][i + 1]] != w2)
											continue;

			if (st[0][i + 1] == 0 && w1)
				continue;
			if (st[1][i + 1] == 0 && w2)
				continue;
			
										add(f[w1][w2][res ^ ((sgn[0][i + 1] ^ w1) || (sgn[1][i + 1] ^ w2))][i + 1], f[l1][l2][res][i]);
									}
							}
			}
			
			forn(i, 2)
				tmpAns[i] = 0;
				
			forn(l1, 2)
				forn(l2, 2)
					forn(res, 2)
						add(tmpAns[res], f[l1][l2][res][st[0].size() - 1]); 
			 		
			 //cout << v1 << v2 << " ->\n";
			 forn(i, 2) {
				// cout << tmpAns[i] << " \n"[i == 1];
				 add(curAns[i], tmpAns[i]);
			 }
			 
		}
		
	//cout << "ANS:\n";
	forn(i, 2) {
		cur[i].pb(curAns[i]);
		//cout << curAns[i] << " \n"[i == 1];
	}
}

void dfs1(int id, int v) {
	useda[id] = 1;
	used[v] = 1;
	assert(!where[v].empty());
	
	forn(i, a[id].size())
		st[i].pb(a[id][i]);
	if (st[0].size() > st[1].size())
		st[1].pb(0);
		
	//try next letter
	for (auto ww: a[id]) {
		int w = abs(ww);
		if (!used[w]) {
			used[w] = 1;
			for (auto id2: where[w])
				if (!useda[id2])
					dfs1(id2, w); 	
		}
	}
	
	//try next clause
	for (auto id2: where[v]) {
		if (!useda[id2]) {
			dfs1(id2, v);
		}
	}
}

int main() {

	scanf("%d%d", &n, &m);
	forn(i, n) {
		int k;
		scanf("%d", &k);
		a[i].resize(k);
		forn(j, k) {
			scanf("%d", &a[i][j]);			
			where[abs(a[i][j])].pb(i);
		}
	}
	
	
	mult = 1;
	forab(i, 1, m + 1)
		if (where[i].empty()) {
			used[i] = 1;
			mult = (mult * 2) % MOD;
		}
			
	forab(i, 1, m + 1)
		if (!used[i]) {
			forn(j, 2)
				st[j].clear();

			for (auto id: where[i]) {
				if (!useda[id]) {
					dfs1(id, i);
				}
			}
			/*
			cout << "NEXT:\n";
			forn(j, st[0].size())
				cout << st[0][j] << ' ' << st[1][j] << '\n';
			cout << "---\n";
			
			forn(j, 2)
				collect[j] = 0;
			//memset(put, -1, sizeof(put));
			//gen(0, 0, 0);
			indexes.clear();
			forn(j, 2)
				forn(k, st[j].size())
					indexes.pb(abs(st[j][k]));
			sort(all(indexes));
			indexes.resize(unique(all(indexes)) - indexes.begin());
			memset(put, -1, sizeof(put));
			forn(mask, 1 << indexes.size()) {
				forn(i, indexes.size())
					put[indexes[i]] = (mask >> i) & 1;
				if (put[0] == 0)
					continue;
					
				int res = 0;
				forn(j, st[0].size()) {
					int cur = 0;
					forn(k, 2)
						if (st[k][j] > 0)
							cur |= put[st[k][j]];
						else if (st[k][j] == 0)
							cur |= 1;
						else
							cur |= !put[-st[k][j]];
							
					res ^= cur;
				}
				
				collect[res]++;
			}
			
			forn(j, 2)
				cout << collect[j] << " \n"[j == 1];
			*/	
			add();		
		}
	
	forn(i, 2)
		dp[i].resize(cur[i].size() + 1, 0);
		
	dp[0][0] = 1;
	dp[1][0] = 0;
	for (int i = 0; i < (int)cur[0].size(); i++) {
		forn(f, 2)
			forn(nf, 2) 
				add(dp[f ^ nf][i + 1], 1ll * dp[f][i] * cur[nf][i] % MOD);
	}
	
	ans = dp[1][cur[0].size()];
	ans = (1ll * ans * mult) % MOD;
	cout << ans << '\n';
	
	return 0;
}