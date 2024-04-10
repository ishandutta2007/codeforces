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
const int MAXN = 200500;
const int MAXM = 20;         
const int MAXK = (int)131072 * 2;

int t[MAXK * 2 + 1];
int x[MAXN], l[MAXN], maxlink[MAXN], nxt[MAXN]; 

void tree_build() {                    
	forn(i, MAXK * 2 + 1)
		t[i] = MAXN - 1;
}

void update(int i, int val) {
    int v = MAXK + i;
    t[v] = val;
    while (v > 1) {
        v /= 2;
        if (x[t[2 * v]] + l[t[2 * v]] > x[t[2 * v + 1]] + l[t[2 * v + 1]])
        	t[v] = t[2 * v];
        else
        	t[v] = t[2 * v + 1];
    }
}

int get(int v, int lb, int rb, int lll, int rr) { //call with parametres (1, 1, MAXK, zL, zR)
    if ((rb < lll) || (rr < lb))
        return MAXN - 1;
    if ((lll <= lb) && (rb <= rr))
        return t[v];
    int id1 = get(2 * v, lb, (lb + rb) / 2, lll, rr);
    int id2 = get(2 * v + 1, (lb + rb) / 2 + 1, rb, lll, rr);
    if (x[id1] + l[id1] > x[id2] + l[id2])
    	return id1;
    return id2;
}

int n, m, a, b, used[MAXN];
pii jump[MAXN][MAXM];
vector<pii> g[MAXN];

int main() {

	scanf("%d", &n);
	forn(i, n) {
		scanf("%d%d", &x[i], &l[i]);	
	}		
	x[MAXN - 1] = l[MAXN - 1] = -INF;
	
	maxlink[n - 1] = n - 1; 
	update(n - 1, maxlink[n - 1]);
	nxt[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		int j = lower_bound(x, x + n, x[i] + l[i] + 1) - x;	
		j--;
		nxt[i] = min(n - 1, j + 1);
		
		if (j == i)
			maxlink[i] = i;
		else {
			maxlink[i] = get(1, 1, MAXK, i + 1, j + 1);
			if (x[i] + l[i] > x[maxlink[i]] + l[maxlink[i]])
				maxlink[i] = i;
		}
		update(i, maxlink[i]);
			
	}

	jump[n - 1][0] = mp(n - 1, 0);
	for (int i = n - 2; i >= 0; i--) {
		if (maxlink[i] == n - 1)
			jump[i][0] = mp(n - 1, 0);
		else {
			jump[i][0] = mp(nxt[maxlink[i]], x[nxt[maxlink[i]]] 
			- x[maxlink[i]] - l[maxlink[i]]);
			jump[i][0].X = maxlink[jump[i][0].X];
		}
	}

	for (int i = 1; i < MAXM; i++)
		forn(j, n) {
			jump[j][i].X = jump[jump[j][i - 1].X][i - 1].X;
			jump[j][i].X = maxlink[jump[j][i].X];
			jump[j][i].Y = jump[j][i - 1].Y + jump[jump[j][i - 1].X][i - 1].Y;				
		}	
	/*
	cout << "MAXLINKS\n";
	forn(i, n)
		cout << maxlink[i] << '\n';
	cout << "NXT\n";
	forn(i, n)
		cout << nxt[i] << '\n';
	cout << "JUMP\n";
	forn(i, n)
		cout << jump[i][0].X << ' ' << jump[i][0].Y << '\n';
	*/	
	scanf("%d", &m);
	forn(i, m) {
		scanf("%d%d", &a, &b);
		a--, b--;
		
		int ans = 0;
		for (int j = MAXM - 1; j >= 0; j--) {
			a = maxlink[a];
			if (x[jump[a][j].X] + l[jump[a][j].X] < x[b]) {
				ans += jump[a][j].Y;
				a = jump[a][j].X; 
			}
		}
		
		if (x[a] + l[a] < x[b])
			ans += jump[a][0].Y;
		printf("%d\n", ans);
	}
	
   	return 0;
}