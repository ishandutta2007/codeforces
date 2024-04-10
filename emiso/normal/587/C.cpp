#include <bits/stdc++.h>

#define MN 100100
#define LG 20

using namespace std;

typedef vector<int> vi;

int n,m,q,u,v,c,a;
vi adj[MN], mora[MN][LG];
int dp[MN][LG], visit[MN], h[MN];

vi merge(vi &a, vi &b) {
	vi ans;
	int ia = 0,  ib = 0, sa = a.size(), sb = b.size();
	while(ia != sa || ib != sb) {
	    if(ans.size() == 10) break;
		if(ia == sa) {
			ans.push_back(b[ib]);
			ib++;
		}
		else if(ib == sb) {
			ans.push_back(a[ia]);
			ia++;
		}
		else {
			if(a[ia] > b[ib]) {
				ans.push_back(b[ib]);
				ib++;
			}
			else if(a[ia] < b[ib]){
				ans.push_back(a[ia]);
				ia++;
			}
			else {
                ans.push_back(a[ia]);
                ia++, ib++;
			}
		}
	}
	return ans;
}

void dfs(int node) {
	visit[node] = 1;
	for(int i=0;i<adj[node].size();i++) {
		int v = adj[node][i];
		if(!visit[v]) {
			h[v] = h[node] + 1;
			dp[v][0] = node;
			dfs(v);
		}
	}
}

void build(int node) {
    dp[node][0] = node;

    for(int j=1; (1<<j)<=n;j++)
        for(int i=1;i<=n;i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
            mora[i][j] = merge(mora[i][j-1],mora[dp[i][j-1]][j-1]);
        }
}

vi query(int a, int b) {
    vi ansa, ansb;
    if(h[a] < h[b]) swap(a,b);

    int lg;
    for(lg=1;(1<<lg)<=n;lg++); lg--;

    for(int i=lg; i>=0; i--)
        if(h[a] - h[b] >= (1<<i)) {
            ansa = merge(ansa,mora[a][i]);
            a = dp[a][i];
        }

    if(a == b) return merge(ansa,mora[a][0]);

    for(int i=lg; i>=0; i--)
        if(dp[a][i] != dp[b][i]) {
            ansa = merge(ansa, mora[a][i]);
            ansb = merge(ansb, mora[b][i]);
            a = dp[a][i];
            b = dp[b][i];
        }

    ansa = merge(ansa,mora[a][0]);
    ansb = merge(ansb,mora[b][1]);
    return merge(ansa,ansb);
}

int main() {
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<n;i++) {
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

    for(int i=1;i<=m;i++) {
        scanf("%d",&c);
        mora[c][0].push_back(i);
    }

    for(int i=1;i<=n;i++) {
        sort(mora[i][0].begin(),mora[i][0].end());
    }

    dfs(1);
    build(1);

    for(int i=0;i<q;i++) {
        scanf("%d %d %d",&v,&u,&a);
        vi ans = query(v,u);

        int k = min(a,(int)ans.size());

        printf ("%d",k);
        for(int s=0; s<k ;s++) {
            printf(" %d",ans[s]);
        } puts("");
    }

	return 0;
}