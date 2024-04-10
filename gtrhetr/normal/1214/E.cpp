#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

vector<int> v[200010];

pii d[100010],ans[200010];

int nxt[200010],h[200010],n,tt,tot;

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
	for (int i=1;i<=n;i++) d[i].first=rd(),d[i].second=i;
	sort(d+1,d+n+1);reverse(d+1,d+n+1);
	tt=0;
	int lst=d[1].second*2-1,fir=lst,lst1=d[1].second*2,rest=d[1].first-1;
	int id=n+1;
	int now=d[1].first+1;
	for (int i=2;i<=n;i++)
	{
		if (!rest) { id=i;break; }
		if (i+d[i].first>now)
		{
			now=i+d[i].first;
			nxt[lst]=d[i].second*2-1;
			nxt[lst1]=d[i].second*2;
			lst=nxt[lst];lst1=nxt[lst1];
			rest--;
		}
		else
		{
			rest--;
			nxt[lst]=d[i].second*2-1;lst=nxt[lst];
			v[i+d[i].first-1].push_back(d[i].second*2);
		}
	}
	nxt[lst]=d[1].second*2;
	tt=0;
	for (int i=fir;i;i=nxt[i]) h[++tt]=i;
	tot=0;
	for (int i=1;i<tt;i++) ans[++tot]=pii(h[i],h[i+1]);
	for (int i=1;i<=tt;i++) for (int t:v[i]) ans[++tot]=pii(h[i],t);
	for (int i=id;i<=n;i++)
	{
		if (d[i].first==1) ans[++tot]=pii(h[1],d[i].second*2-1),ans[++tot]=pii(d[i].second*2-1,d[i].second*2);
		else ans[++tot]=pii(h[1],d[i].second*2-1),ans[++tot]=pii(h[1+d[i].first-2],d[i].second*2);
	}
	for (int i=1;i<=tot;i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}