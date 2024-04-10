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
int n,ans=0;
char s[51];
int main()
{
	scanf("%d\n%s",&n,&s);
	for(int i=0;i<n;i++)
		ans+=((s[i]==s[i-1])?1:0);
	printf("%d\n",ans);
}