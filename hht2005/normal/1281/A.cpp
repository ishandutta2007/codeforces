#include<bits/stdc++.h>
using namespace std;
char s[50];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%s",s+1);
		int n=strlen(s+1);
		if(s[n]=='o')puts("FILIPINO");
		if(s[n]=='u')puts("JAPANESE");
		if(s[n]=='a')puts("KOREAN");
	}
	return 0;
}