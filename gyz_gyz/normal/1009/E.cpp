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
#define N 1000010
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
int n;ll a[N],t,ans;
int main(){
	scanf("%d",&n);t=1;
	rep(i,1,n)scanf("%I64d",&a[i]);
	dep(i,n,1)ans=(ans+(a[i]-a[i-1])*t%mo*(n-i+1))%mo,t=t*2%mo;
	printf("%I64d\n",ans);
}