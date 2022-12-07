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
char s[101];
int now,cnt; 
int main()
{
	scanf("%s",&s);
	for(int i=0;i<strlen(s);i++)
	{
		if((int)s[i]!=now)
		{
			now=(int)s[i];
			cnt=1;
		}
		else
			cnt++;
		if(cnt==7)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}