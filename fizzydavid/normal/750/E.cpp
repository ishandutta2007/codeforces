//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int s[200111];
struct node
{
	int l,r;
	int dp[5][5];
	void init(int p)
	{
		l=r=p;
		for(int i=0;i<5;i++)for(int j=i;j<5;j++)dp[i][j]=(i==j?0:23333333);
		int t=s[p];
		if(t<4)
		{
			dp[t][t]=1;
			dp[t][t+1]=0;
		}
		else if(t==4)
		{
			dp[3][3]=dp[4][4]=1;
		}
	}
	void out()
	{
		#define tout(x) (x==23333333?-1:x)
		for(int i=0;i<5;i++)
		{
			for(int j=i;j<5;j++)
			{
				cout<<tout(dp[i][j])<<" ";
			}
			cout<<endl;
		}
	}
}a[800111];
node combine(const node &x,const node &y)
{
	node ret;
	ret.l=x.l;
	ret.r=y.r;
	for(int i=0;i<5;i++)
	{
		for(int j=i;j<5;j++)
		{
			ret.dp[i][j]=23333333;
			for(int k=i;k<=j;k++)
			{
				ret.dp[i][j]=min(ret.dp[i][j],x.dp[i][k]+y.dp[k][j]);
			}
		}
	}
	return ret;
}
#define ls p<<1
#define rs p<<1|1
void build(int l,int r,int p=1)
{
	if(l==r)
	{
		a[p].init(l);
	}
	else
	{
		int m=l+r>>1;
		build(l,m,ls);
		build(m+1,r,rs);
		a[p]=combine(a[ls],a[rs]);
	}
//	cout<<l<<","<<r<<":"<<endl;
//	a[p].out();
}
node query(int x,int y,int p=1)
{
	int l=a[p].l,r=a[p].r;
	if(x<=l&&r<=y)return a[p];
	int m=l+r>>1;
	if(x<=m&&m<y)return combine(query(x,y,ls),query(x,y,rs));
	else if(x<=m)return query(x,y,ls);
	else return query(x,y,rs);
}
int n,q;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		char c=getchar();
		while(c<'0'||c>'9')c=getchar();
//		cout<<c<<",";
		if(c=='6')c='4';
		else if(c!='2'&&c!='0'&&c!='1'&&c!='7')c='9';
		else if(c=='2')c='0';
		else if(c=='0')c='1';
		else if(c=='1')c='2';
		else if(c=='7')c='3';
		s[i]=c-'0';
//		cout<<c<<" ";
	}
//	for(int i=1;i<=n;i++)cout<<s[i];cout<<endl;
	build(1,n);
//	cout<<"---------------"<<endl;
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		node t=query(x,y);
//		t.out();
		if(t.dp[0][4]==23333333)puts("-1");
		else printf("%d\n",t.dp[0][4]);
	}
	return 0;
}