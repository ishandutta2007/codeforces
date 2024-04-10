#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
template <typename T> void sortv(std::vector<T> &v) {
	sort(v.begin(), v.end());
}


vector<int> adj[110000];

int n, k, p;
vector<int> depths;

void dfs(int v, int p, int d) {
    depths.push_back(d);

    for (int x : adj[v]) if (x != p) {
        dfs(x,v,d+1);
    }
}

void solve() {
    scanf("%d %d %d", &n, &k, &p);
    
    REP(i,n-1) {
        int u,v;
        scanf("%d %d", &u, &v); u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0,-1,0);
    sortv(depths);

    int f = 1;
    long long s = 0;

    int ans = 0;
    for (int la = 1; la < (int)depths.size(); la++) {
        s += depths[la];
        while (f <= la && la-f+1 > k) {
            s -= depths[f];
            f++;
        }
        while (f <= la && depths[la]*1ll*(la-f+1) - s > p) {
            s -= depths[f];
            f++;
        }

        ans = max(ans, la-f+1);
    }
    
    printf("%d\n", ans);
}


int main() {
    solve();
}