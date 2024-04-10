#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 1000
#define K 15000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 998244353
#define eps 1e-8
using namespace std;
int n,k;ll a[N][N],b[N][N],ans;
int main(){
	scanf("%d%d",&n,&k);k--;
	rep(i,1,n){
		if(i>k)break;b[i][1]=2;
		rep(j,2,n+1)b[i][j]=(b[i][j-1]*2+mo-b[i][max(0,j-i-1)])%mo;
		a[i][1]=(b[i][n+1]+b[i-1][n]+mo*2-b[i][n]-b[i-1][n+1])%mo;
		rep(j,2,n+1)a[i][j]=(a[i][j-1]*2+mo-a[i][max(0,j-(k/i)-1)])%mo;
		ans=(ans+a[i][n+1]+mo-a[i][n])%mo;
	}
	printf("%I64d\n",ans);
}