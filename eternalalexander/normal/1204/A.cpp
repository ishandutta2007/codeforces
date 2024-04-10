#include <bits/stdc++.h>
char s[1000];
int main(){
	scanf("%s",s+1);
	int n=std::strlen(s+1),flag=0;
	if (n%2==0)flag=1;
	for (int i=2;i<=n;++i){if (s[i]=='1')flag=1;}
	printf("%d",(n-1)/2+flag);
	return 0;
}