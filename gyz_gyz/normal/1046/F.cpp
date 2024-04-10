#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define mo 2147483647
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n;ll f,x,ans,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%I64d",&a[i]);
	scanf("%I64d%I64d",&x,&f);
	rep(i,1,n)if(a[i]>x)ans+=(a[i]+f-1)/(x+f)*f;
	printf("%I64d",ans);
}