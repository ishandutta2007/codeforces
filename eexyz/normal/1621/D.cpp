#include<bits/stdc++.h>
using namespace std;
#define N 505
#define int long long
int T,n,i,j,res,ans,ii,k,r,f0[N][N],t[N],tt[N],a[N][N],b[N][N],f1[N][N],f2[N][N],f3[N][N];
main(){
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(i=1;i<=n+n;++i)for(j=1;j<=n+n;++j)cin>>a[i][j];
		for(i=1;i<=n;++i)for(j=1;j<=n;++j)ans+=a[i+n][j+n],a[i+n][j+n]=0;
		ans+=min(min(min(a[n+1][n],a[n][n+1]),
					min(a[n+n][n],a[n][n+n])),
					min(min(a[n+1][1],a[1][n+1]),
					min(a[n+n][1],a[1][n+n]))) ;
		cout<<ans<<"\n";
	}
}