#include<bits/stdc++.h>
using namespace std;
int n;
char s[105];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)	putchar(s[n]);
		puts("");
	}
	return 0;
}