#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,s[100005],flag=0;
vector<int> g[100005];
void dfs(int x,int fa){
	if(g[x].size()==1)s[x]=1;
	int cnt=0;
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x),s[x]+=s[y],cnt++;
	}
	if(cnt==2&&!fa)flag=1;
	if(cnt==1&&fa)flag=1;
}
int main(){
	cin>>n;
	if(n==2)return puts("YES"),0;
	for(int i=1,x,y;i<n;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	for(int i=1;i<=n;i++){
		if(g[i].size()!=1){
			dfs(i,0);
			if(flag)puts("NO");
			else puts("YES");
			return 0;
		}
	}
}