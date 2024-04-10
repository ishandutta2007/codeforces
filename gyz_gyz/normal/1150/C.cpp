#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int N=1e7;
const ll mo=1e9+7;
const ll inf=1e9;
const ll Inf=1e18;
int main(){int n,a=0,b=0;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x==1)++a;else ++b;
	}
	if(b){
		printf("2 ");--b;
	}
	if(a){
		printf("1 ");--a;
	}
	for(;b;--b)printf("2 ");
	for(;a;--a)printf("1 ");	
}