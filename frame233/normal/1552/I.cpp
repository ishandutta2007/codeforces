#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
#define FAIL puts("0"),exit(0)
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=105,NC=N<<1,mod=998244353;
std::vector<int> e[NC];
int type[NC],opt[NC],nc,n;
void dfs1(int x){if(x>n){opt[x]=0;for(auto v:e[x])dfs1(v),opt[x]|=opt[v];}}
void dfs2(int x,int lim){
	if(opt[x]<=2)return;
	std::vector<int> a[3];
	for(auto v:e[x])a[opt[v]-1].pb(v);
	if(SZ(a[2])+(!!lim)>2)FAIL;
	if(!lim&&SZ(a[1])+SZ(a[2])<=1)return dfs2(a[1].empty()?a[2][0]:a[1][0],0);
	if(type[x]){
		std::vector<int> E;
		int o=0;
		if(!a[1].empty()){
			if(SZ(a[1])==1)o=a[1][0];
			else o=++nc,type[o]=1,e[o]=a[1];
		}
		if(!a[2].empty()){
			dfs2(a[2][0],2);
			for(auto v:e[a[2][0]])E.pb(v);
		}
		if(o)E.pb(o);
		if(SZ(a[2])>1){
			dfs2(a[2][1],1);
			for(auto v:e[a[2][1]])E.pb(v);
		}
		if(a[0].empty()){
			if(lim==1)std::reverse(E.begin(),E.end());
			type[x]=0,e[x]=E;
		}
		else{
			if(!lim){
				int t=0;if(SZ(E)==1)t=E[0];else t=++nc,type[t]=0,e[t]=E;
				e[x]=a[0],e[x].pb(t);
			}
			else{
				int u=0;if(SZ(a[0])==1)u=a[0][0];else u=++nc,type[u]=1,e[u]=a[0];
				e[x]={u};for(auto it:E)e[x].pb(it);
				if(lim==1)std::reverse(e[x].begin(),e[x].end());
			}
		}
	}
	else{
		std::vector<int> E;
		int cnt=0;
		if(opt[e[x].back()]==1||opt[e[x][0]]==2)std::reverse(e[x].begin(),e[x].end());
		for(auto v:e[x]){
			if(opt[v]==1)cnt+=cnt==1,E.pb(v);
			else if(opt[v]==2){
				if(cnt==2)FAIL;
				cnt+=!cnt,dfs2(v,0),E.pb(v);
			}
			else{
				if(cnt==2)FAIL;
				++cnt,dfs2(v,3-cnt);
				for(auto it:e[v])E.pb(it);
			}
		}
		if(lim&&cnt==2)FAIL;
		if(lim==1)std::reverse(E.begin(),E.end());
		e[x]=E;
	}
}
int fac[N];
int calc(int x){
	int ans=x<=n?1:type[x]?fac[SZ(e[x])]:2;
	for(auto v:e[x])ans=1LL*ans*calc(v)%mod;
	return ans;
}
int main(){
	fac[0]=1;for(int i=1;i<N;++i)fac[i]=1LL*fac[i-1]*i%mod;
	int m;read(n,m);
	int rt=nc=n+1;type[n+1]=1;for(int i=1;i<=n;++i)e[n+1].pb(i);
	for(int i=1;i<=m;++i){
		int q;read(q);
		for(int i=1;i<=n;++i)opt[i]=1;
		for(int j=1,x;j<=q;++j)read(x),opt[x]=2;
		dfs1(rt),dfs2(rt,0);
	}
	printf("%d\n",calc(rt));
	return 0;
}