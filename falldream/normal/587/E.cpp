#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 200000 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,Q,a[MN+5];
struct data{int s[2][32];
	data(){s[0][30]=s[1][30]=-1;}
	void ins(int x,int num=0)
	{
		for(int j=29;~j;--j)
			if(x&(1<<j))
			{
				if(s[num][j]) x^=s[num][j],num^=(num^1);
				else if(s[num^1][j]) x^=s[num^1][j],num^=num;
				else{s[num][j]=x;return;}
			}
		s[num][30]=0;
	} 
	data operator + (const data&b)
	{
		data c=*this;
		for(int i=29;~i;--i)
		{
			if(b.s[0][i]) c.ins(b.s[0][i]);
			if(b.s[1][i]) c.ins(b.s[1][i],1);
		}
		if(b.s[0][30]==0) c.s[0][30]=0;
		if(b.s[1][30]==0) c.s[1][30]=0;
		return c;
	}
};
struct Tree{int l,r,val;data x;}T[MN*4+5];

void Build(int x,int l,int r)
{
	//cout<<"Build"<<x<<" "<<l<<" "<<r<<endl;
	if((T[x].l=l)==(T[x].r=r)){T[x].x.s[0][30]=T[x].x.s[1][30]=-1;T[x].x.ins(a[l]);return;}	
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r); 
	T[x].x=T[x<<1].x+T[x<<1|1].x;
}
int q[50];
inline void Mark(int x,int v)
{
	T[x].val^=v;//cout<<"Mark"<<x<<" "<<v<<endl;
	for(int i=0;i<=29;++i) q[i]=T[x].x.s[0][i],T[x].x.s[0][i]=0;
	int flag=T[x].x.s[0][30];T[x].x.s[0][30]=-1;
	for(int i=0;i<=29;++i) if(q[i]) T[x].x.ins(q[i]^v);
	if(flag==0) T[x].x.ins(v);
}
inline void pushdown(int x){Mark(x<<1,T[x].val);Mark(x<<1|1,T[x].val);T[x].val=0;} 

void Modify(int x,int l,int r,int v)
{
	if(T[x].l==l&&T[x].r==r) {Mark(x,v);return;}	
	int mid=T[x].l+T[x].r>>1;if(T[x].val)pushdown(x);
	if(r<=mid) Modify(x<<1,l,r,v);
	else if(l>mid) Modify(x<<1|1,l,r,v);
	else Modify(x<<1,l,mid,v),Modify(x<<1|1,mid+1,r,v);
	T[x].x=T[x<<1].x+T[x<<1|1].x; 
}

data Query(int x,int l,int r)
{
	if(T[x].l==l&&T[x].r==r) return T[x].x;
	int mid=T[x].l+T[x].r>>1;if(T[x].val) pushdown(x);
	if(r<=mid) return Query(x<<1,l,r);
	else if(l>mid) return Query(x<<1|1,l,r);
	else return Query(x<<1,l,mid)+Query(x<<1|1,mid+1,r);
}
int main()
{
//	T[0].x.ins(2);//Mark(0,2);
//	for(int i=0;i<=29;++i) cout<<i<<" "<<T[0].x.s[0][i]<<" "<<T[0].x.s[1][i]<<endl;
	n=read();Q=read();
	for(int i=1;i<=n;++i) a[i]=read();
	Build(1,1,n);
	for(int i=1;i<=Q;++i)
	{
		int op=read(),l=read(),r=read();
		if(op==1) Modify(1,l,r,read());
		else 
		{
			data x=Query(1,l,r);int ans=1;
			for(int i=0;i<=29;++i)if(x.s[0][i]|x.s[1][i]) ans<<=1; 
		//	for(int i=0;i<=29;++i) cout<<i<<" "<<x.s[0][i]<<" "<<x.s[1][i]<<endl;
			printf("%d\n",ans);	
		}
	}
	return 0;
}