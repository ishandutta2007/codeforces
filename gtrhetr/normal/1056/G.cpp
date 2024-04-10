#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll t;
int h[100010],id[100010],n,m,s;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int gao(int x,int y)
{
	if (x<=m) x+=y;
	else x-=y;
	if (x<=0) x+=n;
	if (x>n) x-=n;
	return x;
}

int main()
{
	n=rd();m=rd();s=rd();t=rd();
	while (t%n!=0) s=gao(s,t%n),t--;
	h[s]=1;id[1]=s;
	for (int i=2;t>=n;i++)
	{
		for (int j=n;j;j--) s=gao(s,j);
		t-=n;
		if (h[s]) { printf("%d\n",id[(t/n)%(i-h[s])+h[s]]);return 0; }
		h[s]=i;id[i]=s;
	}
	while (t) s=gao(s,t%n),t--;
	printf("%d\n",s);
	return 0;
}