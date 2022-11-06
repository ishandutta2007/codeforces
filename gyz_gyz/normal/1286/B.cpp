#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=1e6;
const int INF=1e9;
int a[N],b[N];vector<int>p[N],d[N];
void dfs(int x){
	for(auto&i:p[x]){dfs(i);
		for(auto&j:d[i]){
			if((int)d[x].size()==b[x])d[x].push_back(x),a[x]=d[x].size();
			d[x].push_back(j);a[j]=d[x].size();
		}
	}
	if((int)d[x].size()==b[x])d[x].push_back(x),a[x]=d[x].size();
	if((int)d[x].size()<b[x]){
		printf("NO\n");exit(0);
	}
}
int main(){int n,rt;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d%d",&x,&b[i]);
		if(x)p[x].push_back(i);else rt=i;
	}
	dfs(rt);printf("YES\n");
	rep(i,1,n)printf("%d ",a[i]);
}