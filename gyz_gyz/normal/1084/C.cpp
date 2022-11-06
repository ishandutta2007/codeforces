#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 400000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
string s;ll a,b;
int main(){cin>>s;
	for(auto i:s){
		if(i=='a')b=(a+b+1)%mo;
		if(i=='b')a=(a+b)%mo,b=0;
	}
	printf("%lld\n",(a+b)%mo);
}