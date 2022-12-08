#include<bits/stdc++.h>
using namespace std;
char s[110],t[110];
int main() {
	scanf("%s",s+1);
	int cnt=0,n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]!='/'||s[i-1]!='/')t[++cnt]=s[i];
	if(cnt!=1&&t[cnt]=='/')t[cnt]='\0';
	printf("%s\n",t+1);
	return 0;
}