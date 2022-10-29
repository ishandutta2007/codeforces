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
const int MAXN = 100500;  

int n, m, a, b, ans, processed;
vi g[MAXN];
vi t[MAXN];
int to[MAXN], used[MAXN];
vi cur;                   
queue<int> good;

void dfs(int v) {
	used[v] = 1;
	cur.pb(v);
	
	for (auto w: g[v])
		if (!used[w])
			dfs(w);
}

int main() {

	cin >> n >> m;
	
	forn(i, m) {
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		t[a].pb(b);	
	}
	
	ans = 0;
	forn(i, n)
		if (!used[i]) {
			cur.clear();
			dfs(i);	
			                    
			for (auto v: cur) {
				for (auto w: t[v])
					to[w]++;	
			}
			
			while (!good.empty())
				good.pop();
				
			for (auto v: cur)
				if (to[v] == 0)
					good.push(v);
					
			processed = 0;
			while (!good.empty()) {
				int v = good.front();
				good.pop();
				processed++;
				
				for (auto w: t[v]) {
					to[w]--;
					if (to[w] == 0)
						good.push(w);
				}   						
			}
			
			if (processed == (int)cur.size())
				ans += cur.size() - 1;
			else
				ans += cur.size();
		}	
	cout << ans;
                	
	return 0;
}