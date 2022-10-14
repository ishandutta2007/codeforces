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
int n,m,v[2002][2002],dp[2002][2002],r,c,x,y;
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
char maze[2002][2002];
bool check(int x,int y){
	if(maze[x][y]=='*') return 0;
	if(x<=0||x>n||y<=0||y>m) return 0;
	return 1;
}
priority_queue<pair<int,mp>,vector<pair<int,mp> >,greater< pair<int,mp> > > q;
int main(){
//	freopen("test.in","r",stdin);
	fastio;
	cin>>n>>m>>r>>c>>x>>y;
	rb(i,1,n)
		rb(j,1,m)
			cin>>maze[i][j];
	memset(dp,63,sizeof(dp));
	dp[r][c]=0;
	q.push(II(0,II(r,c)));
	while(!q.empty()){
		pair<int,mp> now;
		now=q.top();
		q.pop();
		int i,j;
		i=now.SEC.FIR,j=now.SEC.SEC;
		if(now.FIR!=dp[i][j]||now.FIR>y) continue;
		rep(k,4){
			int nx,ny;
			nx=i+dir[k][0];
			ny=j+dir[k][1];
			if(check(nx,ny)&&dp[nx][ny]>dp[i][j]+(!(k))){
				dp[nx][ny]=dp[i][j]+(!(k));
				q.push(II(dp[nx][ny],II(nx,ny)));
			}
		}
	}
	int res=0;
	rb(i,1,n)
		rb(j,1,m){
			if(dp[i][j]<=y&&dp[i][j]-(j-c)<=x){
				res++;
			}
		}
			
	cout<<res<<endl;
	return 0;
}