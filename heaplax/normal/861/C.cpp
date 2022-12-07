#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
char s[3333];
int n;
bool mp[666],use[3333];
int main()
{
	mp['a']=mp['e']=mp['i']=mp['o']=mp['u']=1;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1,now=0,len=0;i<=n;++i)
	{
		if(mp[s[i]])now=len=0;
		else 
		{
			if(now==1 && !use[i-1] && s[i]==s[i-1])++len;
			else if(len>=2 || now>=2)
			{
				use[i-1]=1;
				putchar(' ');
				now=len=1;
			}
			else 
				++now,len=1;
		}
		putchar(s[i]);
	}
}