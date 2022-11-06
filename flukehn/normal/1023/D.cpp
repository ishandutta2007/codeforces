#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<ctime>
#define ll long long
using namespace std;
vector<int> v[200005];
char butt[(1<<15)+2],*bp=butt,*bq=butt+(1<<15);
inline void pr(char x){
    *bp=x;(++bp==bq)?fwrite(butt,1,1<<15,stdout),bp=butt:0;
}
inline void write(int x){
    if(!x)pr('0');
    else{
        if(x<0)pr('-'),x=-x;
        static int s[12];
        int p=0;
        while(x)s[p++]=x%10,x/=10;
        for(int i=p-1;~i;--i)pr(s[i]+'0');
    }
}
int n,m;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}


int ans1[200005],a[200005],l[200005],r[200005];
struct segt
{
	struct segtree
	{
		int ls;
		int rs;
		int sum;
		int mark;
	}tree[800005];
	int cnt;
	void init()
	{
		cnt=1;
	}
	void build(int p,int l,int r)
	{
		int mid=l+r>>1;
		if(l==r) return;
		tree[p].ls=++cnt;
		tree[p].rs=++cnt;
		build(tree[p].ls,l,mid);
		build(tree[p].rs,mid+1,r);
	}
	int query(int p,int l,int r,int x,int y)
	{
		int mid=l+r>>1;
		if(l==x&&r==y) return tree[p].sum;
		int num=tree[p].mark;
		if(num)
		{
			tree[tree[p].ls].mark=num;
			tree[tree[p].rs].mark=num;
			tree[tree[p].ls].sum=num;
			tree[tree[p].rs].sum=num;
			tree[p].mark=0;
		}
		if(y<=mid) return  query(tree[p].ls,l,mid,x,y);
		else if(x>mid) return query(tree[p].rs,mid+1,r,x,y);
		else return query(tree[p].ls,l,mid,x,mid)+query(tree[p].rs,mid+1,r,mid+1,y);
	}
	void modify(int p,int l,int r,int x,int y,int z)
	{
		int mid=l+r>>1;
		if(l==x&&r==y) 
		{
			tree[p].sum=tree[p].mark=z;
			return;
		}
		int num=tree[p].mark;
		if(num)
		{
			tree[tree[p].ls].mark=num;
			tree[tree[p].rs].mark=num;
			tree[tree[p].ls].sum=num;
			tree[tree[p].rs].sum=num;
			tree[p].mark=0;
		}
		if(y<=mid) modify(tree[p].ls,l,mid,x,y,z);
		else if(x>mid) modify(tree[p].rs,mid+1,r,x,y,z);
		else
		{
			modify(tree[p].ls,l,mid,x,mid,z);
			modify(tree[p].rs,mid+1,r,mid+1,y,z);
		}
		tree[p].sum=tree[tree[p].ls].sum+tree[tree[p].rs].sum;
	}
	void push(int p,int l,int r)
	{
		if(l==r)
		{
			ans1[l]=tree[p].sum;
			return;
		}
		int num=tree[p].mark;
		if(num)
		{
			tree[tree[p].ls].mark=num;
			tree[tree[p].rs].mark=num;
			tree[tree[p].ls].sum=num;
			tree[tree[p].rs].sum=num;
			tree[p].mark=0;
		}
		int mid=l+r>>1;
		push(tree[p].ls,l,mid);
		push(tree[p].rs,mid+1,r);
	}
}ans,t;
int f[200005];
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	bool ac=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i])
		{
			ac=1;
			break;
		}
	}
	if(!ac)
	{
		puts("YES");
		for(int i=1;i<=n;i++)
		printf("%d ",m);
		return 0;
	}
	//cout<<"ok";
	ans.init();t.init();
	t.build(1,1,n);ans.build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		if(a[i])
		{
			v[a[i]].push_back(i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(!v[i].size()) continue;
		l[i]=v[i][0],r[i]=v[i][v[i].size()-1];
		//cout<<l[i]<<" "<<r[i]<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		if(!v[i].size()) continue;
		/*if(t.query(1,1,n,l[i],r[i])!=0)
		{
			puts("NO");
			return 0;
		}//*/
		ans.modify(1,1,n,l[i],r[i],i);
		/*int x=v[i].size();
		for(int j=0;j<x;j++)
		{
			t.modify(1,1,n,v[i][j],v[i][j],1);
		}//*/
	}
	ans.push(1,1,n);
	
	for(int i=1;i<=n;i++)
	{
		if(!a[i]) continue;
		if(a[i]!=ans1[i])
		{
			puts("NO");
			return 0;
		}
	}
	int ok=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==m)
		{
			ok=1;
			break;
		}
		if(a[i]==0)
		{
			ok=2;
		}
	}
	if(!ok)
	{
		puts("NO");
		return 0;
	}
	if(ok==2)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) 
			{
				ans1[i]=m;
				break;
			}
		}
	}
	puts("YES");
	int last=0;
	for(int i=1;i<=n;i++)
	{
		if(ans1[i]!=0) last=ans1[i];
		else ans1[i]=last;
	}
	last=0;
	for(int i=n;i;i--)
	{
		if(ans1[i]!=0) last=ans1[i];
		else ans1[i]=last;
		f[i]=ans1[i];
		//printf("%d ",ans1[i]);
	}
	for(int i=1;i<=n;i++)
	{
		/*write(ans1[i]);
		pr(' ');*/
		printf("%d ",f[i]);
	}
	//fwrite(butt,1,bp-butt,stdout);
}