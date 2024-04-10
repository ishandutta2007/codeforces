#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
const int N=100010,NN=N*40,inf=1000000000;
int n,m,num,tot;
PII q[N*2];
priority_queue<int,vector<int>,greater<int> > H1,H2;
int lc[NN],rc[NN],k1[NN],k2[NN];
void change(int &i,int l,int r,int ll,int rr,int a,int d)
{
	if (rr<l||r<ll||ll>rr) return;
	if (i==0) i=++num;
	if (ll<=l&&r<=rr)
	{
		k1[i]+=a+(l-ll)*d;
		k2[i]+=d;
		return;
	}
	int mid=(l+r)>>1;
	if (ll<=mid) change(lc[i],l,mid,ll,rr,a,d);
	if (rr> mid) change(rc[i],mid+1,r,ll,rr,a,d);
}
int query(int i,int l,int r,int k)
{
	if (i==0) return 0;
	if (l==r) return k1[i];
	int mid=(l+r)>>1;
	if (k<=mid) return query(lc[i],l,mid,k)+(k-l)*k2[i]+k1[i];
	if (k> mid) return query(rc[i],mid+1,r,k)+(k-l)*k2[i]+k1[i];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) 
	{
		int l,r,t;
		scanf("%d%d%d",&l,&r,&t);
		q[++tot]=MP(l,t+1);
		q[++tot]=MP(r,-t-1);
	}
	sort(q+1,q+1+tot);
	int last=q[1].FR;
	num=1;
	for (int i=1;i<=tot;)
	{
		while (!H2.empty()&&!H1.empty())
		if (H1.top()==H2.top()) H1.pop(),H2.pop();else break;
		
		if (!H1.empty())
		{
		int t=H1.top()-1,rt=1;
		change(rt,0,inf,t-q[i].FR,t-last,0,1);
		change(rt,0,inf,t-last+1,inf,q[i].FR-last,0);
		}

		last=q[i].FR;
		int j=i;
		while (q[i].FR==q[j].FR&&q[i].SC<0&&i<=tot) H2.push(-q[i].SC),i++;
		while (q[i].FR==q[j].FR&&q[i].SC>0&&i<=tot) H1.push( q[i].SC),i++;
	}
	while (n--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",query(1,0,inf,x));
	}
	return 0;
}