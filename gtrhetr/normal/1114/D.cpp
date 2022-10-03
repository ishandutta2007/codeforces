#include<bits/stdc++.h>
using namespace std;

int f[5010][5010],num[5010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	n=unique(num+1,num+n+1)-num-1;
	for (int len=2;len<=n;len++) for (int i=1;i+len-1<=n;i++)
	{
		int j=i+len-1;
		if (num[i]==num[j]) f[i][j]=f[i+1][j-1]+1;
		else f[i][j]=min(f[i][j-1],f[i+1][j])+1;
	}
	printf("%d\n",f[1][n]);
	return 0;
}