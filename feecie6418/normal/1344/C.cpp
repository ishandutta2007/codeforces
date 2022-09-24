#include<bits/stdc++.h>
using namespace std;
int n,m,vst[200005],d[200005],f1[200005],f2[200005];
vector<int> g[200005],g2[200005];
void dfs1(int x){
	if(f1[x])return ;
	f1[x]=x;
	for(int y:g[x])dfs1(y),f1[x]=min(f1[x],f1[y]);
}
void dfs2(int x){
	if(f2[x])return ;
	f2[x]=x;
	for(int y:g2[x])dfs2(y),f2[x]=min(f2[x],f2[y]);
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,g[x].push_back(y),g2[y].push_back(x),d[y]++;
	queue<int> q;
	for(int i=1;i<=n;i++)if(!d[i])q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop(),vst[x]=1;
		for(int y:g[x]){
			d[y]--;
			if(!d[y])q.push(y);
		}
	}
	bool flag=0;
	for(int i=1;i<=n;i++)if(!vst[i])flag=1;
	if(flag)return puts("-1"),0;
	for(int i=1;i<=n;i++)dfs1(i);
	for(int i=1;i<=n;i++)dfs2(i);
	int ans=0;
	for(int i=1;i<=n;i++)if(f1[i]>=i&&f2[i]>=i)ans++;
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)if(f1[i]>=i&&f2[i]>=i)cout<<'A';else cout<<'E';
	return 0;
}