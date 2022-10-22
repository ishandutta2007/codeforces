#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6,mod=1e9+7; 

int n;char s[maxn+5]; 
int f[maxn+5][4][4],pw3[maxn+5]; 
//  i    j  

int add(int x,int y) {
	return (x+=y)>=mod?x-mod:x;
}
int main() {
	scanf("%d",&n); 
	scanf("%s",s+1);
	pw3[0]=1;
	for (int i=1;i<=n;i++) pw3[i]=1ll*pw3[i-1]*3%mod; 
	int all=0;
	for (int i=1;i<=n;i++) all+=(s[i]=='?'); 
	//for ()
	f[0][0][0]=1;
	for (int i=1;i<=n;i++) {
		if (s[i]=='?') {
			for (int j=0;j<=3;j++) {
				for (int k=0;k<=3;k++) {
					f[i][j][k]=f[i-1][j][k];
					if (j>=1&&k>=1) {
						f[i][j][k]=add(f[i][j][k],f[i-1][j-1][k-1]);
					}
				}
			}
		}
		else {
			int pos=s[i]-'a'+1;
			for (int j=0;j<=3;j++) {
				for (int k=0;k<=3;k++) {
					f[i][j][k]=add(f[i][j][k],f[i-1][j][k]); 
					if (j==pos) f[i][j][k]=add(f[i][j][k],f[i-1][j-1][k]); 
				}
			}
		}
	} 
	int ans=0; 
	for (int k=0;k<=3;k++) {
		ans=add(ans,1ll*f[n][3][k]*pw3[all-k]%mod); 
	}
	cout<<ans<<'\n'; 
	return 0; 
}