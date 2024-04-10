#include<bits/stdc++.h>
using namespace std;

int sum[100010],suf[100010],n;
char s[100010],s1[100010],s2[100010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]=='a');
	for (int i=n;i;i--) suf[i]=suf[i+1]+(s[i]=='a');
	int id=0;
	for (int i=1;i<=n;i++) if (!suf[i+1]&&i-sum[i]==n-i) { id=i;break; }
	if (!id) { puts(":(");return 0; }
	int h1=0,h2=0;
	bool flag=true;
	for (int i=1;i<=id;i++) if (s[i]!='a') s1[++h1]=s[i];
	for (int i=id+1;i<=n;i++) s2[++h2]=s[i];
	for (int i=1;i<=h1;i++) if (s1[i]!=s2[i]) flag=false;
	if (!flag) { puts(":(");return 0; }
	for (int i=1;i<=id;i++) putchar(s[i]);
	putchar('\n');
	return 0;
}