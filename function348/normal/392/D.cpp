#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
const int N=100010;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef set<PII>::iterator SETI;
int n,num,ans;
PIII a[N*3];
PIII b[N*3];
set<PII> S1;
multiset<int> S2;
/*
void change(int i,int l,int r,int ll,int rr,int d)
{
	if (ll<=l&&r<=rr)
	{
		tag[i]=max(tag[i],d);
		t[i]=max(t[i],tag[i]+r);
		return;
	}
	int mid=(l+r)>>1;
	if (ll<=mid) change(i*2,l,mid,ll,rr,d);
	if (rr> mid) change(i*2+1,mid+1,r,ll,rr,d);
	t[i]=max(t[i*2],t[i*2+1]);
	t[i]=max(t[i],tag[i]+r);
}
void build(int i,int l,int r)
{
	tag[i]=0;t[i]=r;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
}
*/
int main()
{
	scanf("%d",&n);
	for (int j=1;j<=3;j++)
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[++num]=MP(x,MP(j,i));
	}
	sort(a+1,a+1+n*3);
	num=0;
	for (int i=1;i<=n*3;)
	{
		int j=i,k1=n*3+1,k2=n*3+1,k3=n*3+1;
		while (a[j].FR==a[i].FR&&j<=n*3) 
		{
			int x=a[j].SC.FR,y=a[j].SC.SC;
			if (x==1) k1=min(k1,y);
			if (x==2) k2=min(k2,y);
			if (x==3) k3=min(k3,y);
			j++;
		}
		b[++num]=MP(k1,MP(k2,k3));
		i=j;
	}
	sort(b+1,b+1+num);
	ans=n*3;
	S1.insert(MP(0,0));
	S2.insert(0);
	for (int i=num;i>=1;i--)
	{
	//	printf("%d %d %d %d\n",i,b[i].FR,b[i].SC.FR,b[i].SC.SC);
		int now=b[i].FR+(*S2.begin());
	//	printf("%d\n",now);
	//	printf("%d\n",S2.size());
		ans=min(ans,now);
		int x=b[i].SC.FR,y=b[i].SC.SC;
		PII k1=MP(-1,-1),k2=MP(-1,-1);
		while (1)
		{
			SETI it=S1.upper_bound(MP(x,y));
			if (it==S1.begin()) break;
			it--;
			if ((*it).SC>y) break;
			S1.erase(it);
			S2.erase(S2.find((*it).FR+(*it).SC));
			if (k2.FR==-1) k2=MP(x,(*it).SC);
			k1=MP((*it).FR,y);
		}
		if (k1.FR!=-1) S1.insert(k1),S2.insert(k1.FR+k1.SC);
		if (k2.FR!=-1) S1.insert(k2),S2.insert(k2.FR+k2.SC);
	}
	ans=min(ans,(*S2.begin()));
	printf("%d\n",ans);
	return 0;
}