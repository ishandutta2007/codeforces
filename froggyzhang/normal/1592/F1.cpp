#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
int n,m,a[N][N],c[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		static char s[N];
		cin>>(s+1);
		for(int j=1;j<=m;++j){
			a[i][j]=s[j]=='B';
		}	
	}
	for(int i=1;i<=n+1;++i){
		for(int j=1;j<=m+1;++j){
			c[i][j]=a[i-1][j-1]^a[i-1][j]^a[i][j-1]^a[i][j];	
		}
	}
	int ans=0;
	for(int i=2;i<=n+1;++i)
		for(int j=2;j<=m+1;++j)
			ans+=c[i][j];
	for(int i=2,ok=0;i<=n&&!ok;++i)
		for(int j=2;j<=m;++j)
			if(c[i][j]&c[n+1][j]&c[i][m+1]&c[n+1][m+1]){
				--ans;ok=1;break;
			}
	cout<<ans<<'\n';
	return 0;
}