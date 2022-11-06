#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
using namespace std;
typedef long long ll;
const int N=1e6+10;
vector<int>p[N];int tot,f[N],l[N],r[N];
void dfs(int x){
	int ss=p[x].size()-(x!=1);
	int ct=tot=r[x]=tot+ss+1;
	for(auto&i:p[x])if(i!=f[x]){
		l[i]=--ct;f[i]=x;dfs(i);
	}
}
int main(){int n;
	scanf("%d",&n);
	rep(i,2,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	l[1]=tot=1;dfs(1);
	rep(i,1,n)printf("%d %d\n",l[i],r[i]);
}