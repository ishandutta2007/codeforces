//#define _GLIBCXX_DEBUG
//#include <bits/stdc++.h>

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
        
int n, a, b, root;
vi g[MAXN];
int used[MAXN];
bool dp[MAXN][4];
int visited[MAXN][4];        

bool dfs(int v, int pr, int state) {
	//cout << v << endl;

	if (visited[v][state])
		return dp[v][state];

	bool ans = 0;
	if (state == 0) {

		if (g[v].size() == 1)
			ans = 1;
		else if (g[v].size() >= 3)
			ans = 0;
		else {
			int w = (g[v][0] != pr ? g[v][0] : g[v][1]);
			ans = dfs(w, v, 0);
		}
							
	} else if (state == 1) {

	    if (g[v].size() == 1)
	    	ans = 1;
	    else if (g[v].size() >= 4)
	    	ans = 0;
	    else {
	    	ans = 1;
	    	for (auto w: g[v]) {
	    		if (w == pr)
	    			continue;
	    		if (!dfs(w, v, 0))
	    			ans = 0;
	    	}
	    }		

   	} else {

   		int canFlang = state - 1;
   		vi curFlang;
   		curFlang.clear();

   		for (auto w: g[v]) {
   			if (w == pr)
   				continue;

   			if (!dfs(w, v, 1))
   				curFlang.pb(w);
   			if ((int)curFlang.size() > canFlang)
   				break;
   		}

   		if ((int)curFlang.size() > canFlang)
   			ans = 0;
   		else {
   			ans = 1;
   			for (auto w: curFlang) {
   				if (w == pr)
   					continue;

   				if (!dfs(w, v, 2))
   					ans = 0;
   			}
   		}

   		curFlang.clear();
   		
   	}

	visited[v][state] = 1;
	dp[v][state] = ans;
	return dp[v][state];	
}

int main() {

	cin >> n;
	forn(i, n - 1) {
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
		
	root = 0;
	forn(i, n)
		if (g[i].size() > g[root].size())
			root = i;

	if (g[root].size() <= 2) {
		cout << "Yes";
		return 0;
	}

	if (dfs(root, -1, 3))
		cout << "Yes";
	else {
		//cerr << "nope\n";
		if (g[root].size() == 3) {
			for (auto v: g[root]) {
				memset(visited, 0, sizeof(visited));
				memset(dp, 0, sizeof(dp));
				if (dfs(v, -1, 3)) {
					cout << "Yes";
					return 0;
				}
			}	
		}

		cout << "No";	
	}

	return 0;
}