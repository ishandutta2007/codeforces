/*
 * Author: ylx
 * Lang: c++
 * Prog: 653A
 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void qmax(int &x,int y) {if (x<y) x=y;}
void qmin(int &x,int y) {if (x>y) x=y;}
inline int read()
{
	char s;
	int k=0,base=1;
	while ((s=getchar())!='-'&&s!=EOF&&!(isdigit(s)));
	if (s==EOF) exit(0);
	if (s=='-') base=-1,s=getchar();
	while (isdigit(s)) k=k*10+(s^'0'),s=getchar();
	return k*base;
}
inline void write(ll x)
{
	static char cnt,num[20];cnt=0;
	if (!x)
	{
		putchar('0');
		return;
	}
	for (;x;x/=10) num[++cnt]=x%10;
	for (;cnt;putchar(num[cnt--]+48));
}
const int N=60;
int a[N],n;
int cnt[2000];
int main()
{
#ifdef ylx
	freopen("653A.in","r",stdin);
	freopen("653A.out","w",stdout);
#endif
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),cnt[a[i]]++;
	for (int i=1;i<=1000;i++)
	{
		if (cnt[i]&&cnt[i+1]&&cnt[i+2])
		{
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
	return 0;
}
//2018 12 24  20:35:05 CST