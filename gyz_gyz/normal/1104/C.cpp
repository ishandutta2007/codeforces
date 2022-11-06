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
int main(){string s;
	cin>>s;int x=0,y=0;
	for(auto i:s)if(i=='0'){
		x=x%4+1;printf("1 %d\n",x);
	}else{
		y=y%2+1;printf("3 %d\n",y*2-1);
	}
}