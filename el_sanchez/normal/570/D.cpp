//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <cassert>
#include <ctime>
*/
               
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
#define db(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 500100;
const int ALPH = 26;

int n, m, p, h[MAXN], maxH, tmr, tin[MAXN], tout[MAXN];
int v, rh, curH, L, R, odds;
vi g[MAXN];
vector<pii> inH[MAXN];
int cnt[MAXN][ALPH];
int total[ALPH];
string s;

void dfs(int v, int ch) {
	maxH = max(maxH, ch);
	h[v] = ch;
	tin[v] = tmr++;
	
	inH[ch].pb({tin[v], v});
	
	for (auto w: g[v])
		dfs(w, ch + 1);
		
	tout[v] = tmr++;
}

int main() {
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d", &p);
		p--;
		g[p].pb(i);
	}
	cin >> s;
	
	tmr = 1;
	dfs(0, 0);
	
	forn(i, maxH + 1) {
		assert(!inH[i].empty());
		
		int pv = inH[i][0].Y;
		cnt[pv][s[pv] - 'a']++;
		forab(j, 1, inH[i].size()) {
			int v = inH[i][j].Y;
			forn(k, ALPH)
				cnt[v][k] = cnt[pv][k];
			cnt[v][s[v] - 'a']++;
			pv = v;	
		}				
	}

	forn(i, m) {
		scanf("%d%d", &v, &curH);
		v--;
		curH--;

		bool ok;
		if (inH[curH].empty()) {
			ok = 1;
		} else {
			pii p = {tin[v], -INF};
			L = lower_bound(all(inH[curH]), p) - inH[curH].begin();
			p = {tout[v], -INF};
			R = lower_bound(all(inH[curH]), p) - inH[curH].begin();	
			R--;
			
			if (L > R)
				ok = 1;
			else {
				//cerr << v << ' ' << L << ' ' << R << '\n';
				
				forn(j, ALPH) {
					total[j] = cnt[inH[curH][R].Y][j];
					if (L > 0)
						total[j] -= cnt[inH[curH][L - 1].Y][j];
				}
				
				odds = 0;
				forn(j, ALPH)
					odds += (total[j] & 1);
				/*
				forn(j, ALPH)
					cerr << total[j];
				cerr << endl;
				*/
				ok = (odds <= 1);
			}	   					
		}
        
		cout << (ok ? "Yes\n" : "No\n");	
	}
			
	return 0;
}