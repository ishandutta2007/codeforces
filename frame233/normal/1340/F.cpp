// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
const int mod=998244853;
const int base=23333;
ll ksm(ll a,ll b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
const int S=350;
ll pw[N],inv[N];
int a[N],n;
int bel[N],L[N/S+5],R[N/S+5];
int val1[N/S+5+S+S][S+5],val2[N/S+5+S+S][S+5];
int max_block;
int l1[N/S+5+S+S],l2[N/S+5+S+S];
bool tag[N/S+5];
int st[N],top;
void rebuild(int B)
{
	top=0,tag[B]=false;
	int l=L[B],r=R[B];
	for(int i=l;i<=r;++i)
	{
		if(a[i]>0) st[++top]=a[i];
		else
		{
			if(top&&st[top]+a[i]==0) --top;
			else st[++top]=a[i];
		}
	}
	for(int i=1;i<top;++i)
	{
		if(st[i]>0&&st[i+1]<0)
		{
			tag[B]=true;
			return;
		}
	}
	int pos=0;while(pos<top&&st[pos+1]<0) ++pos;
	for(int i=1;i<=pos;++i) val1[B][i]=(val1[B][i-1]-1ll*st[i]*pw[i-1])%mod;			//   )
	for(int i=pos+1;i<=top;++i) val2[B][i-pos]=(1ll*val2[B][i-pos-1]*base+st[i])%mod;	//   (
	l1[B]=pos,l2[B]=top-pos;
}
void build()
{
	int cur=0;
	for(int l=1,r=S;l<=n;l+=S,r+=S)
	{
		chmin(r,n);
		++cur;L[cur]=l,R[cur]=r;
		for(int k=l;k<=r;++k) bel[k]=cur;                                           
		rebuild(cur);
	}
	max_block=cur;
}
void upd(int x,int y)
{
	a[x]=y;
	rebuild(bel[x]);
}
struct node{
	int id,len;
};
node __[N];
bool push(int cur)
{
	int pos=0;
	while(pos<l1[cur]&&top)
	{
		int id=__[top].id,len=__[top].len;
		int tmp=min(l1[cur]-pos,len);
		if(((val2[id][len]-1ll*val2[id][len-tmp]*pw[tmp])-(val1[cur][pos+tmp]-val1[cur][pos]+mod)*inv[pos])%mod==0)
		{
			pos+=tmp;
			__[top].len-=tmp;
			if(!__[top].len) --top;
		}
		else return false;
	}
	if(pos!=l1[cur]) return false;
	if(l2[cur]) __[++top]=(node){cur,l2[cur]};
	return true;
}
bool qry(int l,int r)
{
	top=0;
	if(bel[l]==bel[r])
	{
		for(int i=l;i<=r;++i)
		{
			if(a[i]>0) st[++top]=a[i];
			else
			{
				if(top&&st[top]+a[i]==0) --top;
				else return false;
			}
		}
		return !top;
	}
	for(int i=bel[l]+1;i<bel[r];++i) if(tag[i]) return false;
	int cur=max_block;
	for(int i=l;i<=R[bel[l]];++i)
	{
		++cur;
		if(a[i]<0)
		{
			l1[cur]=1,val1[cur][1]=-a[i];
			l2[cur]=0;
		}
		else
		{
			l1[cur]=0;
			l2[cur]=1,val2[cur][1]=a[i];
		}
		if(!push(cur)) return false;
	}
	for(int i=bel[l]+1;i<bel[r];++i) if(!push(i)) return false;
	for(int i=L[bel[r]];i<=r;++i)
	{
		++cur;
		if(a[i]<0)
		{
			l1[cur]=1,val1[cur][1]=-a[i];
			l2[cur]=0;
		}
		else
		{
			l1[cur]=0;
			l2[cur]=1,val2[cur][1]=a[i];
		}
		if(!push(cur)) return false;
	}
	return !top;
}
int main()
{
	pw[0]=inv[0]=1;
	ll ___=ksm(base);
	for(int i=1;i<N;++i) pw[i]=pw[i-1]*base%mod,inv[i]=inv[i-1]*___%mod;
	int q;
	read(n,q);
	for(int i=1;i<=n;++i) read(a[i]);
	build();read(q);
	int opt,x,y;
	while(q--)
	{
		read(opt,x,y);
		if(opt==1) upd(x,y);
		else puts(qry(x,y)?"Yes":"No");
	}
	return 0;
}