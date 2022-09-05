//by yjz
#include<bits/stdc++.h>
#include<bitset>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbg=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int ia[100111];
struct PersistentFruitCandy
{
	struct node
	{
		int lazy,mn,tl,tr;
	}a[10000111];
	#define pls a[p].tl
	#define prs a[p].tr
	int tot;
	PersistentFruitCandy(){tot=0;}
	int copy(int pp)
	{
		int p=++tot;
		a[p].lazy=a[pp].lazy;
		a[p].mn=a[pp].mn;
		a[p].tl=a[pp].tl;
		a[p].tr=a[pp].tr;
		return p;
	}
	int build(int l,int r)
	{
		int p=++tot;
		a[p].lazy=0;
		if(l==r)
		{
			a[p].mn=ia[l];
			a[p].tl=a[p].tr=0;
//			cout<<"build:"<<l<<","<<r<<" "<<a[p].mn<<endl;
			return p;
		}
		int m=l+r>>1;
		a[p].tl=build(l,m);
		a[p].tr=build(m+1,r);
		a[p].mn=min(a[pls].mn,a[prs].mn);
//		cout<<"build:"<<l<<","<<r<<" "<<a[p].mn<<endl;
		return p;
	}
	void push_down(int p)
	{
		if(pls<p)pls=copy(pls);
		if(prs<p)prs=copy(prs);
		if(a[p].lazy)
		{
			a[p].mn=a[p].lazy;
			a[pls].mn=a[prs].mn=a[pls].lazy=a[prs].lazy=a[p].lazy;
			a[p].lazy=0;
		}
	}
	void change(int x,int y,int l,int r,int v,int p)
	{
		if(x<=l&&r<=y)
		{
			a[p].mn=a[p].lazy=v;
//			cout<<"change:"<<x<<","<<y<<" "<<l<<","<<r<<" "<<v<<" "<<p<<" "<<a[p].mn<<" "<<a[p].lazy<<endl;
			return;
		}
		push_down(p);
		int m=l+r>>1;
		if(x<=m)change(x,y,l,m,v,pls);
		if(m<y)change(x,y,m+1,r,v,prs);
		a[p].mn=min(a[pls].mn,a[prs].mn);
//		cout<<"change:"<<x<<","<<y<<" "<<l<<","<<r<<" "<<v<<" "<<p<<" "<<a[p].mn<<" "<<a[p].lazy<<endl;
	}
	void change1(int x,int l,int r,int v,int p)
	{
		if(l==r)
		{
			a[p].mn=v;
			return;
		}
		push_down(p);
		int m=l+r>>1;
		if(x<=m)change1(x,l,m,v,pls);
		else change1(x,m+1,r,v,prs);
		a[p].mn=min(a[pls].mn,a[prs].mn);
	}
	int query(int x,int y,int l,int r,int p)
	{
//		cout<<"query:"<<x<<","<<y<<" "<<l<<","<<r<<" "<<p<<" "<<a[p].mn<<" "<<a[p].lazy<<endl;
		if(l<r)push_down(p);
		if(x<=l&&r<=y)return a[p].mn;
		int m=l+r>>1,ret=mod;
		if(x<=m)ret=min(ret,query(x,y,l,m,pls));
		if(m<y)ret=min(ret,query(x,y,m+1,r,prs));
		return ret;
	}
	int query2(int x,int l,int r,int p)
	{
		if(l<r)push_down(p);
		if(l==r)
		{
			int tmp=a[p].lazy;
			a[p].lazy=0;
			return tmp;
		}
		int m=l+r>>1,ret=mod;
		if(x<=m)return query2(x,l,m,pls);
		else return query2(x,m+1,r,prs);
	}
}A;
int n,k,a[100111];
int stA,stB[10011];
void push_downA(int x)
{
//	cout<<"push_downA:"<<x<<endl;
	int lazy=A.query2(x,1,k,stA);
//	cout<<"lazy="<<lazy<<endl;
	if(lazy)A.change(1,n,1,n,lazy,stB[x]);
}
void change(int x,int y,int v)
{
//	cout<<"change:"<<x<<","<<y<<endl;
	int xB=(x-1)/n+1,yB=(y-1)/n+1;
	if(xB==yB)
	{
		push_downA(xB);
		A.change((x-1)%n+1,(y-1)%n+1,1,n,v,stB[xB]);
		A.change1(xB,1,k,A.a[stB[xB]].mn,stA);
	}
	else
	{
		change(x,xB*n,v);
		change(yB*n-n+1,y,v);
		if(xB+1<yB)
		{
			A.change(xB+1,yB-1,1,k,v,stA);
		}
	}
}
int query(int x,int y)
{
//	cout<<"query:"<<x<<","<<y<<endl;
	int xB=(x-1)/n+1,yB=(y-1)/n+1;
	if(xB==yB)
	{
		push_downA(xB);
		return A.query((x-1)%n+1,(y-1)%n+1,1,n,stB[xB]);
	}
	else
	{
		int ans=mod;
		ans=min(ans,query(x,xB*n));
		ans=min(ans,query(yB*n-n+1,y));
		if(xB+1<yB)
		{
			ans=min(ans,A.query(xB+1,yB-1,1,k,stA));
		}
		return ans;
	}
}
int main()
{
	getii(n,k);
	for(int i=1;i<=n;i++)geti(a[i]),ia[i]=a[i];
	int tmp;
	tmp=A.build(1,n);
	for(int i=1;i<=k;i++)stB[i]=A.copy(tmp);
	for(int i=1;i<=k;i++)ia[i]=A.a[tmp].mn;
	stA=A.build(1,k);
	int q;
	geti(q);
	while(q--)
	{
		int type,l,r,v;
		getiii(type,l,r);
		if(type==1)
		{
			geti(v);
			change(l,r,v);
		}
		else
		{
			putsi(query(l,r));
		}
	}
	return 0;
}