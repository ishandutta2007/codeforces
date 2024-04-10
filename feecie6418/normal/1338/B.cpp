#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,sd[2],d[100005],c[100005],is[100005],ans;
vector<int> g[100005];
void DFS(int x,int fa){
	d[x]=d[fa]+1;
	if(c[x]==1){
		sd[d[x]%2]++;
		is[x]=1;
		return ;
	}
	int sum=0;
	for(int y:g[x]){
		if(y==fa)continue;
		DFS(y,x);
		//cout<<x<<' '<<y<<' '<<is[y]<<endl;
		sum+=is[y];
	}
	//cout<<sum<<endl;
	ans+=max(sum-1,0);
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<n; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y),g[y].push_back(x);
		c[x]++,c[y]++; 
	}
	int root=1;
	for(int i=1;i<=n;i++)if(c[i]>1)root=i;
	DFS(root,0);
	if(sd[0]&&sd[1])printf("3 ");
	else printf("1 ");
	printf("%d\n",n-ans-1);
}