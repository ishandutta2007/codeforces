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
#define N 1000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,u,x,a[N],b[N],r[N][N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m)scanf("%d",&b[i]);
	rep(x,0,29)rep(i,1,n)rep(j,1,m){
		if((a[i]>>x)&1){
			r[i][j]^=1<<x;a[i]^=1<<x;b[j]^=1<<x;
		}
		if((i==n)&&((b[j]>>x)&1)){
			r[i][j]^=1<<x;a[i]^=1<<x;b[j]^=1<<x;
		}
	}
	rep(x,0,29)rep(j,1,m)rep(i,1,n){
		if((b[j]>>x)&1){
			r[i][j]^=1<<x;a[i]^=1<<x;b[j]^=1<<x;
		}
		if((j==m)&&((a[j]>>x)&1)){
			r[i][j]^=1<<x;a[i]^=1<<x;b[j]^=1<<x;
		}
	}u=0;
	rep(i,1,n)if(a[i])u=1;
	rep(j,1,m)if(b[j])u=1;
	if(u)printf("NO\n");else{
		printf("YES\n");
		rep(i,1,n){
			rep(j,1,m)printf("%d ",r[i][j]);
			printf("\n");
		}
	}
}