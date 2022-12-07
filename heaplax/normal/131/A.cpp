#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
char s[100001],ch=true;
int main()
{
	scanf("%s",&s);
	for(int i=strlen(s)-1;i>=1;i--)
		if(!(s[i]>='A' && s[i]<='Z'))
			ch=false;
	if(ch)
		for(int i=0;i<strlen(s);i++)
		{
			if(s[i]>='a' && s[i]<='z')
				cout<<char(s[i]-32);
			else
				cout<<char(s[i]+32);
		}
	else
		printf("%s",s);
	return 0;
}