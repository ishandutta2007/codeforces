#include<bits/stdc++.h>
using namespace std;
#define y1 DCXISSOHANDSOME

struct hhhh
{
	int x1,y1,x2,y2;
	hhhh() {}
	hhhh(int xx1,int yy1,int xx2,int yy2):x1(xx1),y1(yy1),x2(xx2),y2(yy2) {}
}h1[200010],h2[200010];

int len1[310][310],len2[310][310],n,m,t1,t2;
char *s1[310][310],*s2[310][310];
char s[100010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline void gao1()
{
	vector<int> v;
	v.clear();
	for (int i=len1[1][1];i;i--) v.push_back(s1[1][1][i]);
	t1=0;
	for (int i=2;i<=n;i++)
	{
		for (int j=len1[i][1];j;j--) v.push_back(s1[i][1][j]),h1[++t1]=hhhh(i,1,1,1);
	}
	for (int i=2;i<=m;i++)
	{
		for (int j=len1[1][i];j;j--) v.push_back(s1[1][i][j]),h1[++t1]=hhhh(1,i,1,1);
	}
	for (int i=2;i<=n;i++) for (int j=2;j<=m;j++)
	{
		for (int k=len1[i][j];k;k--)
		{
			if (s1[i][j][k]=='0')
			{
				h1[++t1]=(hhhh){i,j,i,1};
				if (i>2) h1[++t1]=(hhhh){i,1,2,1};
			}
			else
			{
				h1[++t1]=hhhh(i,j,1,j);
				if (j>2) h1[++t1]=hhhh(1,j,1,2);
			}
		}
	}
	for (int j=0;j<v.size();j++) if (v[j]=='0') h1[++t1]=hhhh(1,1,2,1);else h1[++t1]=hhhh(1,1,1,2);
}

inline void gao2()
{
	vector<int> v;
	v.clear();
	for (int i=1;i<=len2[1][1];i++) v.push_back(s2[1][1][i]);
	t2=0;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=len2[i][1];j++) v.push_back(s2[i][1][j]),h2[++t2]=hhhh(i,1,1,1);
	}
	for (int i=2;i<=m;i++)
	{
		for (int j=1;j<=len2[1][i];j++) v.push_back(s2[1][i][j]),h2[++t2]=hhhh(1,i,1,1);
	}
	for (int i=2;i<=n;i++) for (int j=2;j<=m;j++)
	{
		for (int k=1;k<=len2[i][j];k++)
		{
			if (s2[i][j][k]=='0')
			{
				h2[++t2]=(hhhh){i,j,i,1};
				if (i>2) h2[++t2]=(hhhh){i,1,2,1};
			}
			else
			{
				h2[++t2]=hhhh(i,j,1,j);
				if (j>2) h2[++t2]=hhhh(1,j,1,2);
			}
		}
	}
	for (int j=0;j<v.size();j++) if (v[j]=='0') h2[++t2]=hhhh(1,1,2,1);else h2[++t2]=hhhh(1,1,1,2);
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
	{
		scanf("%s",s+1);
		len1[i][j]=strlen(s+1);
		s1[i][j]=new char[len1[i][j]+2];
		for (int k=1;k<=len1[i][j];k++) s1[i][j][k]=s[k];
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
	{
		scanf("%s",s+1);
		len2[i][j]=strlen(s+1);
		s2[i][j]=new char[len2[i][j]+2];
		for (int k=1;k<=len2[i][j];k++) s2[i][j][k]=s[k];
	}
	gao1();gao2();
	print(t1+t2);putchar('\n');
	for (int i=1;i<=t1;i++) print(h1[i].x1),print(h1[i].y1),print(h1[i].x2),print(h1[i].y2),putchar('\n');
	for (int i=t2;i;i--) print(h2[i].x2),print(h2[i].y2),print(h2[i].x1),print(h2[i].y1),putchar('\n');
	return 0;
}