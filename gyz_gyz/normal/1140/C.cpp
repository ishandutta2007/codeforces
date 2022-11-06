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
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,t[N],b[N];vector<int>r[N];multiset<int>s;ll ans,tot;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d%d",&t[i],&b[i]);
		r[b[i]].pb(t[i]);
	}
	dep(i,1000000,1){
		for(auto j:r[i]){
			s.insert(j);tot+=j;
			if(int(s.size())>m){
				tot-=*s.begin();
				s.erase(s.begin());
			}
		}
		if(tot){
			ans=max(ans,tot*i);
		}
	}
	printf("%lld\n",ans);
}