#include<iostream>
#include<cstdio>
#include<cstring>
#define N 300010
using namespace std;
char str[N];
int num[N][26];
int get_(int l,int r){int res=0;for(int _=0;_<26;_++) res+=(num[r][_]-num[l-1][_])>0;return res;}
int main()
{
	scanf("%s",str+1);
	int n=strlen(str+1),m;
	scanf("%d",&m);
	for(int i=1;i<=n;i++)
	{
		memcpy(num[i],num[i-1],sizeof(num[i-1]));
		num[i][str[i]-'a']++;
	}
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(get_(l,r)>=3) puts("Yes");
		else if(str[l]!=str[r] || l==r) puts("Yes");
		else puts("No");
	}
	return 0;
}