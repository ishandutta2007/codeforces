#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


#define NN 51
int cap[NN][NN], deg[NN], adj[NN][NN];
int q[NN], prv[NN];

int dinic( int n, int s, int t )
{
    int flow = 0;

    memset( deg, 0, sizeof( deg ) );
    for( int u = 0; u < n; u++ )
        for( int v = 0; v < n; v++ ) if( cap[u][v] || cap[v][u] )
            adj[u][deg[u]++] = v;

    while( true )
    {
        memset( prv, -1, sizeof( prv ) );
        int qf = 0, qb = 0;
        prv[q[qb++] = s] = -2;
        while( qb > qf && prv[t] == -1 )
            for( int u = q[qf++], i = 0, v; i < deg[u]; i++ )
                if( prv[v = adj[u][i]] == -1 && cap[u][v] )
                    prv[q[qb++] = v] = u;

        if( prv[t] == -1 ) break;

        for( int z = 0; z < n; z++ ) if( cap[z][t] && prv[z] != -1 )
        {
            int bot = cap[z][t];
            for( int v = z, u = prv[v]; u >= 0; v = u, u = prv[v] )
                bot = min(bot, cap[u][v]);
            if( !bot ) continue;

            cap[z][t] -= bot;
            cap[t][z] += bot;
            for( int v = z, u = prv[v]; u >= 0; v = u, u = prv[v] )
            {
                cap[u][v] -= bot;
                cap[v][u] += bot;
            }
            flow += bot;
        }
    }

    return flow;
}

pair<int, pair<int, int> > edges[1100];
int n,m,x;

void solve() {
	scanf("%d %d %d", &n, &m, &x);
	REP(i,m) {
		scanf("%d %d %d", &edges[i].second.first, &edges[i].second.second, &edges[i].first);
		edges[i].second.first--;
		edges[i].second.second--;
	}

	double st = 1.0/x, ed = 1000000;
	REP(i, 200) {
		memset(cap,0,sizeof(cap));
		double md = (st+ed)/2;
		REP(j,m) {
			cap[edges[j].second.first][edges[j].second.second] += 
				(int)(floor(edges[j].first / md) + 0.5);
		}
		if (dinic(n,0,n-1) >= x) st = md;
		else ed = md; 
	} 

	printf("%.15f\n", x*(st+ed)/2);
}

int main() {
    solve();
}