#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,s[1000005],f[1000005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j+=i)f[j]++;
	for(int i=1;i<=n;i++)f[i]=(f[i]+s[i-1])%mod,s[i]=(s[i-1]+f[i])%mod;
	cout<<f[n]%mod;
}