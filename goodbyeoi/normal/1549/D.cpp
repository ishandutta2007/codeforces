#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int M=3e5+10;
int n,m,a[M],b[M];

struct segment_tree
{
	struct tree
	{
		int tl,tr,val;
	}t[M<<2];
	#define l(k) t[(k)].tl
	#define r(k) t[(k)].tr
	#define val(k) t[(k)].val
	#define lson k<<1
	#define rson k<<1|1
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r){val(k)=b[l];return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		val(k)=__gcd(val(lson),val(rson));
	}
	int query(int k,int l,int r)
	{
		if (l(k)>r||r(k)<l)return 0;
		if (l(k)>=l&&r(k)<=r)return val(k);
		return __gcd(query(lson,l,r),query(rson,l,r));
	}
}T;

signed main()
{
//	cout<<__gcd(0,114514);
	WT
	{
		n=read();
		for (int i=1;i<=n;i++)a[i]=read();
		if (n==1){puts("1");continue;}
		for (int i=2;i<=n;i++)b[i-1]=abs(a[i]-a[i-1]);
		T.build(1,1,n-1);int ans=0;
		for (int l=1,r=0;l<n;l++)
		{
			while(r+1<=l&&T.query(1,r+1,l)==1)r++;
			ans=max(ans,l-r+1);
//			cout<<l<<' '<<r<<endl;
		}cout<<ans<<endl;
	}
	return 0;
}