#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int bl=2345;
struct query
{
	int l,r,k,t,key;
}b[100005];
inline bool cmp(query x,query y)
{
	return x.key<y.key;
}
int fr[100005],nx[100005],p[100005],a[100005],cnt[100005],cntcnt[100005],Cnt,ans[100005],op[100005],vis[100005];
vector <int> v;
inline void ins(int x)
{
	--cntcnt[cnt[x]];
	if(!vis[++cnt[x]])
		vis[cnt[x]]=1,v.push_back(cnt[x]);
	++cntcnt[cnt[x]];
}
inline void del(int x)
{
	--cntcnt[cnt[x]];
	if(!vis[--cnt[x]])
		vis[cnt[x]]=1,v.push_back(cnt[x]);
	++cntcnt[cnt[x]];
}
inline int query(int k)
{
	//cout << k << "  ";
	vector <int> V;
	for(auto t:v) if(t&&cntcnt[t]) V.push_back(t);else vis[t]=0;
	sort(V.begin(),V.end());
/*	for(int i=1;i<=13;i++) cout << cntcnt[i] << " ";
	for(int i=1;i<=13;i++) cout << cnt[i] << " ";
	puts("");
	for(auto t:V) cout << t << " ";
	puts("");*/
	int now=0,rtn=1e9,s=0;
	for(auto t:V)
	{
		s+=cntcnt[t];
		while(s-cntcnt[V[now]]>=k) s-=cntcnt[V[now++]];
		if(s>=k) rtn=min(rtn,t-V[now]);
	}
	swap(V,v);
	if(rtn>1e6) return -1;
	return rtn;
}
int main(int argc, char** argv) {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&op[i]);
		if(op[i]==1)
		{
			++Cnt,scanf("%d%d%d",&b[Cnt].l,&b[Cnt].r,&b[Cnt].k),b[Cnt].t=i;
			b[Cnt].key=b[Cnt].l/bl*10000000+b[Cnt].r/bl*100000+b[Cnt].t;
			//b[Cnt].key=b[Cnt].t;
		}
		if(op[i]==2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			p[i]=x,fr[i]=a[x],a[x]=y,nx[i]=y;
		}
	}
	sort(b+1,b+Cnt+1,cmp);
	int nowl=1,nowr=0,nowt=m;
	for(int i=1;i<=Cnt;i++)
	{
		while(nowt>b[i].t)
		{
			if(p[nowt]<=nowr&&p[nowt]>=nowl) ins(fr[nowt]),del(nx[nowt]);
			a[p[nowt]]=fr[nowt];
			nowt--;
		}
		while(nowt<b[i].t)
		{
			nowt++;
			a[p[nowt]]=nx[nowt];
			if(p[nowt]<=nowr&&p[nowt]>=nowl) del(fr[nowt]),ins(nx[nowt]);
		}
		while(nowr<b[i].r) ins(a[++nowr]);
		while(nowl>b[i].l) ins(a[--nowl]);
		while(nowr>b[i].r) del(a[nowr--]);
		while(nowl<b[i].l) del(a[nowl++]);
	//	cout << b[i].t << "***";
		ans[b[i].t]=query(b[i].k);
	}
	for(int i=1;i<=m;i++)
		if(op[i]==1) printf("%d\n",ans[i]);
	return 0;
}