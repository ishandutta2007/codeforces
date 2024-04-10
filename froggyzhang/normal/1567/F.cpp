#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
int n,m,ans[N][N];
const int d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
char s[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>(s[i]+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i][j]=='X'){
				int cnt=0;
				for(int k=0;k<4;++k){
					int x=i+d[k][0],y=j+d[k][1];
					if(s[x][y]=='.')++cnt;
				}
				if(cnt&1){cout<<"NO\n";return 0;}
				ans[i][j]=cnt/2*5;
			}
		}
	}
	cout<<"YES\n";
	for(int i=1,k=1;i<=n;++i,k^=5){
		for(int j=1;j<=m;++j){
			if(s[i][j]=='.')ans[i][j]=k;
			else if(s[i-1][j]=='X')k^=5;
		}
	}
	for(int i=1;i<=n;++i,cout<<'\n')
		for(int j=1;j<=m;++j)
			cout<<ans[i][j]<<' ';
	return 0;
}