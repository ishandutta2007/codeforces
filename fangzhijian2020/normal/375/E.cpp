#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;
const int Mxdt=100000,Maxn=1000,Maxm=500;
const double eps=1e-7,O=1e-9;
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
int N,M,id[Maxn+Maxm+5];double a[Maxn+5][Maxm+5];
void pivot(int x,int y){
	swap(id[x+M],id[y]);
	double tmp=-a[x][y];a[x][y]=-1;
	for(int i=0;i<=M;++i)a[x][i]/=tmp;
	for(int i=0;i<=N;++i){
		if(i==x||fabs(a[i][y])<O)continue;
		double tmp=a[i][y];a[i][y]=0;
		for(int j=0;j<=M;++j){
			a[i][j]+=tmp*a[x][j];
		}
	}
}
bool find(int&x,int &y){
	double Max=0;x=y=0;
	for(int j=1;j<=M;++j){
		if(a[0][j]>eps){
			if(!y||Max<a[0][j]){
				y=j;Max=a[0][j];
			}
		}
	}
	if(!y)return 0;
	int tp=0;double Min=0;
	for(int i=1;i<=N;++i){
		if(a[i][y]<-eps){
			double tmp=-a[i][0]/a[i][y];
			if(!tp||tmp<Min){tp=i;Min=tmp;}
		}
	}
	if(!tp){puts("-1");exit(0);}
	x=tp;return 1;
}
void prework(){
	while(1){
		int x=0,y=0;
		for(int i=1;i<=N;++i){
			if(a[i][0]<-eps&&(!x||rand()&1))x=i;
		}
		if(!x)return;
		for(int j=1;j<=M;++j){
			if(a[x][j]>eps&&(!y||rand()&1))y=j;
		}
		if(!y){puts("-1");exit(0);}pivot(x,y);
	}
}
double simplex(){
	int x,y;prework();
	while(find(x,y))pivot(x,y);
	return a[0][0];
}
int n,X,x,y,z,opt[505],h[505],cnt;
struct edge{int to,next,v;}e[1005];
void add(int x,int y,int z){
	e[++cnt]=(edge){y,h[x],z};h[x]=cnt;
}
void dfs(int x,int prt,int dep){
	int i,y;if(dep>X)return;
	if(opt[x]==0)a[N][x]=1;
	else{a[N][x]=-1;++a[N][0];}
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		dfs(y,x,dep+e[i].v);
	}
}
int main(){
	srand(time(0));
	n=read();X=read();M=n;
	for(int i=1;i<=n;++i)opt[i]=read();
	for(int i=1;i<n;++i){
		x=read();y=read();z=read();
		add(x,y,z);add(y,x,z);
	}
	for(int i=1;i<=n;++i)a[0][i]=-1;
	for(int i=1;i<=n;++i){++N;a[N][i]=-1;a[N][0]=1;}
	++N;for(int i=1;i<=n;++i)if(opt[i]==1)a[N][i]=1;else a[N][i]=-1;
	++N;for(int i=1;i<=n;++i)if(opt[i]==0)a[N][i]=1;else a[N][i]=-1;
	for(int i=1;i<=n;++i){++N;a[N][0]=-1;dfs(i,0,0);}
	int ans=(int)-simplex()/2;cout<<ans<<"\n";
	return 0;
}