#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,K;
ll dp[N][N],D[N][N],R[N][N],tD[N][N],tR[N][N];
struct Data{
	int x,y,w;	
	Data(int _x,int _y,int _w){x=_x,y=_y,w=_w;}
};
vector<Data> _D[N][N],_R[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>K;;
	for(int i=1;i<=K;++i){
		int x,y,d,t,w;
		cin>>x>>y>>d>>t>>w;
		bool ok[4]={false,false,false,false};
		if(t<=x+y&&(x+y)%4==t%4)ok[0]=true;
		if(t<=x+y-1&&(x+y)%4==(t+1)%4)ok[1]=true;
		if(t<=x+y+d-2&&(x+y+d)%4==(t+2)%4)ok[2]=true;
		if(t<=x+y+d-3&&(x+y+d)%4==(t+3)%4)ok[3]=true;
		if(ok[0])D[x][y]+=w,R[x][y]+=w;
		if(ok[1])D[x+d][y-d]+=w,R[x+d][y-d]+=w;
		if(ok[2])D[x+d][y]+=w,R[x+d][y]+=w;
		if(ok[3])D[x][y+d]+=w,R[x][y+d]+=w;
		if(ok[0]&&ok[3])_R[x][y+d].push_back(Data(x,y,w));
		if(ok[0]&&ok[2])_D[x+d][y].push_back(Data(x,y,w));
		if(ok[1]&&ok[2])_R[x+d][y].push_back(Data(x+d,y-d,w));
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(!i&&!j)continue;
			for(auto [x,y,w]:_D[i][j]){
				tD[x][y]+=w;
			}
			for(auto [x,y,w]:_R[i][j]){
				tR[x][y]+=w;
			}
			ll now=D[i][j];
			for(int k=i-1;k>=0;--k){
				now-=tD[k][j];
				dp[i][j]=min(dp[i][j],dp[k][j]+now);
				now+=D[k][j];
			}
			now=R[i][j];
			for(int k=j-1;k>=0;--k){
				now-=tR[i][k];
				dp[i][j]=min(dp[i][j],dp[i][k]+now);
				now+=R[i][k];
			}
		}	
	}
	cout<<dp[n-1][m-1]<<'\n';
	return 0;
}