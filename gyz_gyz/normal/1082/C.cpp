#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 200000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,nw,tot,ans,w[N],er[N];multiset<int>p[N],s;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		p[i].insert(-inf);s.insert(i);
	}
	rep(i,1,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].insert(y);
	}
	for(;;){tot=0;
		if(s.empty())break;
		for(auto i:s){
			auto x=p[i].end();--x;
			if(*x+w[i]<=0){
				er[++tot]=i;nw-=w[i];
			}else{
				w[i]+=*x;nw+=*x;p[i].erase(x);
			}
		}
		rep(i,1,tot)s.erase(er[i]);
		ans=max(ans,nw);
	}
	printf("%d\n",ans);
}