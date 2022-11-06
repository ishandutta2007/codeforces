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
typedef pair<pii,int>ppi;
typedef pair<pii,pii>ppp;
const int N=2e5+10;
const int mo=998244353;
int f[N],rf[N];ppp rs[N];vector<pii>p[N];vector<ppi>res;
void dfs(int x){
	for(auto &i:p[x])if(i.fr!=f[x]){
		f[i.fr]=x;rf[i.fr]=i.sc;dfs(i.fr);
	}
	if(!f[x]){
		ppp s=rs[p[x][0].fr];
		res.pb({{x,s.fr.fr},s.fr.sc});
		if(s.sc.sc)res.pb({{x,s.sc.fr},s.sc.sc});
	}else if(p[x].size()==1)rs[x]={{x,rf[x]},{0,0}};else{
		ppp s1,s2; 
		for(auto &i:p[x])if(i.fr!=f[x]){
			if(!s1.fr.fr)s1=rs[i.fr];
			else if(!s2.fr.fr)s2=rs[i.fr];else{
				if(rs[i.fr].fr.sc){
					res.pb({{s2.fr.fr,rs[i.fr].fr.fr},rs[i.fr].fr.sc});
					s2.fr.sc-=rs[i.fr].fr.sc;
				}
				if(rs[i.fr].sc.sc){
					res.pb({{s2.fr.fr,rs[i.fr].sc.fr},rs[i.fr].sc.sc});
					s2.fr.sc-=rs[i.fr].sc.sc;
				}
			}
		}
		if(s1.sc.sc){
			res.pb({{s2.fr.fr,s1.sc.fr},s1.sc.sc});
			s2.fr.sc-=s1.sc.sc;
		}
		if(s2.sc.sc){
			res.pb({{s1.fr.fr,s2.sc.fr},s2.sc.sc});
			s1.fr.sc-=s2.sc.sc;
		}
		int rp=(s1.fr.sc+s2.fr.sc-rf[x])/2;
		if(rp)res.pb({{s1.fr.fr,s2.fr.fr},rp});
		rs[x]={{s1.fr.fr,s1.fr.sc-rp},{s2.fr.fr,s2.fr.sc-rp}};
	}
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n-1){int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		p[x].pb({y,z});p[y].pb({x,z});
	}int rt=1;
	rep(i,1,n)if(p[i].size()==2)return printf("NO\n"),0;
	while(p[rt].size()!=1)++rt;dfs(rt);
	printf("YES\n%d\n",(int)res.size());
	for(auto &i:res)printf("%d %d %d\n",i.fr.fr,i.fr.sc,i.sc);
}