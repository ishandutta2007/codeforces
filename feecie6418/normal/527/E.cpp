#include<bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int n,m,a[100005],fr[300005],to[300005],v[300005],k,cur[100005];
void A(int x,int y,int z){
	fr[z]=x,to[z]=y,g[x].push_back(z),g[y].push_back(z);
}
void dfs(int x){
	for(int &j=cur[x],i;j<g[x].size();j++){
		if(v[i=g[x][j]])continue;
		v[i]=1;
		if(fr[i]==x)dfs(to[i]);
		else dfs(fr[i]);
		if(((++k)&1)==(fr[i]==x))printf("%d %d\n",fr[i],to[i]);
		else printf("%d %d\n",to[i],fr[i]);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,A(x,y,i);
	for(int i=1;i<=n;i++)if(g[i].size()&1)a[++a[0]]=i;
	for(int i=1;i+1<=a[0];i+=2)A(a[i],a[i+1],++m);
	if(m&1)A(1,1,++m);
	cout<<m<<'\n',dfs(1);
}