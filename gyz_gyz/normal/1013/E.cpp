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
#define N 5010
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,x,ans,h[N],a[N][N],b[N][N];
int main(){
	scanf("%d",&n);m=(n+1)/2;
	rep(i,1,n)scanf("%d",&h[i]);
	rep(i,0,n)rep(j,0,m)a[i][j]=b[i][j]=inf;
	rep(i,0,n)b[i][0]=0;
	rep(i,2,n+1)rep(j,1,m){
		x=max(h[i]-h[i-1]+1,0);
		a[i][j]=x+max(min(h[i-3]-1,h[i-2])-h[i-1]+1,0)+a[i-2][j-1];
		a[i][j]=min(a[i][j],x+max(h[i-2]-h[i-1]+1,0)+b[i-2][j-1]);
		b[i][j]=min(a[i-1][j],b[i-1][j]);
	}
	rep(i,1,m){ans=inf;
		rep(j,1,n+1)ans=min(ans,min(a[j][i],b[j][i]));
		printf("%d ",ans);
	}
}