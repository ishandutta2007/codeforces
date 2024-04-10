#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll f[3005][3005];
int main() {
	cin>>n>>m;
	memset(f,0xc0,sizeof(f));
	f[0][0]=0;
	for(int i=1,x,o; i<=n; i++) {
		for(int j=0; j<=m; j++)f[i][j]=f[i-1][j];
		scanf("%d",&o);
		ll sum=0;
		for(int k=1; k<=o; k++) {
			scanf("%d",&x),sum+=x;
			for(int j=k; j<=m; j++) {
				f[i][j]=max(f[i][j],f[i-1][j-k]+sum);
			}
		}
	}
	cout<<f[n][m];
	return 0;
}