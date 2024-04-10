#include<bits/stdc++.h>
using namespace std;

int n,m;
char s1[1010],s2[1010];
bool bo[233];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	scanf("%s%s",s1+1,s2+1);
	n=strlen(s1+1);m=strlen(s2+1);
	if (n!=m) { puts("No");return 0; }
	bo['a'-'a']=bo['e'-'a']=bo['i'-'a']=bo['o'-'a']=bo['u'-'a']=true;
	bool flag=true;
	for (int i=1;i<=n;i++) if ((!bo[s1[i]-'a']&&bo[s2[i]-'a'])||(bo[s1[i]-'a']&&!bo[s2[i]-'a'])) flag=false;
	if (flag) puts("Yes");
	else puts("No");
	return 0;
}