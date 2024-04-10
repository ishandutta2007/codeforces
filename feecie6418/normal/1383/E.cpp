#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,f[1000005][2],ans=0,s[1000005],pos[1000005],nxt[1000005];
char a[1000005];
int main(){
	scanf("%s",a+1),n=strlen(a+1);
	for(int i=1;i<=n;i++){
		if(a[i]=='0')s[i]=s[i-1]+1;
		else s[i]=0;
	}
	for(int i=n;i>=0;i--)nxt[i]=pos[s[i]+1],pos[s[i]]=i;
	f[0][0]=1;
	for(int i=0,j=1;i<n;i++){
		int t=nxt[i];
		if(t)f[t][1]=(f[t][1]+f[i][1])%mod;
		if(t==i+1)f[t][0]=(f[t][0]+f[i][0])%mod;
		j=max(j,i+1);
		while(j<=n&&a[j]=='0')j++;
		if(j<=n){
			f[j][1]=(f[j][1]+f[i][0])%mod;
			f[j][1]=(f[j][1]+f[i][1])%mod;
		}
	}
	int u=0;
	for(int i=n;i>=1;i--)if(a[i]=='0')u++;else break;
	if(u==n){
		cout<<n;
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(a[i]=='1')ans=(ans+f[i][0])%mod,ans=(ans+f[i][1])%mod;
		if(a[i]=='0'&&s[i]<=u)ans=(ans+f[i][1])%mod;
	}
	cout<<ans;
}