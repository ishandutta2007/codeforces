#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t[200005],h[200005],ind[200005],outd[200005],vst[200005];
ll f[200005][2],ans=0;//0: 1: 
vector<int> g[200005];
void dfs(int x,int fa){
	vst[x]=1;
	vector<int> sons;
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x),sons.push_back(y),f[x][0]+=f[y][1],f[x][1]+=f[y][0];
	}
	//f[x][0]x 
	f[x][0]+=1ll*max(ind[x],outd[x]+(int)g[x].size())*t[x];
	sort(sons.begin(),sons.end(),[](int x,int y){return f[x][0]-f[x][1]<f[y][0]-f[y][1];});
	ll mx=0,sum=0,tid=ind[x],tod=outd[x]+g[x].size();
	for(int i:sons){
		sum+=f[i][0]-f[i][1];
		tod--,tid++;
		mx=min(mx,sum-1ll*max(ind[x],outd[x]+(int)g[x].size())*t[x]+1ll*max(tid,tod)*t[x]);
	}
	f[x][0]+=mx; 
	//f[x][1]y
	f[x][1]+=1ll*max(ind[x]+(int)g[x].size(),outd[x])*t[x];
	sort(sons.begin(),sons.end(),[](int x,int y){return f[x][1]-f[x][0]<f[y][1]-f[y][0];});
	mx=0,sum=0,tid=ind[x]+g[x].size(),tod=outd[x];
	for(int i:sons){
		sum+=f[i][1]-f[i][0];
		tod++,tid--;
		mx=min(mx,sum-1ll*max(ind[x]+(int)g[x].size(),outd[x])*t[x]+1ll*max(tid,tod)*t[x]);
	}
	f[x][1]+=mx;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		if(h[x]>h[y])ind[x]++,outd[y]++;
		else if(h[x]<h[y])outd[x]++,ind[y]++;
		else g[x].push_back(y),g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)if(!vst[i])dfs(i,0),ans+=f[i][0];
	cout<<ans;
}