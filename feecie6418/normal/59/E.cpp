#include<bits/stdc++.h>
using namespace std;
int n,m,k,x[40005],y[40005],dis[40005],pre[40005],inq[40005],ans=1e9,p,as[40005];
unordered_map<int,int> mp,is;
vector<int> o[3005],O[3005],g[40005];
int main() {
	cin>>n>>m>>k,memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)cin>>x[i]>>y[i],x[i+m]=y[i],y[i+m]=x[i];
	m*=2;
	for(int i=1;i<=m;i++)o[x[i]].push_back(i),O[y[i]].push_back(i),mp[x[i]*4000+y[i]]=i;
	for(int i=1,x,y,z;i<=k;i++)cin>>x>>y>>z,is[mp[x*4000+y]*40005+mp[y*4000+z]]=1;
	for(int i=1;i<=n;i++)for(int j:O[i])for(int k:o[i])if(!is.count(j*40005+k))g[j].push_back(k);
	queue<int> q;
	for(int i=1;i<=m;i++)if(x[i]==1)q.push(i),dis[i]=1,inq[i]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop(),inq[x]=0;
		for(int y:g[x]){
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				if(!inq[y])q.push(y),inq[y]=1,pre[y]=x;
			}
		}
	}
	for(int i=1;i<=m;i++)if(y[i]==n)if(dis[i]<ans)ans=dis[i],p=i;
	if(ans>1e6)return puts("-1"),0;
	printf("%d\n",ans),as[as[0]=1]=n;
	while(p)as[++as[0]]=x[p],p=pre[p];
	for(int i=as[0];i;i--)printf("%d ",as[i]);
}