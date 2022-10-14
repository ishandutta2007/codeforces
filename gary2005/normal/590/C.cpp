/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m;
int dp[1002][1002][3];
char c[1002][1002];
int walk[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main(){
	fastio;
	cin>>n>>m;	
	memset(dp,0x3f,sizeof(dp));
	deque <pair<pair<mp,int>,int> > q;
	rb(i,1,n)
		rb(j,1,m)
		{
			cin>>c[i][j];
			if(c[i][j]<='3'&&c[i][j]>='1'){
				dp[i][j][c[i][j]-'1']=0;
				q.PB(II(II(II(i,j),c[i][j]-'1'),0));
			}
		}
	while(!q.empty()){
		int i,j,k;
		i=(*q.begin()).FIR.FIR.FIR;
		j=(*q.begin()).FIR.FIR.SEC;
		k=(*q.begin()).FIR.SEC;
		if((*q.begin()).SEC!=dp[i][j][k]){
			q.pop_front();
			continue;
		}
//		cout<<i<<" "<<j<<" "<<k<<endl;
		q.pop_front();
		rep(J,4){
			int ni,nj;
			ni=i+walk[J][0];
			nj=j+walk[J][1];
			if(ni>0&&ni<n+1&&nj>0&&nj<=m);
			else continue; 
			if(c[ni][nj]=='#'){
				continue;
			}
//			cout<<ni<<" "<<nj<<"_"<<dp[i][j][k]<<endl;
			if(c[ni][nj]=='.'){
				if(dp[ni][nj][k]>dp[i][j][k]+1){
					dp[ni][nj][k]=dp[i][j][k]+1;
					q.push_back(II(II(II(ni,nj),k),dp[ni][nj][k]));
				}
			}
			else{
				if(dp[ni][nj][k]>dp[i][j][k]){
					dp[ni][nj][k]=dp[i][j][k];
					q.push_front(II(II(II(ni,nj),k),dp[ni][nj][k]));
				}
			}
		}
	}
	int res=INF;
	rb(i,1,n)
		rb(j,1,m)
			if(dp[i][j][0]!=INF&&dp[i][j][1]!=INF&&dp[i][j][2]!=INF)
			res=min(res,dp[i][j][0]+dp[i][j][1]+dp[i][j][2]-2*(c[i][j]=='.'));
	if(res==INF)
		res=-1;
	cout<<res<<endl;
	return 0;
}