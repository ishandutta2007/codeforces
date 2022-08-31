#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0,f=0;re char v=gc();
	while(v<'0')f|=(v=='-'),v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return f?-t:t;
}
struct node{
    int pos;
    ll dis;
    bool operator <(const node x)const{
        return dis>x.dis;
    }
}h[2002];
priority_queue<node>q;
int n,cnt,head[2002],m,p[2002],S,T,m1,m2,sz[2002][2002],sz1[2002][2002],a[2002][2002];
struct edge{int to,next,w;}e[200002];
ll f[2][2002][2002],d1[2002],d2[2002],d[2002],s[2002][2002],s1[2002][2002],b[2002][2002],sum;
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}
inline void dis(re int s){
	for(re int i=1;i<=n;++i)h[i].dis=1e18,h[i].pos=i;
    h[s].dis=0;
    q.push(h[s]);
    while(!q.empty()){
        while((h[q.top().pos].dis<q.top().dis)){q.pop();if(q.empty())break;}
        if(q.empty())break;
        node tmp=q.top();
        q.pop();
        for(re int i=head[tmp.pos];i;i=e[i].next)
            if((tmp.dis+e[i].w)<h[e[i].to].dis){
                h[e[i].to].dis=tmp.dis+e[i].w;
                q.push(h[e[i].to]);
            }
    }
}
int main(){
	n=read(),m=read(),S=read(),T=read();
	for(re int i=1;i<=n;++i)p[i]=read(),sum+=p[i];
	if(sum>0)return puts("Break a heart"),0;
	for(re int i=1,x,y,z;i<=m;++i)x=read(),y=read(),z=read(),add(x,y,z),add(y,x,z);
	dis(S);for(re int i=1;i<=n;++i)d1[i]=d[i]=h[i].dis;
	sort(d+1,d+n+1),m1=unique(d+1,d+n+1)-d-1;for(re int i=1;i<=n;++i)d1[i]=lower_bound(d+1,d+m1+1,d1[i])-d;
	dis(T);for(re int i=1;i<=n;++i)d2[i]=d[i]=h[i].dis;
	sort(d+1,d+n+1),m2=unique(d+1,d+n+1)-d-1;for(re int i=1;i<=n;++i)d2[i]=lower_bound(d+1,d+m2+1,d2[i])-d;
	for(re int i=1;i<=n;++i)++a[d1[i]][d2[i]],b[d1[i]][d2[i]]+=p[i];
	for(re int i=1;i<=m1;++i)for(re int j=1;j<=m2;++j)sz[i][j]=sz[i][j-1]+a[i][j],s[i][j]=s[i][j-1]+b[i][j];
	for(re int i=1;i<=m2;++i)for(re int j=1;j<=m1;++j)sz1[i][j]=sz1[i][j-1]+a[j][i],s1[i][j]=s1[i][j-1]+b[j][i];
	for(re int i=m1;i;--i)
		for(re int j=m2;j;--j){
			if(sz[i][m2]-sz[i][j-1])f[0][i][j]=max(f[0][i+1][j],f[1][i+1][j])+s[i][m2]-s[i][j-1];
			else f[0][i][j]=f[0][i+1][j];
			if(sz1[j][m1]-sz1[j][i-1])f[1][i][j]=min(f[1][i][j+1],f[0][i][j+1])-s1[j][m1]+s1[j][i-1];
			else f[1][i][j]=f[1][i][j+1];
		}
	if(f[0][1][1]>0)puts("Break a heart");
	else if(f[0][1][1]==0)puts("Flowers");
	else puts("Cry");
}