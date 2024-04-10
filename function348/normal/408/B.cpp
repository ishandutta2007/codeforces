#include<iostream>
#include<cstdio>
#include<cstring>
int main()
{
	int a[28],b[28],tot=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	char s1[1010],s2[1010];
	scanf("%s\n",s1);int n=strlen(s1);
	scanf("%s'n",s2);int m=strlen(s2);
	for (int i=0;i<n;i++) a[s1[i]-'a']++;
	for (int i=0;i<m;i++) b[s2[i]-'a']++;
	for (int i=0;i<28;i++) tot+= a[i]<b[i]?a[i]:b[i];
	for (int i=0;i<28;i++) if (a[i]==0&&b[i]!=0) tot=-1;
	printf("%d",tot);
}