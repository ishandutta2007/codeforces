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
int dp[1001][1001][41];
int Min_dis[41][41]; 
int a[1001][1001];
int n,m,k;
vector<mp> each[41];
int dis[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
typedef pair<int,mp>  thispair;
struct QUU{
		thispair Q[1000000+20];
		int h=0,t=-1;
		void clear_()
		{
			h=0,t=-1;
		}
		void push_(thispair A){
			Q[++t]=A;
		}
		bool empty_(){
			return !bool(t-h+1);
		}
		void pop_(){
			h++;
		}
		thispair top_(){
			return Q[h];
		}
}q;
void solve(int col){
	q.clear_();
	rb(i,1,n)
		rb(j,1,m)
			if(!dp[i][j][col])
			q.push_(II(-dp[i][j][col],II(i,j)));
	bool Min[41]={0};
	while(!q.empty_()){
		int val,x,y;
		val=-q.top_().FIR;
		x=q.top_().SEC.FIR;
		y=q.top_().SEC.SEC;
		q.pop_();
		if(!Min[a[x][y]]){
			Min[a[x][y]]=1;
			for(auto it:each[a[x][y]]){
				if(dp[it.FIR][it.SEC][col]>val+1){
					dp[it.FIR][it.SEC][col]=val+1;
					q.push_(II(-(val+1),it));
				}
			}
		}
		if(val!=dp[x][y][col]){
			continue;
		}
		rep(i,4){
			int nx,ny;
			nx=x+dis[i][0];
			ny=y+dis[i][1];
			if(nx<=n&&nx>=1&&ny<=m&&ny>=1){
				if(val+1<dp[nx][ny][col]){
					dp[nx][ny][col]=val+1;
					q.push_(II(-(val+1),II(nx,ny)));
				}
			}
		}
	}
}
int main(){
	fastio;
	cin>>n>>m>>k;
	memset(dp,0x3f,sizeof(dp));//cout<<"!"<<endl;
	rb(i,1,n)
		rb(j,1,m)
			cin>>a[i][j],dp[i][j][a[i][j]]=0,each[a[i][j]].PB(II(i,j));
	
	rb(i,1,k){
		solve(i);
	}
	memset(Min_dis,0x3f,sizeof(Min_dis));
	rb(i,1,n)
		rb(j,1,m)
			rb(K,1,k)
			Min_dis[a[i][j]][K]=Min_dis[K][a[i][j]]=min(Min_dis[a[i][j]][K],dp[i][j][K]);
	int q;
	cin>>q;
	while(q--){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		int res=min(min(abs(r1-r2)+abs(c1-c2),2+Min_dis[a[r1][c1]][a[r2][c2]]),min(dp[r2][c2][a[r1][c1]]+1,dp[r1][c1][a[r2][c2]]+1)); 
		rb(i,1,k){
			res=min(res,dp[r1][c1][i]+dp[r2][c2][i]+1);
		}
		cout<<res<<endl;
	}
	return 0;
}