#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back
#define N 300010
#define mo 998244353
using namespace std;
typedef long long ll;
int n,k,h[N],c[N],f[N],F[N];ll a[2][N];
struct cmp{bool operator ()(int x,int y){return h[x]>h[y];}};
multiset<int,cmp>s[N];vector<int>p[N],P[N];
void dfs(int x){
	for(auto i:p[x])if(i!=f[x]){
		f[i]=x;h[i]=h[x]+1;dfs(i);
	}
}
void dp(int x){a[0][x]=1;
	for(auto i:P[x])if(F[x]!=i){
		F[i]=x;dp(i);
		a[1][x]=(a[1][x]*(a[0][i]+a[1][i])+a[0][x]*a[1][i])%mo;
		a[0][x]=a[0][x]*(a[0][i]+a[1][i])%mo;
	}
	if(x<=k)a[1][x]=a[0][x],a[0][x]=0;
}
int main(){
	scanf("%d",&n);k=2;
	rep(i,1,n){
		scanf("%d",&c[i]);
	}
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}dfs(1);
	rep(i,1,n)if(c[i])s[c[i]].insert(i);
	rep(i,1,k)while(s[i].size()>1){
		int x=*s[i].begin();s[i].erase(s[i].begin());
		if(!c[f[x]]){
			c[f[x]]=i;s[i].insert(f[x]);
		}
		if(c[f[x]]!=i)return printf("0\n"),0;
	}int tot=k;
	rep(i,1,n)if(!c[i])c[i]=++tot;
	rep(i,1,n)for(auto j:p[i])if(c[i]!=c[j]){
		P[c[i]].pb(c[j]);
	}
	dp(1);printf("%lld\n",a[1][1]);
}