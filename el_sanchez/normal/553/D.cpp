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
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;
const int MAXN = 100500;
const int MAXI = 100;

int n, m, k, a, b, tmr = 0, rest;
int bad[MAXN], lim[MAXN], curSz[MAXN], used[MAXN];
vi g[MAXN];
ld L, R, M;
vi answer;
queue<int> wipe;

bool good(ld param, int print) {
	forn(i, n) {
		lim[i] = int(param * g[i].size() + 1.0 - eps);
		curSz[i] = g[i].size();
	}	
	tmr++;
	rest = n;
	
	while (!wipe.empty())
		wipe.pop();
	forn(i, k) {
		wipe.push(bad[i]);
		used[bad[i]] = tmr;
		rest--;
	}
	
	while (!wipe.empty()) {
		int v = wipe.front();	
		wipe.pop();
		
		for (auto w: g[v]) {
			curSz[w]--;
			if (curSz[w] < lim[w] && used[w] != tmr) {
				used[w] = tmr;
				rest--;
				wipe.push(w);
			}
		}
	}	
	
	if (rest == 0)
		return 0;
	if (print) {
		answer.clear();
		forn(i, n)
			if (used[i] != tmr)
				answer.pb(i);	
	}
	return 1;
}
int main() {

	scanf("%d%d%d", &n, &m, &k);
	forn(i, k) {
		scanf("%d", &bad[i]);
		bad[i]--;
	}
	
	forn(i, m) {
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	//forn(i, n)
	//	db(g[i].size());
		
	L = -eps;
	R = 1 + eps;
	forn(iter, MAXI) {
		M = (L + R) / 2;
		if (good(M, 0))
			L = M;
		else
			R = M;		
	}
	
	//cout.precision(10);
	
	good(L, 1);
	/*
	db(L);
	forn(i, n)
		db(lim[i]);
	*/	
	cout << answer.size() << '\n';
	forn(i, answer.size())
		printf("%d ", answer[i] + 1);
		
	return 0;
}