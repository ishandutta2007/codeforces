//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m;
vector<vector<int> > Map,dp,sum1,sum2,v,v2;
void Dfs(int x,int y){
	if(Map[x][y]==0) return;
	v[x][y]=1;
	if(x!=n-1&&!v[x+1][y]) Dfs(x+1,y);
	if(y!=m-1&&!v[x][y+1]) Dfs(x,y+1);
}
void Dfs2(int x,int y){
	if(Map[x][y]==0) return ;
	v2[x][y]=1;
	if(x!=0&&!v2[x-1][y]) Dfs2(x-1,y);
	if(y!=0&&!v2[x][y-1]) Dfs2(x,y-1);
}
bool check(){
	Dfs(0,0);
	Dfs2(n-1,m-1);
	rep(i,n)
		rep(j,m) v[i][j]&=v2[i][j];
	sum1=sum2=Map;
	rep(i,n)
		rep(j,m) {
			if(v[i][j]) sum1[i][j]=sum2[i][j]=1;
			else sum1[i][j]=sum2[i][j]=0;
			if(i) sum2[i][j]+=sum2[i-1][j];
			if(j) sum1[i][j]+=sum1[i][j-1];
		}
	rep(i,n){
//		cout<<i<<" "<<sum1[i][m-1]<<endl;
		if(sum1[i][m-1]==1) return true;
	}
	rep(i,m)
	{
		if(sum2[n-1][i]==1) return true;
	}
	rep(i,n){
		rep(j,m){
			if(i&&j){
				if(sum1[i][j]+sum2[i][j]-2*(v[i][j])==1) return true;
				if(sum1[i][j]-(v[i][j])==1&&sum2[i][j]-(v[i][j])==1&&(Map[i-1][j]&&Map[i][j-1])&&(i-1!=0&&j-1!=0)){
					return true;	
				} 
			}
			
		}
	}
	rl(i,n-1,0)
	rl(j,m-1,0){
		if(v[i][j]) sum1[i][j]=sum2[i][j]=1;
		if(i!=n-1) sum2[i][j]+=sum2[i+1][j];
		if(j!=m-1) sum1[i][j]+=sum1[i][j+1];  
	}
	rep(i,n){
		rep(j,m){
			if(i!=n-1&&j!=m-1)
			if(sum1[i][j]+sum2[i][j]-2*(v[i][j])==1){
				return true;
			} 
		}
	}
	return false;
}
int main(){
	cin>>n>>m;
	vector<int> init(m,0);
	rep(i,n) Map.PB(init),dp.PB(init),v.PB(init),v2.PB(init);
	rep(i,n)
		rep(j,m) {
			char c;cin>>c,Map[i][j]=(c=='.');
		}
	dp[0][0]=1;
	rep(i,n)	
		rep(j,m) if(Map[i][j]&&(i||j)) dp[i][j]=dp[max(0,i-1)][j]|dp[i][max(0,j-1)];
	if(!dp[n-1][m-1]){
		puts("0");
	} 
	else{
		if(n==1||m==1) {
			puts("1");
			return 0;
		}
		if(dp[1][0]+dp[0][1]==1||dp[n-1][m-2]+dp[n-2][m-1]==1) {
			puts("1");
			return 0;
		}
		if(check()){
			puts("1");
		}
		else{
			puts("2");
		}
	}
	return 0;
}