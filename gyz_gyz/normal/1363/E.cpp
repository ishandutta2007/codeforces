#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
ll ans;vector<int>p[N];int a[N],b[N],f[N];
void dfs(int x){int tot=abs(b[x]);
	for(auto&i:p[x])if(i!=f[x]){
		f[i]=x;a[i]=min(a[i],a[x]);dfs(i);
		b[x]+=b[i];tot+=abs(b[i]);
	}
	ans+=1ll*(tot-abs(b[x]))*a[x];
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){int x,y;
		scanf("%d%d%d",&a[i],&x,&y);
		b[i]=x-y;
	}
	rep(i,2,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}dfs(1);
	printf("%lld\n",b[1]?-1:ans);
}