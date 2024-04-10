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
#define N 300000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n;ll a[N],ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n*2)scanf("%I64d",&a[i]);
	sort(a+1,a+n*2+1);
	ans=(a[n]-a[1])*(a[n*2]-a[n+1]);
	rep(i,2,n)if((a[i+n-1]-a[i])*(a[n*2]-a[1])<ans)
		ans=(a[i+n-1]-a[i])*(a[n*2]-a[1]);
	printf("%I64d\n",ans);
}