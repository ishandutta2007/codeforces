#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000,mod=1e9+7,inv2=5e8+4;
char gc(){
	return getchar();
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;n>>=1;
	}
	return ans;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,x,y,h[205],cnt,ans;
struct edge{int to,next;}e[405];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int f[205][10],d[205];
void dfs(int x,int prt){
	int i,y;f[x][0]=prt;d[x]=d[prt]+1;
	for(int i=1;i<10;++i)f[x][i]=f[f[x][i-1]][i-1];
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		dfs(y,x);
	}
}
int LCA(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=9;~i;--i){
		if(d[x]-(1<<i)>=d[y]){
			x=f[x][i];
		}
	}
	if(x==y)return x;
	for(int i=9;~i;--i){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];y=f[y][i];
		}
	}
	return f[x][0];
}
int F[505][505],c[505][505];
int C(int n,int m){
	if(n<m)return 0;
	return c[n][m];
}
int solve(int a,int b){
	if(a==0)return 0;
	if(b==0)return 1;
	if(F[a][b]!=-1)return F[a][b];
	return (F[a][b]=1ll*(solve(a-1,b)+solve(a,b-1))*inv2%mod);
}
int main(){
	n=read();
	memset(F,-1,sizeof(F));
	c[0][0]=1;
	for(int i=1;i<=n;++i){
		c[i][0]=1;
		for(int j=1;j<=i;++j){
			c[i][j]=Mod(c[i-1][j-1]+c[i-1][j]);
		}
	}
	for(int i=1;i<n;++i){
		x=read();y=read();add(x,y);add(y,x);
	}
	for(int i=1;i<=n;++i){
		d[i]=1;dfs(i,0);
		for(int j=1;j<=n;++j){
			for(int k=j+1;k<=n;++k){
				int lca=LCA(j,k);if(lca==j)continue;
				if(lca==k)Add(ans,1);
				else{
					Add(ans,solve(d[j]-d[lca],d[k]-d[lca]));
				}
			}
		}
	}
	cout<<1ll*ans*ksm(n,mod-2)%mod<<"\n";
	return 0;
}