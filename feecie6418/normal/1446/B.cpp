#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,f[5005][5005],g[5005][5005];
char a[5005],b[5005];
int main(){
	cin>>n>>m>>a+1>>b+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//f[i][j]=f[i][j-1],g[i][j]=g[i][j-1]+1;
			//if(f[i-1][j]>f[i][j])f[i][j]=f[i-1][j],g[i][j]=g[i-1][j]+1;
			//else if(f[i-1][j]==f[i][j]&&g[i-1][j]+1<g[i][j])g[i][j]=g[i-1][j]+1;
			f[i][j]=max(f[i][j-1]-1,f[i-1][j]-1);
			f[i][j]=max(f[i][j],0);
			if(a[i]!=b[j])continue;
			//if(f[i-1][j-1]+1>f[i][j])f[i][j]=f[i-1][j-1]+1,g[i][j]=g[i-1][j-1]+2;
			//else if(f[i-1][j-1]+1==f[i][j]&&g[i-1][j-1]+2<g[i][j])g[i][j]=g[i-1][j-1]+2;
			f[i][j]=max(f[i][j],f[i-1][j-1]+2);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans=max(ans,f[i][j]-g[i][j]);
	cout<<ans;
    return 0;
}