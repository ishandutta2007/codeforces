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
vector<int>p[N];
int d[N],f[N];
void dfs(int x){
	for(auto&i:p[x])if(i!=f[x]){
		f[i]=x;d[i]=d[x]^1;dfs(i);
	}
}
int main(){int n;
	scanf("%d",&n);
	rep(i,2,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}int rt=0;
	rep(i,1,n)if(p[i].size()==1){
		rt=i;break;
	}
	dfs(rt);int an1=1;
	rep(i,1,n)if(p[i].size()==1&&d[i]){
		an1=3;break;
	}int an2=n-1;
	rep(i,1,n){int ct=0;
		for(auto&j:p[i])if(p[j].size()==1)++ct;
		if(ct)an2-=ct-1;
	}
	printf("%d %d\n",an1,an2);
}