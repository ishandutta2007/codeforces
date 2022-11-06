#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=1e9+7;
vector<int>p[N];
int v[N],c1,c2,cl;
void dfs(int x){
	for(auto i:p[x])if(!v[i]){
		v[i]=3-v[x];dfs(i);
	}
	if(v[x]==1)++c1;else ++c2;
}
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n)v[i]=0,p[i].clear();
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	c1=c2=cl=0;
	rep(i,1,n)if(!v[i]){
		if(p[i].empty())++cl;else{
			v[i]=1;dfs(i);
		}
	}
	if(c1>c2){
		printf("%d\n",c2+cl);
		rep(i,1,n)if(v[i]!=1)printf("%d ",i);
	}else{
		printf("%d\n",c1+cl);
		rep(i,1,n)if(v[i]!=2)printf("%d ",i);
	}printf("\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}