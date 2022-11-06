#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
ll ans,a[N][2],b[N][2];bool c[N];int f[N];
vector<pair<int,bool>>p[N];
void dfs(int x){
	for(auto i:p[x])if(i.fr!=f[x]){
		f[i.fr]=x;c[i.fr]=i.sc;dfs(i.fr);
		ans+=a[x][0]*b[i.fr][0]+a[x][1]*b[i.fr][0]+a[x][1]*b[i.fr][1]
		+a[i.fr][0]*b[x][0]+a[i.fr][1]*b[x][0]+a[i.fr][1]*b[x][1];
		a[x][0]+=a[i.fr][0];a[x][1]+=a[i.fr][1];
		b[x][0]+=b[i.fr][0];b[x][1]+=b[i.fr][1];
	}
	ans+=a[x][0]+a[x][1]+b[x][0]+b[x][1];
	if(x!=1){
		if(c[x]){++a[x][1];
			b[x][1]+=b[x][0]+1;
			a[x][0]=b[x][0]=0;
		}else{++b[x][0];
			a[x][0]+=a[x][1]+1;
			a[x][1]=b[x][1]=0;
		}
	}
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n-1){int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		p[x].pb({y,z});
		p[y].pb({x,z});
	}dfs(1);
	printf("%lld\n",ans);
}