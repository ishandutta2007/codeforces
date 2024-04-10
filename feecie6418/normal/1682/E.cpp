#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200005],vst[200005],X[200005],Y[200005],id[200005],ALL,I,P,ind[200005];
vector<int> g[200005],G[200005];
bool cmp(int x,int y){
	int tx,ty;
	if(X[x]==P)tx=Y[x];
	else tx=X[x];
	if(X[y]==P)ty=Y[y];
	else ty=X[y];
	int dx=(id[tx]-I+ALL)%ALL;
	int dy=(id[ty]-I+ALL)%ALL;
	return dx<dy;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&X[i],&Y[i]);
		g[X[i]].push_back(i),g[Y[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(vst[i])continue;
		vector<int> p;
		vst[i]=1,p.push_back(i);
		int u=i;
		while(a[u]!=i)u=a[u],vst[u]=1,p.push_back(u);
		for(int j=0;j<p.size();j++)id[p[j]]=j;
		for(int j=0;j<p.size();j++){
			ALL=p.size(),I=j,P=p[j];
			sort(g[P].begin(),g[P].end(),cmp);
			for(int k=1;k<g[P].size();k++){
				G[g[P][k-1]].push_back(g[P][k]);
				ind[g[P][k]]++;
			}
		}
	}
	queue<int> q;
	for(int i=1;i<=m;i++)if(!ind[i])q.push(i);
	while(!q.empty()){
		int x=q.front();
		cout<<x<<' ',q.pop();
		for(int y:G[x])if(!--ind[y])q.push(y);
	}
}