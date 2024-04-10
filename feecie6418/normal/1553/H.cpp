#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,K,a[530005],c[10600005][2],rt=1,tot=1,mn[21][530005];
void Insert(int p){
	int x=rt,m[24]={0};
	while(p)m[++m[0]]=p%2,p/=2;
	for(int i=K;i>=1;i--){
		if(!c[x][m[i]])c[x][m[i]]=++tot;
		x=c[x][m[i]];
	}
}
int Qmi(int p,int x,int dep){
	if(dep==K)return 0;
	if(c[p][(x>>K-dep-1)&1])return Qmi(c[p][(x>>K-dep-1)&1],x,dep+1);
	if(c[p][((x>>K-dep-1)&1)^1])return Qmi(c[p][((x>>K-dep-1)&1)^1],x,dep+1)+(1<<K-dep-1);
	return assert(0),0;
}
int Qmx(int p,int x,int dep){
	if(dep==K)return 0;
	if(c[p][((x>>K-dep-1)&1)^1])return Qmx(c[p][((x>>K-dep-1)&1)^1],x,dep+1)+(1<<K-dep-1);
	if(c[p][(x>>K-dep-1)&1])return Qmx(c[p][(x>>K-dep-1)&1],x,dep+1);
	return assert(0),0;
}
void dfs(int x,int dep){
	if(!x)return ;
	if(c[x][0]&&c[x][1]){
		for(int i=0;i<(1<<K-dep);i++){
			int w=(i>>K-dep-1)&1;
			mn[dep][i]=min(mn[dep][i],Qmi(c[x][w^1],i,dep+1)-Qmx(c[x][w],i,dep+1)+(1<<K-dep-1));
			//cout<<"MN:"<<dep<<' '<<i<<' '<<mn[dep][i]<<'\n';
		}
	}
	dfs(c[x][0],dep+1),dfs(c[x][1],dep+1);
}
int main(){
	scanf("%d%d",&n,&K),memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),Insert(a[i]);
	dfs(rt,0);
	for(int i=0;i<(1<<K);i++){
		int ans=1e9;
		for(int j=0;j<K;j++)ans=min(ans,mn[j][i&((1<<K-j)-1)]);
		cout<<ans<<' ';
	}
}