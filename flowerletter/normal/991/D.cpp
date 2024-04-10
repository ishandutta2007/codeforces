#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5;

int n; 
char s[maxn+5]; 
int f[maxn+5][4],a[maxn+5][2]; 

int main() {
	for (int j=0;j<2;j++) {
		cin>>s+1; n=strlen(s+1); 
		for (int i=1;i<=n;i++) {
			a[i][j]=(s[i]=='X'); 
		}
	} 
	for (int i=0;i<4;i++) f[0][i]=-1e9;
	for (int i=0;i<4;i++) {
		int x=a[1][0]+(a[1][1]<<1); 
		if ((i&x)!=x) f[1][i]=-1e9;
		else f[1][i]=0; 
	}
	for (int i=2;i<=n;i++) {
		int mn=-1e9; 
		for (int j=0;j<4;j++) mn=max(mn,f[i-1][j]);
		for (int j=0;j<4;j++) f[i][j]=mn; 
		if (!a[i][0]&&!a[i][1]) {
			f[i][3]=max(f[i][3],max(f[i-1][0],max(f[i-1][1],f[i-1][2]))+1);
		}
		if (!a[i][0]) {
			if (a[i][1]) {
				f[i][3]=max(f[i][3],f[i-1][0]+1);
			}
			else {
				f[i][3]=max(f[i][3],f[i-1][0]+1); 
				f[i][1]=max(f[i][1],f[i-1][0]+1); 
			}
		} 
		if(!a[i][1]) {
			if (a[i][0]) {
				f[i][3]=max(f[i][3],f[i-1][0]+1); 
			} 
			else {
				f[i][2]=max(f[i][2],f[i-1][0]+1); 
				f[i][3]=max(f[i][3],f[i-1][0]+1); 
			}
		} 
	//	cout<<a[i][0]<<'\n'; 
		int x=a[i][0]+(a[i][1]<<1); 
		for (int j=0;j<4;j++) {
			if ((j&x)!=x) f[i][j]=-1e9;
			// cout<<f[i][j]<<' '; 
		}
	//	cout<<'\n'; 
	}
	int ans=0;
	for (int i=0;i<4;i++) ans=max(ans,f[n][i]);
	cout<<ans<<'\n'; 
	return 0; 
}