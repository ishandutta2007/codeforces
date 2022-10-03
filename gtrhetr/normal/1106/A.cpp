#include<bits/stdc++.h>
using namespace std;

int n,ans;
bool bo[510][510];
char s[510][510];

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
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) bo[i][j]=(s[i][j]=='X');
	ans=0;
	for (int i=2;i<n;i++) for (int j=2;j<n;j++) if (bo[i][j]&&bo[i-1][j-1]&&bo[i-1][j+1]&&bo[i+1][j-1]&&bo[i+1][j+1]) ans++;
	printf("%d\n",ans);
	return 0;
}