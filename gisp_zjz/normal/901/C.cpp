#include<bits/stdc++.h>
#define maxn 1000020

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

ll to[maxn],nxt[maxn],h[maxn],low[maxn],dfn[maxn],n,m,p,colorcnt,instack[maxn],color[maxn],cnt;
bool visit[maxn],used[maxn];
pi b[maxn];
ll a[maxn],s1[maxn],s2[maxn],l,r,mid,u,v;

vector <ll> s;

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
		if (used[i/2]) continue;
		used[i/2]=true;
		if (!instack[to[i]]){
			dfs(to[i]);
			low[x]=min(low[x],low[to[i]]);
		}
		else if (instack[to[i]]==1) low[x]=min(low[x],dfn[to[i]]);
	}
	if (dfn[x]==low[x]){
        l=n,r=1;
		while (s.back()!=x)
		{
		    l=min(l,s.back());
            r=max(r,s.back());
			instack[s.back()]=2;
			s.pop_back();
		}
        l=min(l,s.back());
        r=max(r,s.back());
		instack[s.back()]=2;
		s.pop_back();
		if (l!=r) b[cnt++]={l,r};
	}
}


int main()
{
	scanf("%d%d",&n,&m);p=1;
	memset(used,false,sizeof(used));
	memset(h,0,sizeof(h)); cnt=0;
	memset(nxt,0,sizeof(nxt));
	for (int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	memset(instack,0,sizeof(instack));
	colorcnt=1;p=0;
	for (int i=1;i<=n;i++)
	    if (!instack[i]) dfs(i);
    sort(b,b+cnt); b[cnt].first=n+1; a[n+1]=n;
    for (int i=cnt-1;i>=0;i--)
    {
        for (int j=b[i+1].first;j>b[i].first;j--) a[j-1]=a[j];
        a[b[i].first]=min(a[b[i].first],b[i].second-1);
    }
    for (int j=b[0].first;j>0;j--) a[j-1]=a[j];
    s1[0]=0;s2[0]=0;
    for (int i=1;i<=n;i++) s1[i]=s1[i-1]+a[i],s2[i]=s2[i-1]+(i-1);
    int query; scanf("%d",&query);
    while (query--)
    {
        scanf("%d%d",&u,&v);
        l=u-1;r=v+1;
        while (r-l>1){
            mid=(l+r)/2;
            if (a[mid]>v) r=mid; else l=mid;
        }
        printf("%I64d\n",s1[l]-s1[u-1]+v*(v-l)+s2[u-1]-s2[v]);
    }
    printf("\n");
	return 0;
}