#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,f[200005][3],a[200005],ans;
char str[200005];
signed main() {
	scanf("%lld%s",&n,str+1);
	for(int i=1,sum=1; i<=n; i++) {
		if(isalpha(str[i])) {
			memcpy(f[i],f[i-1],sizeof(f[i]));
			a[i]=str[i]-'a';
			if(a[i]==0)f[i][0]=(f[i][0]+sum)%mod;
			else f[i][a[i]]=(f[i][a[i]]+f[i-1][a[i]-1])%mod;
		} else {
			f[i][0]=(3ll*f[i-1][0]+sum)%mod;
			f[i][1]=(3ll*f[i-1][1]+f[i-1][0])%mod;
			f[i][2]=(3ll*f[i-1][2]+f[i-1][1])%mod;
			sum*=3;
			sum%=mod;
		}
		for(int j=0;j<3;j++)f[i][j]%=mod;
	}
	cout<<f[n][2]%mod;
}