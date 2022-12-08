#include<bits/stdc++.h>
using namespace std;///scs
const int maxn=200010,mod=1e9+7;
char s[maxn];
int main() {
	int o=1,a=0,ab=0,abc=0,n;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) {
		if(s[i]=='a')a=(a+o)%mod;
		if(s[i]=='b')ab=(ab+a)%mod;
		if(s[i]=='c')abc=(abc+ab)%mod;
		if(s[i]=='?') {
			abc=(3ll*abc+ab)%mod;
			ab=(3ll*ab+a)%mod;
			a=(3ll*a+o)%mod;
			o=o*3ll%mod;
		}
	}
	printf("%d\n",abc);
	return 0;
}