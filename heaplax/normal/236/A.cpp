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
bool have[27];
int ans;
int main()
{	
	scanf("%s",&s);
	for(int i=0;i<strlen(s);i++)
		have[int(s[i]-96)]=true;
	for(int i=1;i<=26;i++)
		if(have[i])ans++;
	if(ans%2==0)printf("CHAT WITH HER!");
	else printf("IGNORE HIM!");
	return 0;
}