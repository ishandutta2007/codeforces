#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 2000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,x,tot,p[N*N],X[N*N],Y[N*N];
int l[N][N],r[N][N],w[N][N],d[N][N];
int L[N][N],R[N][N],W[N][N],D[N][N];
char c[N][N];bool v[N][N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",c[i]+1);
	rep(i,1,n)rep(j,1,m)if(c[i][j]=='*'){
		if(c[i][j-1]=='*')l[i][j]=l[i][j-1];else l[i][j]=j;
		if(c[i-1][j]=='*')w[i][j]=w[i-1][j];else w[i][j]=i;
	}
	dep(i,n,1)dep(j,m,1)if(c[i][j]=='*'){
		if(c[i][j+1]=='*')r[i][j]=r[i][j+1];else r[i][j]=j;
		if(c[i+1][j]=='*')d[i][j]=d[i+1][j];else d[i][j]=i;
	}
	rep(i,1,n)rep(j,1,m)if(c[i][j]=='*'){
		x=min(min(j-l[i][j],r[i][j]-j),min(i-w[i][j],d[i][j]-i));
		if(x){
			L[i][j-x]=max(L[i][j-x],x);R[i][j+x]=max(R[i][j+x],x);
			W[i-x][j]=max(W[i-x][j],x);D[i+x][j]=max(D[i+x][j],x);
		}
	}
	rep(i,1,n)rep(j,1,m)if(c[i][j]=='*'){
		x=min(min(j-l[i][j],r[i][j]-j),min(i-w[i][j],d[i][j]-i));
		if(x&&((L[i][j-x]==x)||(R[i][j+x]==x)||(W[i-x][j]==x)||(D[i+x][j]==x))){
			rep(k,-x,x)v[i+k][j]=1,v[i][j+k]=1;
			X[++tot]=i;Y[tot]=j;p[tot]=x;
		}
	}
	rep(i,1,n)rep(j,1,m)if((c[i][j]=='*')&&(!v[i][j])){
		printf("-1");return 0;
	}
	printf("%d\n",tot);
	rep(i,1,tot)printf("%d %d %d\n",X[i],Y[i],p[i]);	
}