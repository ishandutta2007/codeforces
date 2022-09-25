#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
typedef pair<bool,bool> pbb;
int n,p[N];
int dp[N][2][2];
pair<bool,bool> pre[N][2][2];
void dfs(int u,int x,int y){
	if(u==n+1)return;
	cout<<(!x?-p[u]:p[u])<<' ';
	dfs(u+1,pre[u][x][y].first,pre[u][x][y].second);
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>p[i];
		dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=-n-1;
	}
	dp[n][0][0]=dp[n][1][0]=n+1;
	for(int i=n-1;i>=1;--i){
		for(int c=0;c<2;++c){
			int z=!c?-p[i]:p[i];
			if(dp[i+1][0][0]>=-n){
				int x=-p[i+1],y=dp[i+1][0][0];
				if(z<x){
					if(y>dp[i][c][0]){
						dp[i][c][0]=y,pre[i][c][0]=pbb(0,0);
					}
				}
				else if(z<y){
					if(x>dp[i][c][1]){
						dp[i][c][1]=x,pre[i][c][1]=pbb(0,0);
					}	
				}
			}
			if(dp[i+1][1][0]>=-n){
				int x=p[i+1],y=dp[i+1][1][0];
				if(z<x){
					if(y>dp[i][c][0]){
						dp[i][c][0]=y,pre[i][c][0]=pbb(1,0);
					}
				}
				else if(z<y){
					if(x>dp[i][c][1]){
						dp[i][c][1]=x,pre[i][c][1]=pbb(1,0);
					}	
				}
			}
			if(dp[i+1][0][1]>=-n){
				int y=-p[i+1],x=dp[i+1][0][1];
				if(z<x){
					if(y>dp[i][c][0]){
						dp[i][c][0]=y,pre[i][c][0]=pbb(0,1);
					}
				}
				else if(z<y){
					if(x>dp[i][c][1]){
						dp[i][c][1]=x,pre[i][c][1]=pbb(0,1);
					}	
				}
			}
			if(dp[i+1][1][1]>=-n){
				int y=p[i+1],x=dp[i+1][1][1];
				if(z<x){
					if(y>dp[i][c][0]){
						dp[i][c][0]=y,pre[i][c][0]=pbb(1,1);
					}
				}
				else if(z<y){
					if(x>dp[i][c][1]){
						dp[i][c][1]=x,pre[i][c][1]=pbb(1,1);
					}	
				}
			}
		}
	}
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			if(dp[1][i][j]>=-n){
				cout<<"YES\n";
				dfs(1,i,j);	
				cout<<'\n';
				return;
			}
		}	
	}
	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}