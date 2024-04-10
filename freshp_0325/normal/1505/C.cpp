#include<bits/stdc++.h>
using namespace std;
char s[15];
int a[15];
int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;++i)	a[i]=s[i]-'A';
	for(int i=1;i<=len-2;++i)	if(a[i+2]!=(a[i]+a[i+1])%26)	return puts("NO")&0;
	puts("YES");
	return 0;
}