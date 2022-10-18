#include <bits/stdc++.h>
const int mod = 1e9+7;
char s[1000005];
int main(){
	scanf("%s",s+1);
	int n = std::strlen(s+1);
	int suf = 0;
	int ans = 0;
	for(int i=n;i>=1;i--){
		if(s[i]=='b') suf=(suf+1)%mod;
		else {
			ans = (ans + suf) % mod;
			suf = (suf * 2) % mod;
		}
	}printf("%d",ans);
	return 0;
}