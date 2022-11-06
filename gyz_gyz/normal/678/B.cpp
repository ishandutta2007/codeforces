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
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int mo=1e9+7;
const int inf=1e9;
const ll Inf=1e18;
bool rn(int x){
	if(!(x%400))return 1;
	if(!(x%100))return 0;
	if(!(x%4))return 1;
	return 0;
}
int main(){int n,s=0;
	scanf("%d",&n);
	rep(i,n+1,inf){
		s=(s+(rn(i-1)?366:365))%7;
		if(!s&&rn(i)==rn(n)){
			printf("%d\n",i);return 0;
		}
	}
}