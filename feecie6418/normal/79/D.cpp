#include<bits/stdc++.h>
using namespace std;
int n,K,m,cnt,a[10005],b[22],len[105],f[1050005],t[22],dis[22][20005];
void bfs(int id){
	queue<int> q;
	memset(dis[id],0x3f3f3f3f,sizeof(dis[id])),dis[id][b[id]]=0,q.push(b[id]);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=1;i<=m;i++){
			if(x>len[i])if(dis[id][x-len[i]]>1e9)q.push(x-len[i]),dis[id][x-len[i]]=dis[id][x]+1;
			if(x+len[i]<=n+1)if(dis[id][x+len[i]]>1e9)q.push(x+len[i]),dis[id][x+len[i]]=dis[id][x]+1;
		}
	}
}
int main(){
	cin>>n>>K>>m;
	for(int i=1,x;i<=K;i++)cin>>x,a[x]=1;
	for(int i=1;i<=n+1;i++)if(a[i]^a[i-1])b[cnt++]=i;
	if(cnt&1)return puts("-1"),0;
	for(int i=1;i<=m;i++)cin>>len[i];
	for(int i=0;i<cnt;i++)bfs(i);
	for(int i=1,s;i<(1<<cnt);i++){
		f[i]=0x3f3f3f3f,s=0;
		for(int j=0;j<cnt;j++)if(i&(1<<j))t[++s]=j;
		for(int j=1;j<s;j++){
			for(int k=j+1;k<=s;k++)f[i]=min(f[i],f[i-(1<<t[j])-(1<<t[k])]+dis[t[j]][b[t[k]]]);
		}
	}
	cout<<(f[(1<<cnt)-1]==0x3f3f3f3f?-1:f[(1<<cnt)-1]);
}