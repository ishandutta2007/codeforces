#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int mo=998244353;
pii e[N];set<int>p[N];
vector<pii>res;int tot,nt[N];
int dfs(int x){
	if(p[x].empty())return tot;
	int t=*p[x].begin();
	p[x].erase(p[x].begin());p[t].erase(x);
	int pt=tot;e[++tot]={x,t};int ed=dfs(t);
	if(p[x].empty())return nt[pt]=pt+1,ed;
	t=*p[x].begin();
	p[x].erase(p[x].begin());p[t].erase(x);
	nt[pt]=++tot;e[tot]={x,t};
	nt[dfs(t)]=pt+1;return ed;
}
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x].insert(y);p[y].insert(x);
	}
	rep(i,1,n)if(p[i].size()&1){
		p[0].insert(i);p[i].insert(0);
	}
	rep(i,1,n)if(!p[i].empty()){
		dfs(i);bool nw=1;
		for(int x=nt[0];x;x=nt[x]){
			if(nw){
				if(e[x].fr&&e[x].sc){
					res.pb(e[x]);nw=0;
				}
			}else{nw=1;
				if(!e[nt[nt[x]?x:0]].sc)res.pb(e[x]);
			}
		}
		rep(j,1,tot)e[j]={0,0},nt[j]=0;tot=0;
	}
	cout<<res.size()<<endl;
	for(auto &i:res)printf("%d %d\n",i.fr,i.sc);
}