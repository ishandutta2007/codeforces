#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL
 
struct tree { ll sum,sum1,tag,tag1; }t[1600010],ans;

ll pow1[310][1010],pow2[310][1010];
ll num[400010];
int p[310],inv[310],n,m,tot;
bool bo[310];
char s[233];
 
inline ll rd()
{
    ll x=0;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar());
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}
 
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline void pushdown(int o,int l,int r)
{
	if (t[o].sum1!=1)
	{
		int mid=(l+r)>>1;
		t[o<<1].sum=t[o<<1].sum*ksm(t[o].sum1,mid-l+1)%mod;t[o<<1].sum1=t[o<<1].sum1*t[o].sum1%mod;
		t[o<<1|1].sum=t[o<<1|1].sum*ksm(t[o].sum1,r-mid)%mod;t[o<<1|1].sum1=t[o<<1|1].sum1*t[o].sum1%mod;
		t[o].sum1=1;
	}
	if (t[o].tag1!=0)
	{
		t[o<<1].tag|=t[o].tag1;t[o<<1].tag1|=t[o].tag1;
		t[o<<1|1].tag|=t[o].tag1;t[o<<1|1].tag1|=t[o].tag1;
		t[o].tag1=0;
	}
}

inline tree merge(tree x,tree y)
{
    tree res;
    res.sum=x.sum*y.sum%mod;
    res.tag=x.tag|y.tag;
    res.sum1=1;res.tag1=0;
    return res;
}
 
inline ll gao(ll x)
{
    ll res=0;
    for (int i=1;i<=62;i++) if (x%p[i]==0) res|=(1LL<<(i-1));
    return res;
}
 
inline void build(int o,int l,int r)
{
	t[o].sum1=1;t[o].tag1=0;
    if (l==r) { t[o].sum=num[l];t[o].tag=gao(num[l]);return; }
    int mid=(l+r)>>1;
    build(o<<1,l,mid);
    build(o<<1|1,mid+1,r);
    t[o]=merge(t[o<<1],t[o<<1|1]);
}
 
inline void modify(int o,int l,int r,int x,int y,ll z,ll hh)
{
	if (l>=x&&r<=y) { t[o].sum=t[o].sum*ksm(z,r-l+1)%mod;t[o].sum1=t[o].sum1*z%mod;t[o].tag|=hh;t[o].tag1|=hh;return; }
	pushdown(o,l,r);
    int mid=(l+r)>>1;
    if (x<=mid) modify(o<<1,l,mid,x,y,z,hh);
    if (y>mid) modify(o<<1|1,mid+1,r,x,y,z,hh);
    t[o]=merge(t[o<<1],t[o<<1|1]);
}
 
inline tree query(int o,int l,int r,int x,int y)
{
    if (l>=x&&r<=y) return t[o];
    pushdown(o,l,r);
    int mid=(l+r)>>1;
    tree res;res.sum=1;res.tag=0;
    if (x<=mid) res=merge(res,query(o<<1,l,mid,x,y));
    if (y>mid) res=merge(res,query(o<<1|1,mid+1,r,x,y));
    return res;
}
 
int main()
{
    n=rd();m=rd();tot=0;
    for (int i=1;i<=n;i++) num[i]=rd();
    for (int i=2;i<=300;i++)
    {
        if (!bo[i]) p[++tot]=i;
        for (int j=1;j<=tot&&i*p[j]<=300;j++)
        {
            bo[i*p[j]]=true;
            if (i%p[j]==0) break;
        }
    }
    for (int i=1;i<=62;i++) inv[i]=ksm(p[i],mod-2);
    for (ll i=1;i<=300;i++)
    {
    	pow1[i][0]=1;
    	for (int j=1;j<=1000;j++) pow1[i][j]=pow1[i][j-1]*i%mod;
    	pow2[i][0]=1;
    	for (int j=1;j<=1000;j++) pow2[i][j]=pow2[i][j-1]*pow1[i][1000]%mod;
	}
    build(1,1,n);
    while (m--)
    {
    	scanf("%s",s+1);
        ll x=rd(),y=rd();
        if (s[1]=='T')
        {
            ans=query(1,1,n,x,y);
            ll res=ans.sum;
            for (int i=1;i<=62;i++) if ((1LL<<(i-1))&ans.tag) res=res*inv[i]%mod*(ll)(p[i]-1)%mod;
            print(res);
        }
        else
        {
        	ll z=rd(),hh=0;
        	for (int i=1;i<=62;i++) if (z%p[i]==0) hh|=(1LL<<(i-1));
        	modify(1,1,n,x,y,z,hh);
		}
    }
    return 0;
}