#include<bits/stdc++.h>
using namespace std;
char s[11];
int main()
{
	scanf("%s",s);
	int t=strlen(s)-1;
	while(s[t]=='0')
		t--;
	int ss=0;
	while(ss<t)
	{
		if(s[ss]!=s[t])
		{
			puts("NO");
			return 0;
		}
		ss++,t--;
	}
	puts("YES");
	return 0;
}