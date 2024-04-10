#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
char gc(){static char buf[1<<20],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=3e5+5;
multiset<int>s;
int n,l[xx],r[xx];
struct fhq
{
	int val[xx],tag[xx],siz[xx],c[xx][2],rd[xx],cst;
	void upd(int k){siz[k]=siz[c[k][0]]+siz[c[k][1]]+1;}
	//1 
	void ad(int k,int z){if(k)val[k]+=z,tag[k]+=z;}
	void pd(int k){if(tag[k])ad(c[k][0],tag[k]),ad(c[k][1],tag[k]),tag[k]=0;}
	void split(int k,int a,int &x,int &y)
	{
		if(!k)return x=y=0,void();
		pd(k);
		if(val[k]<=a)x=k,split(c[k][1],a,c[k][1],y);
		else y=k,split(c[k][0],a,x,c[k][0]);
		upd(k);
	}
	int merge(int x,int y)
	{
		if(!x||!y)return x+y;
		pd(x),pd(y);
		if(rd[x]<rd[y])return c[x][1]=merge(c[x][1],y),upd(x),x;
		else return c[y][0]=merge(x,c[y][0]),upd(y),y;
	}
	int rt;
	int L_B(int a)//lower_bound 
	{
		int x,y;
		split(rt,a-1,x,y);
		int A=fmin(y);
		rt=merge(x,y);
		return A;
	}
	int fmin(int k)
	{
		if(!k||!siz[k])return -1;
		pd(k);
		if(!c[k][0])return val[k];
		return fmin(c[k][0]);
	}
	void add(int l,int r)
	{
		int x,y,z;
		split(rt,l-1,x,y);
		split(y,r,y,z);
		ad(y,1);
		rt=merge(x,merge(y,z));
	}
	void in(int t)
	{
		++cst,rd[cst]=rand(),val[cst]=t,siz[cst]=1;
		int x,y;
		split(rt,t,x,y);
		rt=merge(x,merge(cst,y));
	}
	void er(int t)
	{
		int x,y,z;
		split(rt,t-1,x,y);
		split(y,t,y,z);
		y=merge(c[y][0],c[y][1]);
//		cout<<siz[x]<<" "<<siz[y]<<" "<<siz[z]<<"!!\n";
		rt=merge(x,merge(y,z));
	}
	int S(){return siz[rt];}
}F;
int main(){
	srand(514);
	n=read();
	// 
	// 
	for(int i=1;i<=n;i++)l[i]=read(),r[i]=read();
//	for(int i=1;i<=n;i++)cout<<l[i]<<" "<<r[i]<<"!!\n";
//	for(int i=1;i<=n;i++)
//	{
//		if(s.upper_bound(r[i])!=s.end())s.erase(s.upper_bound(r[i]));
//		s.insert(l[i]);
//	}
	for(int i=1;i<=n;i++)
	{
//		puts("a");
		F.add(l[i],r[i]);
		F.in(l[i]);
		int q=0;
//		cout<<q<<" "<<F.S()<<"ASD\n";
		if((q=F.L_B(r[i]+1))!=-1)F.er(q);
//		cout<<q<<" "<<F.S()<<"ASD\n";
	}
	cout<<F.S()<<"\n";
	pc('1',1);
	return 0;
}