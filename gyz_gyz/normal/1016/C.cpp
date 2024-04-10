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
#define N 500000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n;ll ans,a[N],b[N],f1[N],f2[N],q1[N],q2[N],c2[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	rep(i,1,n)scanf("%lld",&b[i]);
	dep(i,n,1){
		q1[i]=q1[i+1]+a[i]*((n-i)*2+1)+c2[i+1];
		q2[i]=q2[i+1]+b[i]*((n-i)*2+1)+c2[i+1];
		c2[i]=c2[i+1]+a[i]+b[i];
	}
	ans=q2[1];
	rep(i,1,n){
		f2[i]=f1[i-1]+a[i]*(i*2-2)+b[i]*(i*2-1);
		if(i&1)ans=max(ans,f2[i]+q1[i+1]+c2[i+1]*i*2);
		f1[i]=f2[i-1]+b[i]*(i*2-2)+a[i]*(i*2-1);
		if(!(i&1))ans=max(ans,f1[i]+q2[i+1]+c2[i+1]*i*2);
	}
	printf("%lld\n",ans);
}