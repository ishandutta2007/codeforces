#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e2+1,M=2e3+1,INF=0x3f3f3f3f,sgn[]={1,-1};
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
int n,m,p,val[N],a[M],b[M],c[M],d[N][N];
V input(){
	scanf("%d%d",&n,&m),val[0]=-1;
	FOR(i,1,m)scanf("%d%d%d",a+i,b+i,c+i);
}
V init(){
	FOR(i,1,n)FOR(j,1,n)if(i!=j)d[i][j]=INF;
	FOR(i,1,m)d[a[i]][b[i]]=1,d[b[i]][a[i]]=sgn[c[i]];
	FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)cmin(d[i][j],d[i][k]+d[k][j]);
}
I ask(int*t,int maxn=-INF,int minn=INF){
	FOR(i,1,n)cmax(maxn,t[i]),cmin(minn,t[i]);
	return maxn-minn;
}
I check(int u){
	FOR(i,1,m){
		if(abs(d[u][a[i]]-d[u][b[i]])!=1)return 0;
		if(c[i]&&d[u][a[i]]+1!=d[u][b[i]])return 0;
	}
	return d[u][u]==0;
}
V work(){
	FOR(i,1,n)if(check(i)&&(val[i]=ask(d[i]))>val[p])p=i;
	if(!p)return void(cout<<"NO");
	cout<<"YES\n"<<val[p]<<'\n';
	FOR(i,1,n)cout<<d[p][i]+n<<' ';
}
int main(){
	input();
	init();
	work();
	return 0;
}