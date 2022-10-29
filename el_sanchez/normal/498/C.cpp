#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>
#include <cfloat>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 111;
const int MAXV = 11111;

           
int n, m;
pii pairs[MAXN];
int f[MAXN];
int a[MAXN];
vi primes;
int answer;

struct edge {
	int w, f, c;
	int inv;
	
	edge(){};
	edge(int _w, int _f, int _c, int _inv):
		w(_w), f(_f), c(_c), inv(_inv) {};
};

int START, FINISH, SZ, TMR;
edge edges[MAXV];
int cnt, vidl[MAXN], vidr[MAXN];
vi g[MAXV];
int used[MAXV]; 

void addEdge(int v, int w, int capacity) {
	edges[cnt] = edge(w, 0, capacity, cnt + 1);
	edges[cnt + 1] = edge(v, 0, 0, cnt);
	g[v].push_back(cnt);
	g[w].push_back(cnt + 1);
	cnt += 2;
}  

bool dfs(int v, int f) {
	if (v == START) {
		TMR++;
		//cout << "dfs\n";
	}
	if (v == FINISH)
		return 1;
	used[v] = TMR;
	//cout << v << '\n';
	
	for (auto eid: g[v]) {
		int w = edges[eid].w;
		if (used[w] != TMR && edges[eid].f + f <= edges[eid].c) {
			if (dfs(w, f)) {
				edges[eid].f += f;
				edges[edges[eid].inv].f -= f;
				return 1;
			}
		}
	}
	
	return 0;
}

int getFlow(int p) {
	START = 0;
	FINISH = 1;
	SZ = 2;
	
	cnt = 0;
	for (int i = 0; i < n; i += 2)
		vidl[i] = SZ++;
	for (int i = 1; i < n; i += 2)
		vidr[i] = SZ++;
		
	//cout << p << endl;
	
	forn(i, n) {
		f[i] = 0;
		int t = a[i];
		while (t % p == 0) {
			t /= p;
			f[i]++;
		}
		//cout << f[i] << ' ';
	}
	//cout << endl;
	
	forn(i, SZ) {
		g[i].clear();
		used[i] = 0;
	}		
	for (int i = 0; i < n; i += 2)
		addEdge(START, vidl[i], f[i]);
	for (int i = 1; i < n; i += 2)
		addEdge(vidr[i], FINISH, f[i]);
	forn(i, m)
		addEdge(vidl[pairs[i].X], vidr[pairs[i].Y], INF);
		
	int flow = 0;
	TMR = 1;
	for (int val = (1 << 10); val > 0; val >>= 1)
		while (dfs(START, val))
			flow += val;
	return flow;	
}

int main() {

	cin >> n >> m;
	forn(i, n)
		cin >> a[i];
	forn(i, m) {
		cin >> pairs[i].X >> pairs[i].Y;
		pairs[i].X--;
		pairs[i].Y--;
		if (pairs[i].X & 1)
			swap(pairs[i].X, pairs[i].Y);
	}
		
	primes.clear();
	forn(i, n) {
		int t = a[i];
		for (int j = 2; j * j <= t; j++) {
			if (t % j == 0) {
				primes.pb(j);
				while (t % j == 0)
					t /= j;	
			}						
		}
		if (t > 1)
			primes.pb(t);
	}
       	
	sort(all(primes));
	int nsz = unique(primes.begin(), primes.end()) - primes.begin();
	primes.resize(nsz);
	
	answer = 0;
	forn(i, primes.size())
		answer += getFlow(primes[i]);
	cout << answer;
	
	return 0;
}