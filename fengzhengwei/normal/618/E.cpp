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
const double pi=3.141592653589793238462643383279;
int n,m;
struct juz
{
	double a[5][5];
	void clear()
	{
		memset(a,0,sizeof(a));
	}
	void set()
	{
		clear();
		a[1][1]=a[2][2]=a[3][3]=1;
	}
	void operator*(const juz &w)
	{
		juz o;
		o.clear();
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				for(int k=1;k<=3;k++)
					o.a[i][j]+=a[i][k]*w.a[k][j];
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)a[i][j]=o.a[i][j];
	}
	void print()
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
		puts("");
	}
}sum[1300005];
int vis[1300005];
void build(int k,int l,int r)
{
	if(l==r)
	{
		sum[k].a[1][1]=l-1;
		sum[k].a[1][2]=0;
		sum[k].a[1][3]=1;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k].set();
}
void pushdown(int k)
{
	if(!vis[k])return;
	vis[k]=0;
	sum[k<<1]*sum[k];
	sum[k<<1|1]*sum[k];
	vis[k<<1]=1;
	vis[k<<1|1]=1;
//	sum[k<<1].print();
//	sum[k<<1|1].print();
	sum[k].set();
}
void change(int k,int l,int r,int x,int y,juz s)
{
	if(r<x||y<l)return;
	if(x<=l&&r<=y)
	{
//		cout<<l<<" "<<r<<endl;
//		sum[k].print();
//		cout<<"QWE"<<endl;
		sum[k]*s;
//		sum[k].print();
//		cout<<"EQW"<<endl;
		vis[k]=1;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	change(k<<1,l,mid,x,y,s);
	change(k<<1|1,mid+1,r,x,y,s);
}
double xx,yy;
void ask(int k,int l,int r,int v)
{
	if(l==r)
	{
		xx=sum[k].a[1][1];yy=sum[k].a[1][2];
//		cout<<xx<<" sss "<<yy<<" "<<l<<" "<<r<<endl;
		return;
	}
//	if(v==4)cout<<k<<" "<<vis[k]<<endl;
	pushdown(k);
	int mid=l+r>>1;
	if(v<=mid)ask(k<<1,l,mid,v);
	else ask(k<<1|1,mid+1,r,v);
}
int main(){
	n=read();
	m=read();n++;
	build(1,1,n);
	juz o;
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		op=read();
		x=read();
		y=read();
		if(op==1)
		{
			ask(1,1,n,x);
			double xx1=xx,yy1=yy;
			ask(1,1,n,x+1);
			double xx2=xx,yy2=yy;
			o.set();
			double jl=sqrt((yy2-yy1)*(yy2-yy1)+(xx2-xx1)*(xx2-xx1));
			o.a[3][1]=y*(xx2-xx1)/jl;
			o.a[3][2]=y*(yy2-yy1)/jl;
//			o.print();
			change(1,1,n,x+1,n,o);
		}
		else 
		{
			ask(1,1,n,x);
			o.clear();
			double p=y/180.0*pi;
			o.a[1][1]=cos(p);
			o.a[1][2]=-sin(p);
			o.a[2][1]=sin(p);
			o.a[2][2]=cos(p);
			o.a[3][3]=1;
			o.a[3][1]=xx-cos(p)*xx-sin(p)*yy;
			o.a[3][2]=yy-cos(p)*yy+sin(p)*xx;
//			cout<<p<<"QQQ"<<xx<<" "<<yy<<endl;
//			o.print();
			change(1,1,n,x+1,n,o);
		}
		ask(1,1,n,4);
//		cout<<n<<"QQQQQQQq"<<endl;
//		for(int i=1;i<=n;i++)ask(1,1,n,i);
		ask(1,1,n,n);
		cout<<fixed<<setprecision(5)<<xx<<" "<<yy<<"\n";
//		cout<<200<<endl;
	}
	return 0;
}