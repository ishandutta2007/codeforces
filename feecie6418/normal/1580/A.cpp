#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
int n,m,s[505][505],sum[505],s1[505],s2[505];
char a[505][505];
int Get(int x1,int y1,int x2,int y2){
	return s[x2][y2]+s[x1-1][y1-1]-s[x1-1][y2]-s[x2][y1-1];
}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
		for(int j=1;j<=m;j++)s[i][j]=s[i-1][j]+s[i][j-1]+a[i][j]-'0'-s[i-1][j-1];
	}
	int ans=1e9;
	for(int i=1;i<=n;i++){
		for(int j=i+4;j<=n;j++){
			int mn=1e9;
			for(int k=1;k<=m;k++)sum[k]=Get(i+1,1,j-1,k),s1[k]=Get(i,1,i,k)+Get(j,1,j,k);
			for(int k=4;k<=m;k++){
				int l=k-3;
				mn=min(mn,-sum[l]-l-l+s1[l]-Get(i+1,l,j-1,l));
				ans=min(ans,sum[k-1]+k-1-s1[k-1]+k-1-Get(i+1,k,j-1,k)+2*(j-i-1)+mn);
			}
		}
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)s[i][j]=a[i][j]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}