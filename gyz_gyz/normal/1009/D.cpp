#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
int n,m,tot,x[N],y[N];
int gcd(int x,int y){
	if(!x)return y;return gcd(y%x,x);
}
int main(){
	scanf("%d%d",&n,&m);
	if(m>=n-1)rep(i,1,n)rep(j,i+1,n)if(gcd(i,j)==1){
		x[++tot]=i;y[tot]=j;
		if(tot==m){
			printf("Possible\n");
			rep(k,1,tot)printf("%d %d\n",x[k],y[k]);
			return 0;
		}
	}
	printf("Impossible");
}