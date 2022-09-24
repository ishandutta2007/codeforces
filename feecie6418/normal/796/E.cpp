#include<bits/stdc++.h>
using namespace std;
int s1[1005],s2[1005],s[1005],S[1005],n,p,m,n1,n2;
void upd(short &x,short y){
	x=max(x,y);
}
int main(){
	cin>>n>>p>>m>>n1;
	for(int i=1,x;i<=n1;i++)cin>>x,s1[x]++;
	cin>>n2;
	for(int i=1,x;i<=n2;i++)cin>>x,s2[x]++;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+(S[i]=s1[i]|s2[i]);
	if(p>(n+m-1)/m*2)return cout<<s[n],0;
	vector<vector<vector<short>>> f[2];
	for(int o=0;o<2;o++){
		f[o].resize(n+2);
		for(int i=0;i<=n+1;i++){
			f[o][i].resize(m+2);
			for(int j=0;j<=m;j++){
				f[o][i][j].resize(p+2);
			}
		}
	}
	short ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i&&j<=p;j++){
			upd(f[0][i][0][j],f[1][i][0][j]);
			upd(f[1][i][0][j],f[0][i][0][j]);
			for(int k=0;k<=m;k++){
				if(k)f[0][i][k][j]+=s1[i],f[1][i][k][j]+=s2[i];
				upd(f[0][i+1][max(k-1,0)][j],f[0][i][k][j]);
				upd(f[1][i+1][max(k-1,0)][j],f[1][i][k][j]);
				upd(f[1][min(i+k,n)][m-k][j+1],f[0][i][k][j]+s[min(i+k,n)-1]-s[i]+((!s1[i]||!k)&&S[i]));
				upd(f[0][min(i+k,n)][m-k][j+1],f[1][i][k][j]+s[min(i+k,n)-1]-s[i]+((!s2[i]||!k)&&S[i]));
				ans=max(ans,f[0][i][k][j]);
				ans=max(ans,f[1][i][k][j]);
			}
		}
	}
	cout<<ans;
}