#include<bits/stdc++.h>
#define maxn 1102030
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int to[maxn],nxt[maxn],h[maxn],low[maxn],dfn[maxn],n,m,p,colorcnt,instack[maxn],color[maxn];
ll ans,b[maxn],c[maxn],d[maxn],e[maxn],f[maxn],st,sum[maxn],dp[maxn];
bool visit[maxn],use[maxn];
vector <pi> g[maxn];

vector <int> s;

void add_edge(int x,int y)
{
	p++;
	to[p]=y;
	nxt[p]=h[x];
	h[x]=p;
}

void dfs(int x)
{
	p++;
	instack[x]=1;
	dfn[x]=p;
	low[x]=dfn[x];
	s.push_back(x);
	for (int i=h[x];i;i=nxt[i])
	{
		if (!instack[to[i]]){
			dfs(to[i]);
			low[x]=min(low[x],low[to[i]]);
		}
		else if (instack[to[i]]==1) low[x]=min(low[x],dfn[to[i]]);
	}
	if (dfn[x]==low[x]){
		while (s.back()!=x)
		{
			color[s.back()]=colorcnt;
			instack[s.back()]=2;
			s.pop_back();
		}
		color[s.back()]=colorcnt++;
		instack[s.back()]=2;
		s.pop_back();
	}
}

ll calc(ll x){
    ll lf,rt,mid;
    lf=0; rt=20000;
    while (rt-lf>1){
        mid=(lf+rt)/2;
        if (mid*(mid-1)/2<=x) lf=mid; else rt=mid;
    }
    return lf;
}

void dfs2(int u){
    use[u]=true;
    for (int j=0;j<g[u].size();j++){
        int v=g[u][j].F;
        if (!use[v]) dfs2(v);
        d[v]++;
    }
}

int main()
{
	scanf("%d%d",&n,&m);p=0;
	memset(h,0,sizeof(h));
	memset(nxt,0,sizeof(nxt));
	for (int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v);
		b[i]=u; c[i]=v; e[i]=w;
		ll r=calc(w); f[i]=r*w-r*(r+1)*(r-1)/6;
	}
	memset(instack,0,sizeof(instack));
	colorcnt=1;p=0;
	for (int i=1;i<=n;i++)
	    if (!instack[i]) dfs(i);
    scanf("%d",&st); st=color[st];
    for (int i=0;i<m;i++) {
        int u=color[b[i]],v=color[c[i]];
        if (u==v) sum[u]+=f[i]; else g[u].push_back({v,e[i]});
    }
    dfs2(st);
    queue <int> q;
    q.push(st);
    while (!q.empty()){
        int u=q.front(); q.pop(); dp[u]+=sum[u]; ans=max(ans,dp[u]);
        for (int i=0;i<g[u].size();i++){
            int v=g[u][i].F;
            d[v]--; dp[v]=max(dp[v],dp[u]+g[u][i].S);
            if (!d[v]) q.push(v);
        }
    }
    cout << ans << endl;
	return 0;
}