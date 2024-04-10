#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
int a[8000005];
struct node
{
	int sum,l,r;
}e[8000005];
int cst;
int root[8000005];
void insert(int &x,int l,int r,int v)
{
	if(!x)x=++cst;
	e[x].sum++;
	if(l==r)return;
	int mid=l+r>>1;
	if(v<=mid)insert(e[x].l,l,mid,v);
	else insert(e[x].r,mid+1,r,v);
}
void merge(int &x,int &y,int l,int r)
{
	if(!y)return;
	if(!x)return x=y,void();
	e[x].sum+=e[y].sum;
	if(l==r)return;
	int mid=l+r>>1;
	merge(e[x].l,e[y].l,l,mid);
	merge(e[x].r,e[y].r,mid+1,r);
	e[x].sum=e[e[x].l].sum+e[e[x].r].sum;
}
int ask(int &x,int &y,int l,int r,int p,int q)
{
//	cout<<l<<" "<<r<<endl;
//	cout<<"qwqq"<<endl;
	if(r<p)return 0;
	if(q<l)return 0;
//	cout<<x<<" "<<y<<" "<<l<<" "<<r<<"QQQ"<<" "<<p<<" "<<q<<" "<<e[x].sum<<endl;
	if(!x||!e[x].sum)return 0;
	if(p<=l&&r<=q)
	{
//		cout<<x<<"QQQ"<<endl;
		int p=e[x].sum;
		merge(y,x,l,r);x=0;
		return p;
	}
	if(!y)y=++cst;
	int mid=l+r>>1;
	int res=ask(e[x].l,e[y].l,l,mid,p,q)+ask(e[x].r,e[y].r,mid+1,r,p,q);
	e[x].sum-=res;e[y].sum+=res;
	return res;
}
int res=0;
void check(int k,int l,int r,int v)
{
//	if(v==4)cout<<k<<' '<<l<<" "<<r<<" "<<e[k].sum<<endl;
	if(!k)return;
	if(l==r)
	{
		if(e[k].sum)res=1;
		return;
	}
	int mid=l+r>>1;
	if(v<=mid)check(e[k].l,l,mid,v);
	else check(e[k].r,mid+1,r,v);
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		int s=read();
		insert(root[s],1,n,i);
	}
	int q;q=read();
	for(int i=1;i<=q;i++)
	{
		int l,r,x,y;
		l=read();r=read();x=read();y=read();
		if(x==y)continue;
//		cout<<x<<" "<<y<<endl;
		ask(root[x],root[y],1,n,l,r);
//		if(i%100==0)cout<<cst<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		res=0;
		for(int j=1;j<=100;j++)
		{
//			if(i==4)cout<<"o:"<<j<<endl;
			check(root[j],1,n,i);
			if(res)
			{
				cout<<j<<' ';
				break;
			}
		}
	}
	cout<<"\n";
	return 0;
}