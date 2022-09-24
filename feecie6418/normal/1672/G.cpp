#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int n,m,d[4005],vst[4005],M,N,sall;
char a[2005][2005],b[2005][2005];
vector<int> g[4005];
void dfs(int x){
	vst[x]=1,N++,sall^=d[x];
	for(int y:g[x]){
		if(!vst[y])dfs(y);
		if(x<y)M++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	if(n%2==0&&m%2==0){
		int s=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)s+=(a[i][j]=='?');
		cout<<Power(2,s);
		return 0;
	}
	if(m%2==0){
		swap(n,m);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)b[i][j]=a[j][i];
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=b[i][j];
	}
	if(n%2==0){
		int ans=0;
		for(int v=0;v<2;v++){
			int s=1;
			for(int i=1;i<=n;i++){
				int cnt=0,cur=0;
				for(int j=1;j<=m;j++){
					if(a[i][j]=='1')cur^=1;
					if(a[i][j]=='?')cnt++;
				}
				if(!cnt){
					if(cur!=v)s=0;
				}
				else s=1ll*s*Power(2,cnt-1)%mod;
			}
			ans=(ans+s)%mod;
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int v=0;v<2;v++){
		for(int i=1;i<=n+m;i++)g[i].clear(),d[i]=v,vst[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='1')d[i]^=1,d[j+n]^=1;
				if(a[i][j]=='?')g[i].push_back(j+n),g[j+n].push_back(i);
			}
		}
		int s=1;
		for(int i=1;i<=n+m;i++){
			if(vst[i])continue;
			M=N=sall=0,dfs(i);
			if(sall)s=0;
			else s=1ll*s*Power(2,M-N+1)%mod;
		}
		ans=(ans+s)%mod;
	}
	cout<<ans;
}