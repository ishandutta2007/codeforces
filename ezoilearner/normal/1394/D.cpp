#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1000000000000ll;
int n;
#define Maxn 200010
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}
int T[Maxn],H[Maxn];
ll f[Maxn][2];

struct Data{
	ll a,b;
	Data(){a=b=0;}
	Data(ll _a,ll _b){a=_a;b=_b;}
    bool operator <(const Data &z)const{return b-a<z.b-z.a;}
}data[Maxn];

int cnt;
inline ll calc(int u){
	ll res=inf,sum=0;
	sort(data+1,data+cnt+1);
	for(int i=1;i<=cnt;++i)sum+=data[i].a;
	res=min(res,sum+1ll*cnt*T[u]);
	for(int i=1;i<=cnt;++i){
		sum+=data[i].b-data[i].a;
		res=min(res,sum+1ll*max(i,cnt-i)*T[u]);
	}
	return res;
}
void dfs(int u,int fa){
	for(int i=head[u];i;i=nxt[i])
	    if(v[i]^fa){
	    	dfs(v[i],u);
		}
    cnt=0;
	for(int i=head[u];i;i=nxt[i])
	    if(v[i]^fa){
	    	cnt++;
	    	if(H[u]<=H[v[i]])data[cnt].a=f[v[i]][1];
	    	else data[cnt].a=inf;
	    	if(H[u]>=H[v[i]])data[cnt].b=f[v[i]][0];
	    	else data[cnt].b=inf;
		}
	data[++cnt]=Data(0,inf);
	f[u][0]=calc(u);
	cnt=0;
	for(int i=head[u];i;i=nxt[i])
	    if(v[i]^fa){
	    	cnt++;
	    	if(H[u]<=H[v[i]])data[cnt].a=f[v[i]][1];
	    	else data[cnt].a=inf;
	    	if(H[u]>=H[v[i]])data[cnt].b=f[v[i]][0];
	    	else data[cnt].b=inf;
		}
	data[++cnt]=Data(inf,0);
	f[u][1]=calc(u);
	if(u==1){
		cnt=0;
	for(int i=head[u];i;i=nxt[i])
	    if(v[i]^fa){
	    	cnt++;
	    	if(H[u]<=H[v[i]])data[cnt].a=f[v[i]][1];
	    	else data[cnt].a=inf;
	    	if(H[u]>=H[v[i]])data[cnt].b=f[v[i]][0];
	    	else data[cnt].b=inf;
		}
		f[u][0]=calc(u);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&T[i]);
	for(int i=1;i<=n;++i)scanf("%d",&H[i]);
	int s,e;
	for(int i=1;i<n;++i){
		scanf("%d%d",&s,&e);
		add_edge(s,e);
	}
	dfs(1,0);
	printf("%lld\n",min(f[1][0],f[1][1]));
	return 0;
}