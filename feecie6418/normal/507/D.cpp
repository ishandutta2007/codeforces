#include<bits/stdc++.h>
using namespace std;
int f[1005][10][105][2],n,mod,m,ans=0;
int main() {
	cin>>n>>m>>mod;
	for(int i=1; i<=9; i++)f[1][i][i%m][!(i%m)]=1%mod;
	for(int i=2,w=10%m,t=w; i<=n; i++,t=t*w%m) {
		for(int j=0; j<=9; j++) {
			for(int k=0; k<=9; k++) {
				for(int l=0; l<m; l++) {
					int nw=(t*j+l)%m;
					if(nw) {
						f[i][j][nw][0]=(f[i][j][nw][0]+f[i-1][k][l][0])%mod;
						f[i][j][nw][1]=(f[i][j][nw][1]+f[i-1][k][l][1])%mod;
					} else {
						f[i][j][nw][1]=(f[i][j][nw][1]+f[i-1][k][l][0])%mod;
						f[i][j][nw][1]=(f[i][j][nw][1]+f[i-1][k][l][1])%mod;
					}
				}
			}
			if(!j)continue;
			int nw=t*j%m;
			if(nw) f[i][j][nw][0]=(f[i][j][nw][0]+1)%mod;
			else f[i][j][nw][1]=(f[i][j][nw][1]+1)%mod;
		}
	}
	for(int i=1; i<=9; i++) {
		for(int j=0; j<m; j++)ans=(ans+f[n][i][j][1])%mod;
	}
	cout<<ans;
}