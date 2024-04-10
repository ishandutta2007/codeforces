#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,ll>pil;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
vector<int>p[N];bool v[N];int c[N];
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		v[i]=0;c[i]=0;p[i].clear();
	}
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
	}
	vector<int>ans;
	rep(i,1,n)if(p[i].size()==2&&p[i][0]>p[i][1])swap(p[i][0],p[i][1]);
	rep(i,1,n)if(!v[i]){
		if(c[i])continue;
		for(auto&j:p[i])if(!v[j]){v[j]=1;
			for(auto&k:p[j])++c[k];
		}
	}else if(c[i])for(auto&j:p[i])--c[j];
	int tot=0;
	rep(i,1,n)if(c[i])++tot;
	if(tot*7>n*4)for(;;);
	printf("%d\n",tot);
	rep(i,1,n)if(c[i])printf("%d ",i);
	printf("\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}