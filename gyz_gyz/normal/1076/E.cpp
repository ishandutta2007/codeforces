#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 3000000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,m,x,y,f[N],h[N];ll ans[N],a[N],z;
struct pr{int x;ll y;};
vector<pr>q[N];vector<int>p[N];
void ins(int x,ll y){
	for(;x;x-=x&-x)a[x]+=y;
}
ll qs(int x){ll y=0;
	for(;x<=n;x+=x&-x)y+=a[x];
	return y;
}
void dfs(int x){
	for(auto i:q[x])ins(min(i.x+h[x],n),i.y);
	ans[x]=qs(h[x]);
	for(auto i:p[x])if(i!=f[x]){
		f[i]=x;h[i]=h[x]+1;dfs(i);
	}
	for(auto i:q[x])ins(min(i.x+h[x],n),-i.y);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	scanf("%d",&m);
	rep(i,1,m){
		scanf("%d%d%I64d",&x,&y,&z);
		y=min(y,n);q[x].pb({y,z});
	}
	h[1]=1;dfs(1);
	rep(i,1,n)printf("%I64d ",ans[i]);
}