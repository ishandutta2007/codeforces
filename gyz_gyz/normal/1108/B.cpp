#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,x;multiset<int>s;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);s.insert(x);
	}
	x=*(--s.end());
	rep(i,1,x)if(!(x%i))s.erase(s.lower_bound(i));
	printf("%d %d\n",x,*(--s.end()));
}