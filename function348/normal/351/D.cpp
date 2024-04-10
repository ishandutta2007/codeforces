#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#define pb push_back
#define pf push_front
using namespace std;
const int N=100010;
struct Ques {int l,r,id;};
int n,bl,m,all,cnt;
int a[N];
Ques q[N];
deque<int> w[N];
deque<int> s[N];
int v[N],ans[N],ok[N];
int cmp(Ques a,Ques b) { return a.l/bl<b.l/bl||(a.l/bl==b.l/bl&&a.r<b.r);}
int main()
{
	scanf("%d",&n);
	bl=sqrt(n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&q[i].l,&q[i].r);
	for (int i=1;i<=m;i++) q[i].id=i;
	sort(q+1,q+1+m,cmp);
	int l=1,r=0;
	for (int i=1;i<=m;i++)
	{
		while (r<q[i].r) 
		{
			r++,v[a[r]]++,cnt+=v[a[r]]==1;
			int p=a[r];
			all-=ok[p]==0&&!s[p].empty();
			if (s[p].size()>0) 
			{
				if (!w[p].empty()) ok[p]+=(r-s[p].back())!=w[p].back();
				w[p].pb(r-s[p].back());
//				printf("IR:%d %d\n",p,r-s[p].back());
			}
			s[p].pb(r);
			all+=ok[p]==0&&!s[p].empty();
		}
		while (q[i].l<l)
		{
			l--,v[a[l]]++,cnt+=v[a[l]]==1;
			int p=a[l];
			all-=ok[p]==0&&!s[p].empty();
			if (s[p].size()>0) 
			{
				if (!w[p].empty()) ok[p]+=(s[p].front()-l)!=w[p].front();
				w[p].pf(s[p].front()-l);
//				printf("IL:%d %d\n",p,s[p].front()-l);
			}
			s[p].pf(l);
			all+=ok[p]==0&&!s[p].empty();
		}
		while (l<q[i].l)
		{
			v[a[l]]--,cnt-=v[a[l]]==0;
			int p=a[l];
			all-=ok[p]==0&&!s[p].empty();
			s[p].pop_front();
			if (s[p].size()>0) 
			{
				int tmp=s[p].front()-l;
				w[p].pop_front();
				if (!w[p].empty()) ok[p]-=tmp!=w[p].front();
//				printf("DL:%d %d\n",p,s[p].front()-l);
			}
			all+=ok[p]==0&&!s[p].empty();
			l++;
		}
		while (q[i].r<r)
		{
			v[a[r]]--,cnt-=v[a[r]]==0;
			int p=a[r];
			all-=ok[p]==0&&!s[p].empty();
			s[p].pop_back();
			if (s[p].size()>0) 
			{
//				printf("DR:%d %d\n",p,r-s[p].back());
				int tmp=r-s[p].back();
				w[p].pop_back();
				if (!w[p].empty()) ok[p]-=tmp!=w[p].back();
			}
			all+=ok[p]==0&&!s[p].empty();
			r--;
		}
		ans[q[i].id]=cnt+(all==0);
//		printf("%d %d %d\n",q[i].id,ans[q[i].id],all);
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}