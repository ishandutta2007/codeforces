#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define y2 DCXISSOHANDSOME

// 

int all[800010][2];
int mxl[800010][2],mxr[800010][2];
int mxl1[800010][2],mxr1[800010][2];
int mx[800010];
int n,m;
char s[200010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline int min(const int &x,const int &y) { return (x<y)?x:y; }
inline int max(const int &x,const int &y) { return (x>y)?x:y; }

//all,mxl,mxr,mxl1,mxr1,mx

inline pii merge(int *a,int *b)
{
	int x1=a[0],y1=a[1],x2=b[0],y2=b[1];
	if (x1<=y2) return pii(x2,y1+y2-x1);
	return pii(x1+x2-y2,y1);
}

inline int gao(int *a,int *b)
{
	int x1=a[0],y1=a[1],x2=b[0],y2=b[1];
	if (x1<=y2) return y1+y2-x1+x2;
	return y1+x1+x2-y2;
}

inline void pushup(int o)
{
	int ls=o<<1,rs=o<<1|1;
	pii hh=merge(all[ls],all[rs]);
	all[o][0]=hh.first;all[o][1]=hh.second;
	mx[o]=max(mx[ls],mx[rs]);
	mxl[o][0]=mxl[ls][0];mxl[o][1]=mxl[ls][1];
	mxr[o][0]=mxr[rs][0];mxr[o][1]=mxr[rs][1];
	mxl1[o][0]=mxl1[ls][0];mxl1[o][1]=mxl1[ls][1];
	mxr1[o][0]=mxr1[rs][0];mxr1[o][1]=mxr1[rs][1];
	mx[o]=max(mx[o],gao(mxr[ls],mxl[rs]));
	mx[o]=max(mx[o],gao(mxr[ls],mxl1[rs]));
	mx[o]=max(mx[o],gao(mxr1[ls],mxl[rs]));
	mx[o]=max(mx[o],gao(mxr1[ls],mxl1[rs]));
	pii h1=merge(all[ls],mxl1[rs]),h2=merge(all[ls],mxl[rs]);
	if (h1.first+h1.second>mxl[o][0]+mxl[o][1]) mxl[o][0]=h1.first,mxl[o][1]=h1.second;
	if (h2.first+h2.second>mxl[o][0]+mxl[o][1]) mxl[o][0]=h2.first,mxl[o][1]=h2.second;
	if (h1.first-h1.second>mxl1[o][0]-mxl1[o][1]) mxl1[o][0]=h1.first,mxl1[o][1]=h1.second;
	if (h2.first-h2.second>mxl1[o][0]-mxl1[o][1]) mxl1[o][0]=h2.first,mxl1[o][1]=h2.second;
	h1=merge(mxr1[ls],all[rs]);h2=merge(mxr[ls],all[rs]);
	if (h1.first+h1.second>mxr[o][0]+mxr[o][1]) mxr[o][0]=h1.first,mxr[o][1]=h1.second;
	if (h2.first+h2.second>mxr[o][0]+mxr[o][1]) mxr[o][0]=h2.first,mxr[o][1]=h2.second;
	if (h1.second-h1.first>mxr1[o][1]-mxr1[o][0]) mxr1[o][0]=h1.first,mxr1[o][1]=h1.second;
	if (h2.second-h2.first>mxr1[o][1]-mxr1[o][0]) mxr1[o][0]=h2.first,mxr1[o][1]=h2.second;
}

inline void build(int o,int l,int r)
{
	if (l==r)
	{
		int hh=(s[l]=='(')?0:1;
		mxl[o][hh]++;mxr[o][hh]++;
		all[o][hh]++;mx[o]=1;
		if (hh==0) mxl1[o][hh]++;
		else mxr1[o][hh]++;
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

inline void modify(int o,int l,int r,int x)
{
	if (l==r)
	{
		int hh=(s[l]=='(')?1:0;
		memset(mxl[o],0,sizeof(mxl[o]));
		memset(mxr[o],0,sizeof(mxr[o]));
		memset(mxl1[o],0,sizeof(mxl1[o]));
		memset(mxr1[o],0,sizeof(mxr1[o]));
		memset(all[o],0,sizeof(all[o]));
		mxl[o][hh]++;mxr[o][hh]++;
		all[o][hh]++;mx[o]=1;
		if (hh==0) mxl1[o][hh]++;
		else mxr1[o][hh]++;
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x);
	else modify(o<<1|1,mid+1,r,x);
	pushup(o);
}

int main()
{
	n=rd();m=rd();
	scanf("%s",s+1);
	build(1,1,n*2-2);
	print(mx[1]);
	while (m--)
	{
		int x=rd(),y=rd();
		if (s[x]!=s[y]) modify(1,1,n*2-2,x),modify(1,1,n*2-2,y),swap(s[x],s[y]);
		print(mx[1]);
	}
	return 0;
}