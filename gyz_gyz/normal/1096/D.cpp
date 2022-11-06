#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 2000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;ll h,a,r,d,p[N];char s[N];
int main(){
	scanf("%d",&n);scanf("%s",s+1);
	rep(i,1,n)scanf("%lld",&p[i]);
	rep(i,1,n){
		if(s[i]=='h')h+=p[i];
		if(s[i]=='a')a=min(a+p[i],h);
		if(s[i]=='r')r=min(r+p[i],a);
		if(s[i]=='d')d=min(d+p[i],r);
	}
	printf("%lld\n",d);
}