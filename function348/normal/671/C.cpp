#include<cstdio>
#include<iostream>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
struct Ques{int l,r,k;};
struct rec{int m1,c,m2,tag;LL sum;};
const int N=200010;
int n,tot;
PII l[N],r[N];
Ques c[N*3];
rec t[N*4];
void ins(int i,int x)
{
	if (x<l[i].FR) l[i].SC=l[i].FR,l[i].FR=x;else
	if (x<l[i].SC) l[i].SC=x;
	if (x>r[i].FR) r[i].SC=r[i].FR,r[i].FR=x;else
	if (x>r[i].SC) r[i].SC=x;
}
int cmp(Ques a,Ques b) { return a.r>b.r;}
void update(int i)
{
	int j=i*2,k=i*2+1;
	t[i].c=0;
	t[i].m1=min(t[j].m1,t[k].m1);
	t[i].m2=min(t[j].m2,t[k].m2);
	t[i].sum=t[j].sum+t[k].sum;

	if (t[i].m1==t[j].m1) t[i].c+=t[j].c;else t[i].m2=min(t[i].m2,t[j].m1);
	if (t[i].m1==t[k].m1) t[i].c+=t[k].c;else t[i].m2=min(t[i].m2,t[k].m1);
}
void down(int i)
{
	if (t[i].tag)
	{
		int x=t[i].tag;t[i].tag=0;
		int j=i*2,k=i*2+1,f1=0,f2=0;
		if (t[j].m1<=t[k].m1) f1=1;
		if (t[j].m1>=t[k].m1) f2=1;
		if (f1)
		{
			t[j].sum+=x*t[j].c;
			t[j].m1+=x;t[j].tag+=x;
		}
		if (f2)
		{
			t[k].sum+=x*t[k].c;
			t[k].m1+=x;t[k].tag+=x;
		}
	}
}
void change(int i,int l,int r,int ll,int rr,int k)
{
	if (k<=t[i].m1) return;
	int mid=(l+r)>>1;
	if (ll<=l&&r<=rr&&k<t[i].m2)
	{
		t[i].sum+=1LL*(k-t[i].m1)*t[i].c;
		t[i].tag+=k-t[i].m1;
		t[i].m1=k;
		return;
	}
	down(i);
	if (ll<=mid) change(i*2,l,mid,ll,rr,k);
	if (rr> mid) change(i*2+1,mid+1,r,ll,rr,k);
	update(i);
}
void build(int i,int l,int r)
{
	if (l==r)
	{
		t[i]=(rec){0,1,100000000,0,0};
		return;
	}
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	update(i);
}
LL query(int i,int l,int r,int ll,int rr)
{
	if (ll>rr) return 0;
	if (ll<=l&&r<=rr) return t[i].sum;
	down(i);
	int mid=(l+r)>>1;
	LL res=0;
	if (ll<=mid) res+=query(i*2,l,mid,ll,rr);
	if (rr> mid) res+=query(i*2+1,mid+1,r,ll,rr);
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=200000;i++) l[i]=MP(n+1,n+1);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		for (int j=1;j*j<=x;j++)
		if (x%j==0)
		{
			ins(j,i);
			if (j*j!=x) ins(x/j,i);
		}
	}
	tot=0;
	for (int i=1;i<=200000;i++)
	{
		if (l[i].FR+2<=r[i].FR) c[++tot]=(Ques){l[i].FR+1,r[i].FR-1,i};
		if (l[i].SC&&l[i].SC<n) c[++tot]=(Ques){l[i].SC+1,n,i};
		if (r[i].SC&&r[i].SC>1) c[++tot]=(Ques){1,r[i].SC-1,i};
	}
	sort(c+1,c+1+tot,cmp);
//	for (int i=1;i<=tot;i++) printf("%d %d %d\n",c[i].l,c[i].r,c[i].k);
	LL ans=0;
	build(1,1,n);
	for (int i=n,j=1;i>=1;i--)
	{
		while (j<=tot&&c[j].r==i) 
		{
			change(1,1,n,c[j].l,c[j].r,c[j].k);
			j++;
		}
		ans+=query(1,1,n,1,i);
	}
	printf("%lld\n",ans);
	return 0;
}