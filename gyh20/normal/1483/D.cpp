#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int n,m,head[602],cnt,Q,G[602][602],p[602],now,pos1,pos,T[602][602],MX[602][602];
long long D[602][602];
struct edge{int to,next,w;}e[500002];
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}
struct node{
    int pos;
	long long dis;
    bool operator <(const node x)const{
        return dis>x.dis;
    }
}h[602];
priority_queue <node> q;
struct Node{int x,y;};
vector<Node>v[602];
int QRY[602][602];
inline void dis(re int s){for(re int i=1;i<=n;++i)h[i].dis=1e18,h[i].pos=i;
    h[s].dis=0;
    q.push(h[s]);
    while(!q.empty()){
        while((h[q.top().pos].dis<q.top().dis)){q.pop();if(q.empty())break;
        }
        if(q.empty())break;
        node tmp=q.top();
        q.pop();
        for(re int i=head[tmp.pos];i;i=e[i].next){
            if((tmp.dis+e[i].w)<h[e[i].to].dis){
                h[e[i].to].dis=tmp.dis+e[i].w;
                q.push(h[e[i].to]);
            }
		}
    }
}
signed main(){
	n=read(),m=read();
	memset(G,127,sizeof(G));
	memset(D,127,sizeof(D));
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j)
			if(i^j)D[i][j]=1e18;
			else D[i][j]=0;
	for(re int i=1,x,y,z;i<=m;++i){
		x=read(),y=read(),z=read();
		G[x][y]=G[y][x]=z;
		D[x][y]=D[y][x]=z;
		add(x,y,z),add(y,x,z);
	}
	for(re int k=1;k<=n;++k)
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=n;++j)
				D[i][j]=min(D[i][j],D[k][i]+D[j][k]);
	Q=read();
	memset(MX,-127,sizeof(MX));
	memset(QRY,-127,sizeof(QRY));
	for(re int i=1,x,y,z;i<=Q;++i){
		x=read(),y=read(),z=read();
		for(re int j=1;j<=n;++j){
			if(D[y][j]<=z)QRY[x][j]=max(1ll*QRY[x][j],z-D[y][j]);
		}
	}
	for(re int x=1;x<=n;++x){
		for(re int j=1;j<=n;++j){
			if(QRY[x][j])
			for(re int k=1;k<=n;++k)
				if(G[k][j]<=1e9&&D[x][k]+G[k][j]<=QRY[x][j])T[k][j]=T[j][k]=1;
		}
	}
	re int ans=0;
	for(re int i=1;i<=n;++i)
		for(re int j=i+1;j<=n;++j){
			ans+=T[i][j];
		}
	printf("%d",ans);
}