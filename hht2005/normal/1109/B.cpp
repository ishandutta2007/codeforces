#include<bits/stdc++.h>
using namespace std;
const int N=5010;
char s[N],t[N];
int main() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<n;i++) {
		for(int j=i+1;j<=n;j++)
			t[j-i]=s[j];
		for(int j=n-i+1;j<=n;j++)
			t[j]=s[j-n+i];
		int fl=0;
		for(int i=1;i<=n;i++)
			if(s[i]!=t[i])fl=1;
		if(!fl)continue;
		for(int i=1;2*i<=n;i++)
			if(t[i]!=t[n-i+1])fl=0;
		if(fl) {
			puts("1");
			return 0;
		}
	}
	int fl=0;
	for(int i=2;i<=n/2;i++)
		if(s[i]!=s[i-1])fl=1;
	if(fl)puts("2");
	else puts("Impossible");
	return 0;
}