#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 998244353
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
int n,ls[2];ll m,s[2],d[2];bool t;
int main(){
	scanf("%d%lld",&n,&m);
	rep(i,1,n){t^=1;
		int x;scanf("%d",&x);
		if(i<3){
			if(~x)ls[t]=x,s[t]=1;else d[t]=1;
			continue;
		}
		if(!ls[t]){
			if(~x)ls[t]=x,s[t]=d[t]*(m-1)%mo,d[t]=0;
			else d[t]=d[t]*(m-1)%mo;
			continue;
		}
		if(~x){
			if(x==ls[t])s[t]=d[t]*(m-1)%mo;
			else s[t]=s[t]+d[t]*(m-2)%mo;
			d[t]=0;ls[t]=x;
		}else{ll tp=s[t];
			s[t]=d[t]*(m-1)%mo;
			d[t]=(tp+d[t]*(m-2))%mo;
		}
	}
	if(!ls[0])s[0]=d[0];
	if(!ls[1])s[1]=d[1];
	printf("%lld\n",(s[0]+d[0]*(m-1))%mo*((s[1]+d[1]*(m-1))%mo)%mo);
}