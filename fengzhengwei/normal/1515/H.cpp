#include<bits/stdc++.h>
#define ll long long 
//#define int long long 
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
//458Mb  
char st;
const int xx=2e5+5;
// tag  
int n,m;
// log ^2  log  
struct nod{int sum,c[2],xt,at,ot,is;}e[xx*75];
int gar[xx*75],a[xx],t[xx*10],top;
//t 
int cst;
int nw()
{
	int x;
	if(top)x=gar[top--];
	else x=++cst;
	e[x]={0,0,0,0,0,0,0};
	return x;
}
//add =1  0  
// 
void pd(int,int);
int mg(int,int,int);
void ado(int,int,int);
void ada(int,int,int);
void adx(int,int,int);
//tagtag 
void upd(int x,int dep)
{
	e[x].sum=e[e[x].c[0]].sum+e[e[x].c[1]].sum;
	e[x].is=e[e[x].c[0]].is|e[e[x].c[1]].is|((e[x].c[0]&&e[x].c[1])<<dep);
}
int mg(int x,int y,int dep)
{
	if(!x||!y)return x+y;
	pd(x,dep),pd(y,dep);
	if(dep==-1)
	{
		e[x].sum=max(e[x].sum,e[y].sum);
		gar[++top]=y;
		assert(e[x].sum<=1);
		return x;
	}
	e[x].c[0]=mg(e[x].c[0],e[y].c[0],dep-1);
	e[x].c[1]=mg(e[x].c[1],e[y].c[1],dep-1);
	upd(x,dep);
//	cerr<<x<<" "<<dep<<" "<<e[x].sum<<" "<<e[x].c[0]<<" "<<e[x].c[1]<<" "<<e[e[x].c[0]].sum<<" "<<e[e[x].c[1]].sum<<"@\n";
	gar[++top]=y;
	return x;
}
void ado(int x,int y,int dep)
{
	if(!x||!y||dep==-1)return;
	if(y>>dep&1)
	{
		// pd  
		pd(x,dep);
//		cerr<<e[x].sum<<"@\n";
		e[x].c[1]=mg(e[x].c[0],e[x].c[1],dep-1);
		e[x].c[0]=0,upd(x,dep),y-=(1<<dep);
//		if(x==26)
//		cerr<<e[x].sum<<" "<<e[x].c[0]<<" "<<e[x].c[1]<<" "<<e[e[x].c[1]].sum<<"!!!!!!!\n";
	}
	if(y&e[x].is)
	{
		pd(x,dep);
		ado(e[x].c[0],y,dep-1);
		ado(e[x].c[1],y,dep-1);
		upd(x,dep);
	}
	else 
	{
		e[x].xt&=(~y),e[x].at&=(~y),e[x].ot|=y;
		upd(x,dep);
	}
}
void ada(int x,int y,int dep)
{
	if(!x||!y||dep==-1)return;
	if(y>>dep&1)
	{
		pd(x,dep);
		e[x].c[0]=mg(e[x].c[0],e[x].c[1],dep-1);
		e[x].c[1]=0,upd(x,dep),y-=(1<<dep);
	}
	if(y&e[x].is)
	{
		pd(x,dep);
		ada(e[x].c[0],y,dep-1);
		ada(e[x].c[1],y,dep-1);
		upd(x,dep);
	}
	else 
	{
		e[x].xt&=(~y),e[x].ot&=(~y),e[x].at|=y;
		upd(x,dep);
	}
}
void adx(int x,int y,int dep)
{
	if(!x||!y||dep==-1)return;
	if(y>>dep&1)
		pd(x,dep),swap(e[x].c[0],e[x].c[1]),y-=(1<<dep);
	int a=e[x].at&y,o=e[x].ot&y;
	e[x].at-=a,e[x].at+=o;// 
	e[x].ot-=o,e[x].ot+=a;
	y-=a,y-=o,e[x].xt^=y;
	upd(x,dep);
}
void pd(int x,int dep)
{
	if(!x)return;//tag 
	if(e[x].ot)ado(e[x].c[0],e[x].ot,dep-1),ado(e[x].c[1],e[x].ot,dep-1),e[x].ot=0;
	if(e[x].at)ada(e[x].c[0],e[x].at,dep-1),ada(e[x].c[1],e[x].at,dep-1),e[x].at=0;
	if(e[x].xt)adx(e[x].c[0],e[x].xt,dep-1),adx(e[x].c[1],e[x].xt,dep-1),e[x].xt=0;
}
int rt;
void build(int &k,int l,int r,int dep)
{
	k=nw();
//	cerr<<cst<<"@\n";
	if(l==r)return t[l]?e[k].sum=1,void():void();
	int mid=l+r>>1;
	build(e[k].c[0],l,mid,dep-1);
	build(e[k].c[1],mid+1,r,dep-1);
	upd(k,dep);
}
struct tp{int id,l,r,dep;};
vector<tp>v;
void get(int &k,int l,int r,int x,int y,int dep)
{
	if(!k)return;
	if(x<=l&&r<=y)return v.push_back({k,l,r,dep}),k=0,void();
	pd(k,dep);int mid=l+r>>1;
	if(x<=mid)get(e[k].c[0],l,mid,x,y,dep-1);
	if(mid<y)get(e[k].c[1],mid+1,r,x,y,dep-1);
	upd(k,dep);
}
int ask(int &k,int l,int r,int x,int y,int dep)
{
	if(!k)return 0;
	if(x<=l&&r<=y)
	{
//		if(e[k].sum)cerr<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<dep<<" "<<e[k].sum<<"##\n";
		return 
		e[k].sum;
	}
	pd(k,dep);int mid=l+r>>1;
	if(y<=mid)return ask(e[k].c[0],l,mid,x,y,dep-1);
	if(mid<x)return ask(e[k].c[1],mid+1,r,x,y,dep-1);
	return ask(e[k].c[0],l,mid,x,y,dep-1)+ask(e[k].c[1],mid+1,r,x,y,dep-1);
}
void fill(int &k,int l,int r,int x,int y,int dep,int z)
{
	if(x<=l&&r<=y)return k=mg(k,z,dep),void();
	if(!k)k=nw();
//	,cerr<<e[k].sum<<"@@\n";
	pd(k,dep);int mid=l+r>>1;
	if(x<=mid)fill(e[k].c[0],l,mid,x,y,dep-1,z);
	if(mid<y)fill(e[k].c[1],mid+1,r,x,y,dep-1,z);
	upd(k,dep);
}
void print(int &k,int l,int r,int dep)
{
	if(!k)return;
	if(l==r)
	{
		if(e[k].sum==1)
			cout<<l<<" ";
		assert(e[k].sum<=1);
		return;
	}
	pd(k,dep);int mid=l+r>>1;
	print(e[k].c[0],l,mid,dep-1);
	print(e[k].c[1],mid+1,r,dep-1);
//	if(e[k].sum)cerr<<k<<" "<<l<<" "<<r<<" "<<e[k].sum<<"@\n";
}
char ed;
signed main(){
	cerr<<abs(&st-&ed)/1024/1024<<"\n";
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]=1;
	build(rt,0,(1<<20)-1,19);
