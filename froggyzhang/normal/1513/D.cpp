#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,C,p[N],vis[N],a[N];
ll Solve(){
	ll ans=0;
	n=read(),C=read();
	int res=n-1;
	for(int i=1;i<=n;++i){
		a[i]=read();
		p[i]=i;
		vis[i]=0;
	}
	sort(p+1,p+n+1,[&](int i,int j){return a[i]<a[j];});
	for(int i=1;i<=n;++i){
		int u=p[i];
		if(a[u]>=C)break;
		if(vis[u])continue;
		int l=u,r=u;
		while(r<n&&a[r+1]%a[u]==0){
			ans+=a[u],--res;
			if(vis[++r])break;
			vis[r]=1;
		}
		while(l>1&&a[l-1]%a[u]==0){
			ans+=a[u],--res;
			if(vis[--l])break;
			vis[l]=1;
		}
		vis[u]=1;
	}
	return ans+1LL*res*C;
}
int main(){
	T=read();
	while(T--){
		printf("%lld\n",Solve());
	}
	return 0;
}