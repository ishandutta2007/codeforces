#include<bits/stdc++.h>
using namespace std;
#define N 30
typedef long long ll;
int n,m,K,vis[N][N];
char s[N][N];
inline bool In(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;	
}
void check(int x,int y){
	for(int i=1;i<=K;++i){
		if(!In(x-i,y+i)||!In(x-i,y-i)||s[x-i][y-i]^'*'||s[x-i][y+i]^'*')return;
	}
	vis[x][y]=1;
	for(int i=1;;++i){
		if(!In(x-i,y+i)||!In(x-i,y-i)||s[x-i][y-i]^'*'||s[x-i][y+i]^'*')return;
		vis[x-i][y-i]=vis[x-i][y+i]=1;
	}
}
void Solve(){
	cin>>n>>m>>K;
	for(int i=1;i<=n;++i){
		cin>>(s[i]+1);	
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i][j]=='*')check(i,j);	
		}	
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!vis[i][j]&&s[i][j]=='*'){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}