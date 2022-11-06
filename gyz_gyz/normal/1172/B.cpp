#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=998244353;
ll a[N],s[N];int f[N];vector<int>p[N];
void dfs(int x){
	a[x]=s[p[x].size()];
	for(auto i:p[x])if(i!=f[x]){
		f[i]=x;dfs(i);a[x]=a[x]*a[i]%mo;
	}
}
int main(){int n;
	scanf("%d",&n);s[0]=1;
	rep(i,1,n)s[i]=s[i-1]*i%mo;
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}dfs(1);
	printf("%lld\n",a[1]*n%mo);
}