// i->j->k  S->i  i->T  i 
// i  C  i->T  
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p[10005],s[10005];
ll C,f[2][10005],ans=1e18;
int main(){
	cin>>n>>C;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)cin>>s[i];
	memset(f[0],0x3f,sizeof(f[0])),f[0][0]=0;
	for(int i=1;i<=n;i++){
		int I=i&1,J=I^1;
		memset(f[I],0x3f,sizeof(f[I]));
		for(int j=0;j<=i;j++){
			if(j)f[I][j]=min(f[I][j],f[J][j-1]+s[i]);
			f[I][j]=min(f[I][j],f[J][j]+p[i]+C*j);
		}
	}
	for(int j=0;j<=n;j++)ans=min(ans,f[n&1][j]);
	cout<<ans;
}