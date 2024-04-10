#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,cnt[72],f[72][530005],a[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67},lst=0;
int main(){
	cin>>n,f[0][0]=1;
	for(int i=1,x;i<=n;i++)cin>>x,cnt[x]++;
	for(int i=1;i<=70;i++){
		if(!cnt[i])continue;
		int now=0,tmp=i,u=1;
		for(int j=0;j<19;j++){
			int c=0;
			while(tmp%a[j]==0)tmp/=a[j],c++;
			if(c&1)now^=(1<<j);
		}
		for(int j=0;j<524288;j++)f[i][j]=(f[lst][j]+f[lst][j^now])%mod;
		for(int j=1;j<cnt[i];j++)u=(u<<1)%mod;
		for(int j=0;j<524288;j++)f[i][j]=1ll*u*f[i][j]%mod;
		lst=i;
	}
	cout<<f[lst][0]-1;
}