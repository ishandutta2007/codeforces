#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
typedef long long ll;
typedef std::pair<int,int> pr;
int O[N],tim[N],ans[N];ll X[N],Y[N],M[N];char s[7];ll t[N],L[N],R[N],T[N];
std::vector<pr> E[N];
inline void addedge(int u,int v){E[std::min(tim[u],tim[v])].pb({u,v});}
int fa[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool check(ll l1,ll r1,ll l2,ll r2,ll d){
	ll l=std::max(l1,l2-d),r=std::min(r1,r2-d);
	if(r-l+1>=d+1)return true;
	return r/(d*2)*d+std::min(d,r%(d*2)+1)!=(l==0?0:(l-1)/(d*2)*d+std::min(d,(l-1)%(d*2)+1));
}
int main(){
	int n,m;read(n,m);
	int pos=0,p=0;T[++p]=0,T[++p]=1LL<<n;
	for(int i=1;i<=m;++i){
		scanf("%s",s),O[i]=s[0]=='a';
		read(X[i],Y[i]);
		if(O[i]==0)T[++p]=X[i],T[++p]=Y[i]+1;
	}
	std::sort(T+1,T+p+1),p=std::unique(T+1,T+p+1)-T-1;
	for(int i=1;i<p;++i){
		ll x=T[i],y=T[i+1]-1;
		int P=64-(x==y?64:__builtin_clzll(x^y));
		ll mid=P?y&~((1LL<<(P-1))-1):y;
		t[++pos]=x,t[++pos]=mid;
	}
	t[++pos]=1LL<<n,std::sort(t+1,t+pos+1),pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<pos;++i)tim[i]=m+1,L[i]=t[i],R[i]=t[i+1]-1;
	for(int i=1;i<=m;++i)if(O[i]==0){
		tim[std::lower_bound(t+1,t+pos+1,X[i])-t]=i;
		int P=64-(X[i]==Y[i]?64:__builtin_clzll(X[i]^Y[i]));
		ll mid=P?Y[i]&~((1LL<<(P-1))-1):Y[i];
		tim[std::lower_bound(t+1,t+pos+1,mid)-t]=i;
	}
	for(int k=0;k<n;++k){
		ll d=1LL<<k;
		for(int j=1,cur=0;j<pos;++j){
			while(cur+1<j&&L[cur+1]<=R[j]-d)++cur;
			for(int t=cur;t>=1&&R[t]>=L[j]-d;--t)if(check(L[t],R[t],L[j],R[j],d))addedge(j,t);
		}
	}
	std::iota(fa+1,fa+pos+1,1);
	for(int i=m+1;i>=1;--i){
		for(auto [x,y]:E[i])fa[find(x)]=find(y);
		if(O[i]==1){
			int a=std::upper_bound(t+1,t+pos+1,X[i])-t-1,b=std::upper_bound(t+1,t+pos+1,Y[i])-t-1;
			ans[i]=find(a)==find(b);
		}
	}
	for(int i=1;i<=m;++i)if(O[i]==1)putchar(ans[i]+48),putchar('\n');
	return 0;
}