#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,ans[405][405],cnt[405][405],dis[405][405],X[605],Y[605];
vector<int> g[405];
void bfs(int fr){
	queue<int> q;
	memset(dis[fr],0x3f,sizeof(dis[fr])),dis[fr][fr]=0,cnt[fr][fr]=1,q.push(fr);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int y:g[x]){
			if(dis[fr][y]>dis[fr][x]+1)dis[fr][y]=dis[fr][x]+1,cnt[fr][y]=cnt[fr][x],q.push(y);
			else if(dis[fr][y]==dis[fr][x]+1)cnt[fr][y]=min(cnt[fr][y]+cnt[fr][x],2);
		}
	}
}
int Calc(int x,int y){
	int ans=1;
	for(int i=1;i<=n;i++){
		if(dis[x][i]+dis[y][i]==dis[x][y])continue;
		int cnt=0;
		for(int j:g[i])if(dis[x][j]+1==dis[x][i]&&dis[y][j]+1==dis[y][i])cnt++;
		ans=1ll*ans*cnt%mod;
	}
	return ans;
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x),X[i]=x,Y[i]=y;
	for(int i=1;i<=n;i++)bfs(i);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout<<"C:"<<i<<' '<<j<<' '<<cnt[i][j]<<endl;
			if(cnt[i][j]==2){
				printf("0 ");
				continue;
			}
			printf("%d ",Calc(i,j));
		}
		puts("");
	}
    return 0;
}