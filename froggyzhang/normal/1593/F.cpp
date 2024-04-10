#include<bits/stdc++.h>
using namespace std;
#define N 42
typedef long long ll;
bool dp[N][N][N][N];
pair<int,bool> pre[N][N][N][N];
int n,A,B;
char s[N];
void dfs(int x,int y,int p,int q){
	assert(dp[x][y][p][q]);
	if(!x&&!y)return;
	auto [c,w]=pre[x][y][p][q];
	if(w)dfs(x,y-1,p,c);
	else dfs(x-1,y,c,q);
	cout<<(w?'B':'R');	
}
void Solve(){
	cin>>n>>A>>B;
	cin>>(s+1);
	memset(dp,false,sizeof(dp));
	dp[0][0][0][0]=true;
	for(int i=1;i<=n;++i){
		int c=s[i]-'0';
		for(int x=0;x<i;++x){
			int y=i-1-x;
			for(int p=0;p<A;++p){
				for(int q=0;q<B;++q){
					if(!dp[x][y][p][q])continue;
					int c0=(p*10+c)%A;
					int c1=(q*10+c)%B;
					dp[x+1][y][c0][q]=dp[x][y+1][p][c1]=true;
					pre[x+1][y][c0][q]=make_pair(p,0);
					pre[x][y+1][p][c1]=make_pair(q,1);
				}
			}
		}
	}
	for(int i=n/2;i>=1;--i){
		if(dp[i][n-i][0][0]){
			dfs(i,n-i,0,0);
			cout<<'\n';
			return;
		}
		if(dp[n-i][i][0][0]){
			dfs(n-i,i,0,0);
			cout<<'\n';
			return;
		}
	}
	cout<<-1<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}