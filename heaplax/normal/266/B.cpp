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
int n,t;
char s[101],p[101];
int main()
{
	scanf("%d%d\n%s",&n,&t,&s);
	for(int i=1;i<=t;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(s[j]=='B' && s[j+1]=='G')p[j+1]='B';
			else if(s[j]=='G' && j>0 && s[j-1]=='B')p[j-1]='G';
			else p[j]=s[j];
		}
		for(int j=0;j<n;j++)
			s[j]=p[j];
	}
	for(int i=0;i<n;i++)
		printf("%c",s[i]);
	return 0;
}