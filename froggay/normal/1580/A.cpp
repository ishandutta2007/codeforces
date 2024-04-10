#include<bits/stdc++.h>
using namespace std;
#define N 405
typedef long long ll;
int n,m,A[N][N],B[N][N],a[N][N];
char s[N][N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>(s[i]+1);
		for(int j=1;j<=m;++j){
			a[i][j]=s[i][j]-'0';
		}
	}
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			B[i][j]=B[i-1][j]+a[i][j];
			A[i][j]=A[i-1][j]+!a[i][j];
		}
	}
	int ans=n*m;
	for(int i=2;i<n;++i){
		for(int j=i+2;j<n;++j){
			static int s[N],pre[N];
			pre[0]=n*m;
			for(int k=1;k<=m;++k){
				int w=B[j][k]-B[i-1][k]+!a[j+1][k]+!a[i-1][k];
				s[k]=s[k-1]+w;
				pre[k]=min(pre[k-1],A[j][k]-A[i-1][k]-s[k]);
			}
			for(int k=4;k<=m;++k){
				ans=min(ans,pre[k-3]+s[k-1]+A[j][k]-A[i-1][k]);	
			}
		}	
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}