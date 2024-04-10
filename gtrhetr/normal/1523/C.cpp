#include<bits/stdc++.h>
using namespace std;

int h[1010][1010],len[1010];
int num[1010],t,n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

bool bo[1010];

inline void work()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	h[1][len[1]=1]=1;
	printf("%d\n",1);
	memset(bo,true,sizeof(bo));
	for (int i=2;i<=n;i++)
	{
		int id=0;
		for (int j=i-1;j;j--) if (bo[j]&&num[i]==num[j]+1) { id=j;break; }
		if (id)
		{
			for (int j=id;j<i;j++) bo[j]=false;
			len[i]=len[id];
			for (int j=1;j<=len[i];j++) h[i][j]=h[id][j];h[i][len[i]]++;
		}
		else
		{
			len[i]=len[i-1]+1;
			for (int j=1;j<=len[i-1];j++) h[i][j]=h[i-1][j];h[i][len[i]]=1;
		}
		for (int j=1;j<=len[i];j++)
		{
			printf("%d",h[i][j]);
			putchar(j<len[i]?'.':'\n');
		}
	}
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}