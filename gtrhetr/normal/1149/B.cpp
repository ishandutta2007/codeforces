#include<bits/stdc++.h>
using namespace std;
#define inf 1061109567

int ch1[1010][26],ch2[1010][26],ch3[1010][26],fa1[1010],fa2[1010],fa3[1010],tot1,tot2,tot3;
int mn[100010][26],num1[1010],num2[1010],num3[1010];
int *f[1010][1010],id1[1010],id2[1010],id3[1010],n,m,now1,now2,now3;
char s[100010],t[100010];

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline void add1(char ch)
{
	int hh=ch-'a';
	if (!ch1[now1][hh]) ch1[now1][hh]=++tot1,fa1[tot1]=now1,num1[tot1]=hh;
	now1=ch1[now1][hh];
}

inline void add2(char ch)
{
	int hh=ch-'a';
	if (!ch2[now2][hh]) ch2[now2][hh]=++tot2,fa2[tot2]=now2,num2[tot2]=hh;
	now2=ch2[now2][hh];
}

inline void add3(char ch)
{
	int hh=ch-'a';
	if (!ch3[now3][hh]) ch3[now3][hh]=++tot3,fa3[tot3]=now3,num3[tot3]=hh;
	now3=ch3[now3][hh];
}

int main()
{
	n=rd();m=rd();
	scanf("%s",s+1);
	tot1=tot2=tot3=0;
	now1=0,now2=0,now3=0;
	memset(mn,0x3f,sizeof(mn));
	for (int i=n;i;i--)
	{
		memcpy(mn[i],mn[i+1],sizeof(mn[i]));
		mn[i][s[i]-'a']=i;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%s",s+1);
		int x=rd();
		if (s[1]=='+')
		{
			scanf("%s",t+1);
			if (x==1) add1(t[1]);
			else if (x==2) add2(t[1]);
			else add3(t[1]);
		}
		else
		{
			if (x==1) now1=fa1[now1];
			else if (x==2) now2=fa2[now2];
			else now3=fa3[now3];
		}
		id1[i]=now1;id2[i]=now2;id3[i]=now3;
	}
	for (int i=0;i<=tot1;i++) for (int j=0;j<=tot2;j++)
	{
		f[i][j]=new int[tot3+1];
		memset(f[i][j],0x3f,sizeof(int)*(tot3+1));
	}
	f[0][0][0]=0;
	for (int i=0;i<=tot1;i++) for (int j=0;j<=tot2;j++) for (int k=0;k<=tot3;k++)
	{
		if (i>0)
		{
			if (f[fa1[i]][j][k]<n) f[i][j][k]=min(f[i][j][k],mn[f[fa1[i]][j][k]+1][num1[i]]);
		}
		if (j>0)
		{
			if (f[i][fa2[j]][k]<n) f[i][j][k]=min(f[i][j][k],mn[f[i][fa2[j]][k]+1][num2[j]]);
		}
		if (k>0)
		{
			if (f[i][j][fa3[k]]<n) f[i][j][k]=min(f[i][j][k],mn[f[i][j][fa3[k]]+1][num3[k]]);
		}
	}
	for (int i=1;i<=m;i++) if (f[id1[i]][id2[i]][id3[i]]<=n) puts("YES");else puts("NO");
	return 0;
}