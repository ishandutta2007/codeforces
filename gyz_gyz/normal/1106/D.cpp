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
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m;bool v[N];
set<int>s;vector<int>p[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	s.insert(1);v[1]=1;
	while(!s.empty()){
		int x=*(s.begin());
		s.erase(s.begin());printf("%d ",x);
		for(auto i:p[x])if(!v[i]){
			s.insert(i);v[i]=1;
		}
	}
}