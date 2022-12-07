#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e9;
const int M=2e5+10;
int n,q,a[M],L[M],R[M];
set<int>s;
//0  1  -1  

struct segment_tree
{
	struct tree
	{
		int tl,tr;
		set<int>val;
	}t[M<<2];int ed[M];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define lson k<<1
	#define rson k<<1|1
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)return ed[l]=k,void();
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void upd(int pos,int z)
	{
		int now=ed[pos];
		while(now!=0)val(now).insert(z),now>>=1;
	}
	int query(int k,int l,int r,int x)
	{
		if (l(k)>=l&&r(k)<=r)
		{
			auto p=val(k).lower_bound(x);
			if (p==val(k).end())return inf;
			else return *p;
		}
		if (l(k)>r||r(k)<l)return inf;
		return min(query(lson,l,r,x),query(rson,l,r,x));
	}
}T;


void upd(int pos)
{
	if (a[pos]==-1)return;
	if (T.query(1,L[pos]+1,pos,pos)<R[pos])a[pos]=-1;
}

void del(int x)
{
	a[x]=1;L[R[x]]=L[x],R[L[x]]=R[x];
	if (L[x]!=0)upd(L[x]);
	if (R[x]!=n+1)upd(R[x]);
	s.erase(x);
}

int work(int l,int r)
{
	int x=*s.lower_bound(l);
	auto p=s.lower_bound(x+1);
	if (p==s.end()||(*p)>r)return x;
	else return -1;
}

signed main()
{
	n=read(),q=read();T.build(1,1,n);
	for (int i=1;i<=n;i++)s.insert(i),L[i]=i-1,R[i]=i+1;
	while(q--)
	{
		int opt=read();
		if (opt==0)
		{
			int l=read(),r=read(),t=read();
			if (!t)
			{
				while(s.lower_bound(l)!=s.end())
				{
					int pos=*s.lower_bound(l);
					if (pos>r)break;del(pos);
				}
			}
			else
			{
				T.upd(l,r);
				int x=work(l,r);
				if (x!=-1)a[x]=-1;
			}
		}
		else
		{
			int x=read();
			if (a[x]==0)puts("N/A");
			else if (a[x]==1)NO
			else YES
		}
	}
	return 0;
}