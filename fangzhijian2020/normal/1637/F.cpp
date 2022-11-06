#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
const int Mxdt=100000;const long long INF=5e16;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,H[200005],x,y,h[200005],cnt,root,rd[200005];
struct edge{int to,next;}e[400005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
long long f[200005][2],Max[200005];
void dfs(int x,int prt){
	int i,y;Max[x]=H[x];f[x][0]=f[x][1]=INF;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		dfs(y,x);Max[x]=max(Max[x],Max[y]);
	}
	if(Max[x]>H[x]){
		long long Min=Max[x],se=INF,tt=H[x],sum=0,tp=0,cnts=0;
		for(i=h[x];i;i=e[i].next){
			y=e[i].to;if(y==prt)continue;
			sum+=min(f[y][0],f[y][1]);
			if(Max[y]==Max[x]){
				++cnts;se=min(se,f[y][1]-f[y][0]);
			}
			else{
				Min=min(Min,Max[x]-Max[y]);
			}
			if(Max[y]>=H[x])++tp;
			else tt=min(tt,H[x]-Max[y]);
		}	
		if(tp>1)Min=min(Min,se);
		else Min=min(Min,tt+se);
		f[x][0]=sum;
		if(cnts>1)f[x][1]=sum;
		else f[x][1]=min(f[x][1],f[x][0]+Min);
	}
	else{
		long long Min=Max[x],se=INF,sum=0;
		for(i=h[x];i;i=e[i].next){
			y=e[i].to;if(y==prt)continue;
			sum+=min(f[y][0],f[y][1]);
			if(H[x]-Max[y]<Min){
				se=min(se,Min);
				Min=min(Min,H[x]-Max[y]);
			}
			else{
				se=min(se,H[x]-Max[y]);
			}
		}	
		f[x][0]=sum+Min;
		f[x][1]=min(f[x][1],f[x][0]+se);
	}
}
int main(){
	n=read();int mx=0;
	for(int i=1;i<=n;++i)H[i]=read();
	for(int i=1;i<n;++i){
		x=read();y=read();
		add(x,y);add(y,x);
		mx=max(mx,H[i]);
	}
	if(n==2){
		cout<<2ll*max(H[1],H[2])<<"\n";return 0;
	}
	for(int i=1;i<=n;++i){
		if(H[i]==mx){root=i;break;}
	}
	dfs(root,0);cout<<f[root][1]<<'\n';
	return 0;
}