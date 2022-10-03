#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

int num[1000010],h[1000010],res[1000010],n,m,tt;

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

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++) num[i]=rd();
	h[tt=1]=n;
	int sum=0;
	for (int i=1;i<m;i++) sum+=num[i],h[++tt]=sum%n;
	sort(h+1,h+tt+1);
	for (int i=1;i<=m;i++) res[i]=h[i]-h[i-1];
	int now=1;
	for (int i=1;i<=m;i++) while (num[i]>0)
	{
		num[i]-=res[now];
		ans.push_back(i);
		now++;(now>m)?(now-=m):0;
	}
	while (ans.size()%m!=0) ans.push_back(1);
	print(ans.size()/m);putchar('\n');
	for (int i=1;i<=m;i++) print(res[i]);putchar('\n');
	for (int i=0;i<ans.size();i++) print(ans[i]),(((i+1)%m==0)?putchar('\n'):0);
	return 0;
}