#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 200010
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
string s;
void sol(){
	printf("? 0 1\n");fflush(stdout);cin>>s;
	if(s=="x"){
		printf("! 1\n");fflush(stdout);return;
	}ll x=1;
	while(s=="y"){
		printf("? %lld %lld\n",x,x*2);
		fflush(stdout);cin>>s;x*=2;
	}
	ll l=x/2+1,r=min(x,1000000000ll),m=(l+r)>>1;
	for(;l<r;m=(l+r)>>1){
		printf("? %lld %lld\n",(m-1)/2+1,m);
		fflush(stdout);cin>>s;
		if(s=="x")r=m;else l=m+1;
	}
	printf("! %lld\n",m);fflush(stdout);
}
int main(){
	for(cin>>s;s!="end";cin>>s)sol();
}