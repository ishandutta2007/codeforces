#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
char s[200010],t[200010];

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

int main()
{
	n=rd();m=rd();
	scanf("%s",s+1);
	scanf("%s",t+1);
	int id=0;
	for (int i=1;i<=n;i++) if (s[i]=='*') id=i;
	if (id==0)
	{
		if (n!=m) { puts("NO");return 0; }
		bool flag=true;
		for (int i=1;i<=n;i++) if (s[i]!=t[i]) flag=false;
		if (flag) puts("YES");
		else puts("NO");
		return 0;
	}
	if (n>m+1) { puts("NO");return 0; }
	bool flag=true;
	for (int i=1;i<id;i++) if (s[i]!=t[i]) flag=false;
	for (int i=0;i<n-id;i++) if (s[n-i]!=t[m-i]) flag=false;
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}