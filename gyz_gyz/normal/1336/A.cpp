#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll inf=1e18;
const int mo=998244353;
int a[N],s[N],h[N];
vector<int>p[N];
bool cmp(int x,int y){return x>y;}
void dfs(int x){s[x]=1;
	for(auto&i:p[x])if(!h[i]){
		h[i]=h[x]+1;dfs(i);s[x]+=s[i];
	}
}
int main(){int n,k;ll ans=0;
	scanf("%d%d",&n,&k);
	rep(i,2,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	h[1]=1;dfs(1);
	rep(i,1,n)a[i]=h[i]-s[i];
	sort(a+1,a+n+1,cmp);
	rep(i,1,k)ans+=a[i];
	printf("%lld\n",ans);
}