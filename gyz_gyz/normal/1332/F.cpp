#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
ll a[N],b[N],c[N];int f[N];vector<int>p[N];
void dfs(int x){a[x]=1;
	for(auto&i:p[x])if(i!=f[x]){
		f[i]=x;dfs(i);
		ll p2=(a[i]+b[i])%mo;
		ll p0=(p2+c[i])%mo;
		ll p1=(p0+a[i])%mo;
		b[x]=(b[x]*(p0+p1)+a[x]*p1)%mo;
		c[x]=(c[x]*(p0+p2)+a[x]*p2)%mo;
		a[x]=a[x]*p0%mo;
	}
}
int main(){int n;
	scanf("%d",&n);
	rep(i,2,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	dfs(1);
	printf("%lld\n",(a[1]+b[1]+c[1]+mo-1)%mo);
}