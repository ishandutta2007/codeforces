#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c;int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
int a[400005];
struct node
{
	int lmax,rmax,lmin,rmin,sum,linf,rinf,finf,ans;
	void update(node ls,node rs)
	{
		lmax=max(ls.lmax,ls.sum+rs.lmax);
		rmax=max(rs.rmax,rs.sum+ls.rmax);
		lmin=min(ls.lmin,ls.sum+rs.lmin);
		rmin=min(rs.rmin,rs.sum+ls.rmin);
		sum=ls.sum+rs.sum;
		linf=max(ls.linf,max(rs.linf-ls.sum,ls.finf+rs.lmax));
		rinf=max(rs.rinf,max(ls.rinf+rs.sum,rs.finf-ls.rmin));
		finf=max(ls.finf+rs.sum,rs.finf-ls.sum);
		ans=max(ls.ans,max(rs.ans,max(ls.rinf+rs.lmax,rs.linf-ls.rmin)));
	}
}e[1000005];
void build(int k,int l,int r)
{
	if(l==r)
	{
		e[k].sum=a[l];
		e[k].rmin=min(0,a[l]);
		e[k].rmax=max(0,a[l]);
		e[k].lmin=min(0,a[l]);
		e[k].lmax=max(0,a[l]);
		e[k].finf=e[k].linf=e[k].rinf=1;
		e[k].ans=1;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	e[k].update(e[k<<1],e[k<<1|1]);
//	cout<<k<<" "<<e[k].sum<<" "<<e[k].lmax<<" "<<e[k].rmax<<" "<<e[k].lmin<<" "<<e[k].rmin<<" "<<e[k].linf<<" "<<e[k].rinf<<" "<<e[k].finf<<" "<<e[k].ans<<endl;;
}
void change(int k,int l,int r,int to)
{
	if(l==r)
	{
		a[l]=-a[l];
		e[k].sum=a[l];
		e[k].rmin=min(0,a[l]);
		e[k].rmax=max(0,a[l]);
		e[k].lmin=min(0,a[l]);
		e[k].lmax=max(0,a[l]);
		e[k].finf=e[k].linf=e[k].rinf=1;
		e[k].ans=1;
		return;
	}
	int mid=l+r>>1;
	if(to<=mid)change(k<<1,l,mid,to);
	else change(k<<1|1,mid+1,r,to);
	e[k].update(e[k<<1],e[k<<1|1]);
}
int main(){
//	freopen("a.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=2*(n-1);i++)
	{
		char c;
		while(((c=getchar())!='(')&&(c!=')'));
		if(c=='(')
		a[i]=1;
		else a[i]=-1;
	}
	build(1,1,2*(n-1));
	printf("%d\n",e[1].ans);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		x=read();
		y=read();
		if(a[x]!=a[y])
		{
			change(1,1,2*(n-1),x);
			change(1,1,2*(n-1),y);
		}
		printf("%d\n",e[1].ans);
//		for(int i=1;i<=2*(n-1);i++)
//		{
//			if(a[i]==1)
//			{
//				cout<<"(";
//			}
//			else cout<<")";
//		}
//		cout<<endl;
//		for(int i=1;i<=2*(n-1);i++)
//		{
//			if(i==x)
//			{
//				cout<<"L";
//			}
//			else if(i==y)
//			{
//				cout<<"R";
//			}
//			else cout<<" ";
//		}
//		cout<<endl;
	}
	return 0;
}