#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll Inf=1e18;
struct pr{
	ll a,b;int x;
	friend bool operator <(const pr&x,const pr&y){
		if(x.a-x.b==y.a-y.b)return x.x<y.x;
		return x.b-x.a>y.b-y.a;
	}
};
set<pr>s1[N],s2[N];set<int>s;
vector<pair<int,ll>>p[N];
pair<int,int>rd[N];bool ty[N];
ll ans[N],w[N],a0[N],b0[N],a[N];
int tot,f[N],dfn[N],id[N],d[N];
void dfs(int x){
	for(auto i:p[x])if(f[x]!=i.fr){
		++d[x];f[i.fr]=x;w[i.fr]=i.sc;
		s1[x].insert({0,i.sc,i.fr});
		dfs(i.fr);
	}
	dfn[x]=++tot;id[tot]=x;
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n-1){int x,y;ll z;
		scanf("%d%d%lld",&x,&y,&z);
		p[x].pb({y,z});p[y].pb({x,z});
	}
	dfs(1);
	rep(i,1,n)rd[i]={d[i],i};
	sort(rd+1,rd+n+1);int t=n;
	dep(i,n-1,0){
		for(;t&&rd[t].fr==i;--t)s.insert(dfn[rd[t].sc]);
		for(auto j:s){int x=id[j];
			if(x!=1){
				if(ty[x]){
					s2[f[x]].erase({min(a0[x],b0[x]+w[x]),b0[x]+w[x],x});
					a[f[x]]-=b0[x]+w[x];
				}else{
					s1[f[x]].erase({min(a0[x],b0[x]+w[x]),b0[x]+w[x],x});
					a[f[x]]-=min(a0[x],b0[x]+w[x]);
					if(!s2[f[x]].empty()){
						pr y=*s2[f[x]].begin();
						a[f[x]]+=y.a-y.b;ty[y.x]=0;
						s2[f[x]].erase(s2[f[x]].begin());
						s1[f[x]].insert(y);
					}
				}		
			}
			b0[x]=a[x];
			if(i){
				pr y=*--s1[x].end();
				a[x]+=y.b-y.a;a0[x]=a[x];ty[y.x]=1;
				s1[x].erase(--s1[x].end());s2[x].insert(y);
			}else a[x]=a0[x]=Inf;
			if(x==1||!s.count(dfn[f[x]]))ans[i]+=min(a0[x],b0[x]+w[x]);
			if(x!=1){
				if(int(s1[f[x]].size())<i){
					s1[f[x]].insert({min(a0[x],b0[x]+w[x]),b0[x]+w[x],x});
					a[f[x]]+=min(a0[x],b0[x]+w[x]);ty[x]=0;
				}else{bool fl=1;
					if(i){
						pr y=*--s1[f[x]].end();
						if(y.b-y.a<b0[x]+w[x]-min(a0[x],b0[x]+w[x])){fl=0;
							s1[f[x]].erase(--s1[f[x]].end());
							s1[f[x]].insert({min(a0[x],b0[x]+w[x]),b0[x]+w[x],x});
							s2[f[x]].insert(y);ty[x]=0;ty[y.x]=1;
							a[f[x]]+=min(a0[x],b0[x]+w[x])-y.a+y.b;
						}
					}
					if(fl){
						s2[f[x]].insert({a0[x],b0[x]+w[x],x});
						a[f[x]]+=b0[x]+w[x];ty[x]=1;
					}
				}
			}
		}
	}
	rep(i,0,n-1)printf("%lld ",ans[i]);
}