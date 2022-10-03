#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[510][510],b[510][510];
int n,m;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=rd();
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) b[i][j]=rd();
	for (int i=1;i<n;i++) for (int j=1;j<m;j++) if (a[i][j]!=b[i][j])
	{
		a[i][j]^=1;a[i][j+1]^=1;
		a[i+1][j]^=1;a[i+1][j+1]^=1;
	}
	bool flag=true;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (a[i][j]!=b[i][j]) flag=false;
	if (flag) puts("Yes");
	else puts("No");
	return 0;
}