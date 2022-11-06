#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 1000010
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 998244353
#define inf 1000000000
#define eps 1e-8
using namespace std;
int n,k,tot,ans,f[N],fa[N],h[N],s[N],lf[N];bool v[N];
vector<int>p[N];
bool cmp(int x,int y){return h[x]<h[y];}
int gf(int x){
	if(f[x]==x)return x;
	f[x]=gf(f[x]);return f[x];
}
void ht(int x){
	for(auto i:p[x]){
		h[i]=h[x]+1;ht(i);
	}
}
void dfs(int x){
	for(auto i:p[x]){
		s[i]+=s[x];dfs(i);
	}
	if(s[x]>ans)ans=s[x];
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)f[i]=i;
	if(n==1){printf("0");return 0;}
	rep(i,2,n){
		scanf("%d",&fa[i]);p[fa[i]].pb(i);
	}ht(1);
	rep(i,1,n)if(!p[i].size())lf[++tot]=i;
	sort(lf+1,lf+tot+1,cmp);v[1]=1;
	rep(i,1,tot){
		int x=lf[i];v[x]=1;
		rep(j,1,k){
			f[gf(x)]=gf(fa[x]);
			if(v[fa[x]])break;
			v[fa[x]]=1;x=fa[x];
		}
	}
	rep(i,1,tot)s[gf(lf[i])]++;
	dfs(1);printf("%d",ans);
}