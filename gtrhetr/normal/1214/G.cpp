#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define y1 DCXISSOHANDSOME

set<pii> st;
set<int> ans;

bitset<2010> bs[2010],num[2010];

int n,m,q;
bool bo[2010];

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
	if (x<0) putchar('-'),x=-x;
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

int main()
{
	n=rd();m=rd();q=rd();
	for (int i=1;i<=m;i++) num[i]=num[i-1],num[i][i]=1;
	for (int i=1;i<=m;i++) bs[n+1][i]=1;
	for (int i=0;i<=n+1;i++) st.insert(pii(bs[i].count(),i));
	while (q--)
	{
		int x=rd(),l=rd(),r=rd();
		set<pii>::iterator it=st.find(pii(bs[x].count(),x)),it1=it,it2=it;
		it1--;it2++;
		int h1=it1->second,h2=it2->second;
		if (bo[x]) ans.erase(x),bo[x]=false;
		if (bo[h2]) ans.erase(h2),bo[h2]=false;
		if ((bs[h1]&bs[h2])!=bs[h1]) ans.insert(h2),bo[h2]=true;
		st.erase(it);
		bs[x]^=((num[r]>>l)<<l);
		pii hh=pii(bs[x].count(),x);
		it2=st.upper_bound(hh);it1=it2;it1--;
		h1=it1->second,h2=it2->second;
		if (bo[h2]) ans.erase(h2),bo[h2]=false;
		if ((bs[x]&bs[h1])!=bs[h1]) ans.insert(x),bo[x]=true;
		if ((bs[h2]&bs[x])!=bs[x]) ans.insert(h2),bo[h2]=true;
		st.insert(hh);
		if (ans.empty()) { print(-1);putchar('\n');continue; }
		int now=*ans.begin();
		it=st.find(pii(bs[now].count(),now));it--;
		int now1=it->second;
		if (now>now1) swap(now,now1);
		int y1=(bs[now]^(bs[now]&bs[now1]))._Find_first(),y2=(bs[now1]^(bs[now]&bs[now1]))._Find_first();
		if (y1>y2) swap(y1,y2);
		print(now);print(y1);print(now1);print(y2);
		putchar('\n');
	}
	return 0;
}