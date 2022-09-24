#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,col[100005],to[100005],done[100005],p[100005];
vector<int> g[100005];
void Solve(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=(1<<n-1)*n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	to[0]=0,done[0]=1;
	int tt=0;
	for(int x:g[0])to[x]=(1<<(tt++)),done[x]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<(1<<n);j++){
			int cnt=0;
			p[j]=0;
			for(int k:g[j])cnt+=done[k],p[j]|=done[k]*to[k];
			if(cnt!=i||done[j])p[j]=-1;	
		}
		for(int j=0;j<(1<<n);j++)if(p[j]!=-1)done[j]=1,to[j]=p[j];
	}
	for(int i=0;i<(1<<n);i++)p[to[i]]=i;
	for(int i=0;i<(1<<n);i++)cout<<p[i]<<' ';
	puts("");
	if((1<<n)%n)puts("-1");
	else {
		for(int i=0;i<(1<<n);i++){
			int u=0;
			for(int j=0;j<n;j++)if(to[i]&(1<<j))u^=j;
			cout<<u<<' ';
		}
		puts("");
	}
	for(int i=0;i<(1<<n);i++)col[i]=to[i]=done[i]=p[i]=0,g[i].clear();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}