//	cerr<<cst<<"@\n";
//		print(rt,0,(1<<20)-1,19);
//exit(0);
	
//		cout<<"I="<<0<<"\n";
//		print(rt,0,(1<<20)-1,19);
//		puts("");
//		puts("");
	for(int i=1;i<=m;i++)
	{
//			cout<<"I="<<i<<" "<<e[rt].sum<<"\n";
//		if(i==3)
//		{
//		}
		int op=read(),l=read(),r=read();
		v.clear();
		if(op==4)cout<<ask(rt,0,(1<<20)-1,l,r,19)<<"\n";
		else 
		{
			int z=read();
			get(rt,0,(1<<20)-1,l,r,19);
//			cerr<<e[rt].sum<<"##\n";
			if(op==1)
			{
				for(auto it:v)
				{
					int L=z&((1<<(it.dep+1))-1),R=z-L+((1<<(it.dep+1))-1);// 
					L^=((1<<(it.dep+1))-1),ada(it.id,L,it.dep);
//					cerr<<it.l<<" "<<it.r<<" "<<(it.l&R)<<" "<<(it.r&R)<<" "<<R<<"\n";
					fill(rt,0,(1<<20)-1,it.l&R,it.r&R,19,it.id);
				}
			}
			if(op==2)
			{
				for(auto it:v)
				{
					int L=z&((1<<(it.dep+1))-1),R=z-L;//or0 
					ado(it.id,L,it.dep);
//					cerr<<it.l<<" "<<it.r<<" "<<(it.l|R)<<" "<<(it.r|R)<<"\n";
					fill(rt,0,(1<<20)-1,it.l|R,it.r|R,19,it.id);
				}
			}
			if(op==3)
			{
				for(auto it:v)
				{
					int L=z&((1<<(it.dep+1))-1),R=z-L;//xor0 
					adx(it.id,L,it.dep);
					fill(rt,0,(1<<20)-1,it.l^R,it.r^R,19,it.id);
				}
			}
		}
//			cout<<"I="<<i<<" "<<e[rt].sum<<"\n";
//			print(rt,0,(1<<20)-1,19);
//			puts("");
//			puts("");
//		int x=27;
//	cerr<<x<<" "<<" "<<e[x].sum<<" "<<e[x].c[0]<<" "<<e[x].c[1]<<" "<<e[e[x].c[0]].sum<<" "<<e[e[x].c[1]].sum<<"@\n";
//		exit(0);
	}
	pc('1',1);
	return 0;
}
/*
9 3
9 5 0 6 3 2 6 6 5 
1 3 8 6
2 3 9 2
4 3 10 

6 2
3 0 6 9 6 8 
2 0 3 3
4 0 10 
*/