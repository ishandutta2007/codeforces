#include<bits/stdc++.h>
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
int n,m;
char c[1000005];
struct t
{
	int s[27];
	int L,R;
	int op;
}e[1000005];
int cst;
vector<int>v;
void split(int k,int &x,int &y,int size)
{
	int w=e[k].op;
//	cout<<w<<"W"<<endl;
	x=++cst;
	y=k;
	for(int i=1;i<=26;i++)
	{
		if(e[y].s[i]>=size)
		{
			e[x].s[i]+=size;
			e[y].s[i]-=size;
			e[x].op=e[y].op=w;
			return;
		}
		else 
		{
			e[x].s[i]+=e[y].s[i];
			size-=e[y].s[i];
			e[y].s[i]=0;
		}
	}
	e[x].op=e[y].op=w;
}
int sum[1000005];
void build(int k,int l,int r)
{
	if(l==r)
	{
		sum[k]=l;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=-1;
}
void add(int k,int l,int r,int v)
{
	sum[k]=v;
}
void pushdown(int k,int l,int r)
{
	if(sum[k]==-1)return;
	int mid=l+r>>1;
	add(k<<1,l,mid,sum[k]);
	add(k<<1|1,mid+1,r,sum[k]);
	sum[k]=-1;
}
void change(int k,int l,int r,int x,int y,int v)
{
	if(r<x||y<l)
	{
		return;
	}
	if(x<=l&&r<=y)
	{
		add(k,l,r,v);
		return;
	}
	pushdown(k,l,r);
	int mid=l+r>>1;
	change(k<<1,l,mid,x,y,v);
	change(k<<1|1,mid+1,r,x,y,v);
}
int ask(int k,int l,int r,int x)
{
	if(l==r)
	{
		return sum[k];
	}
	pushdown(k,l,r);
	int mid=l+r>>1;
	if(x<=mid)
	{
		return ask(k<<1,l,mid,x);
	}
	else return ask(k<<1|1,mid+1,r,x);
}
void print(int x)
{
	if(e[x].op)
	for(int j=1;j<=26;j++)
	{
		for(int k=1;k<=e[x].s[j];k++)
		{
			putchar('a'+j-1);
		}
	}
	else 
	{
		for(int j=26;j>=0;j--)
		{
			for(int k=1;k<=e[x].s[j];k++)
			{
				putchar('a'+j-1);
			}
		}
	}
}
int main(){
//	freopen("a.out","w",stdout);
	int n,m;
	n=read();
	m=read();
	scanf("%s",c);
	for(int i=1;i<=n;i++)
	{
		cst++;
		e[cst].s[c[i-1]-'a'+1]=1;
		e[cst].L=e[cst].R=i;
		e[cst].op=1;
	}
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int l,r,op;
		l=read();
		r=read();
		op=read();
		int a=ask(1,1,n,l);
		int w=-1;
//		cout<<a<<"a"<<endl;
		v.clear();
		if(e[a].L<l)
		{
			int L=e[a].L,R=e[a].R;
			int size=e[a].R-e[a].L+1;
			int x,y;
			if(e[a].op)split(a,x,y,l-e[a].L);//x 
			else split(a,y,x,size-l+e[a].L);//x 
			e[x].L=L;e[x].R=l-1;
			change(1,1,n,e[x].L,e[x].R,x);
			e[y].L=l;e[y].R=R;
			change(1,1,n,e[y].L,e[y].R,y);
			v.push_back(y);
			a=y;
			w=y;
//			print(x);
//			cout<<endl;
//			print(y);
//			cout<<endl;
		}
		else 
		{
			v.push_back(a);
		}
		while(e[a].R<r)
		{
			a=ask(1,1,n,e[a].R+1);
			v.push_back(a);
//			cout<<a<<"a"<<endl;
		}
//		print(a);
//		cout<<endl;
		if(e[a].R>r)
		{
			v.pop_back();
			int L=e[a].L,R=e[a].R;
			int size=e[a].R-e[a].L+1;
			int x,y;
			if(e[a].op)split(a,y,x,size-(e[a].R-r));//x 
			else split(a,x,y,(e[a].R-r));//x 
			e[x].L=r+1;e[x].R=R;
			change(1,1,n,e[x].L,e[x].R,x);
			e[y].L=L;e[y].R=r;
			change(1,1,n,e[y].L,e[y].R,y);
			v.push_back(y);
			a=y;
			w=y;
		}
		cst++;
		for(int i=0;i<v.size();i++)
		{
//			cout<<v[i]<<endl;
//			print(v[i]);
//			cout<<endl;
			for(int j=1;j<=26;j++)
			{
				e[cst].s[j]+=e[v[i]].s[j];
			}
		}
		e[cst].L=l;
		e[cst].R=r;
		e[cst].op=op;
//		print(cst);
//		cout<<endl;
//		cout<<cst<<endl;
		change(1,1,n,e[cst].L,e[cst].R,cst);
//		for(int i=1;i<=n;i++)
//		{
//			cout<<ask(1,1,n,i)<<" ";
//		}
//		cout<<endl;
	}
	int a;
	a=ask(1,1,n,1);
	while(e[a].R<n)
	{
		print(a);
		a=ask(1,1,n,e[a].R+1);
	}
	print(a);
	return 0;
}