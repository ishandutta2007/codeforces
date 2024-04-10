/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
bool vis[2][50][50][26];
bool ok[2][50][50][26];
string s[2];
bool can[26][26][26];
int dp[50][50];
bool dfs(int is,int l,int r,int c){
	if(l==r){
		return ok[is][l][r][c]=(s[is][l]-'a'==c);	
	}
	if(vis[is][l][r][c]){
		return ok[is][l][r][c];
	}
	vis[is][l][r][c]=1;
	rb(i,l,r-1){
		rep(j,26)
			rep(k,26){
				if(can[j][k][c])
				ok[is][l][r][c]|=dfs(is,l,i,j)&dfs(is,i+1,r,k);
			}
	}
	return ok[is][l][r][c];
}
int main(){
	R2(s[0],s[1]);
	int n;
	R(n);
	rep(i,n){
		char a,b,c,d;
		cin>>a>>d>>d>>b>>c;
		can[b-'a'][c-'a'][a-'a']=1;
	}
	rep(k,2)
	rep(i,26)
	{
		rep(j,s[k].size()){
			rep(l,s[k].size()){
				if(l>=j){
					dfs(k,j,l,i);
				}
			}
		}
	}
	memset(dp,63,sizeof(dp));
	rep(i,s[0].size())
		rep(j,s[1].size()){
			rep(k,26)
					{
						int l=k;
						rep(i2,i+1)
							rep(j2,j+1){
								if(ok[0][i2][i][k]&&ok[1][j2][j][l]){
									if(i2==0&&j2!=0) continue;
									if(j2==0&&i2!=0) continue;
									if(i2==0){
										dp[i][j]=1;
									}
									else{
										dp[i][j]=min(dp[i][j],dp[i2-1][j2-1]+1);
									}
								}
							}
					}
		}
	if(dp[s[0].size()-1][s[1].size()-1]==INF){
		dp[s[0].size()-1][s[1].size()-1]=-1;
	}
	cout<<dp[s[0].size()-1][s[1].size()-1]<<endl;
	return 0;
}