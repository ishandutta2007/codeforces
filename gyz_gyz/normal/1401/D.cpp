#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=1e9;
const int mo=1e9+7;
int n,f[N];ll w[N],s[N],a[N];
vector<int>p[N];
void dfs(int x){s[x]=1;
	for(auto&i:p[x])if(i!=f[x]){
		f[i]=x;dfs(i);s[x]+=s[i];
	}
	if(x!=1)a[x-1]=s[x]*(n-s[x]);
}
void sol(){
	scanf("%d",&n);
	rep(i,1,n){
		f[i]=0;p[i].clear();
	}
	rep(i,2,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	dfs(1);sort(a+1,a+n);
	int m;scanf("%d",&m);
	rep(i,1,m)scanf("%lld",&w[i]);
	sort(w+1,w+m+1);ll ans=0;
	if(m<n){
		rep(i,1,n-m-1)ans=(ans+a[i])%mo;
		rep(i,n-m,n-1)ans=(ans+a[i]%mo*w[i-n+m+1])%mo;
	}else{
		ans=a[n-1]%mo;
		rep(i,n-1,m)ans=ans*w[i]%mo;
		rep(i,1,n-2)ans=(ans+a[i]%mo*w[i])%mo;
	}
	printf("%lld\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}