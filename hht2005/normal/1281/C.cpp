#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
char s[1000010];
int main() {
	int T,len,x;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%s",&x,s+1);
		len=strlen(s+1);
		int f=0;
		for(int i=1;i<=x;i++) {
			if(f==1)len=(len+1ll*(s[i]-'1')*(len-i+mod))%mod;
			else {
				int t=len+1ll*(s[i]-'1')*(len-i);
				for(int j=len+1;j<=t&&j<=x;j++)s[j]=s[j-len+i];
				if(t>=x)f=1;
				len=t;
			}
		}
		printf("%d\n",len);
	}
	return 0;
}