// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=100005;
const int S=350;
int a[N],bel[N],b[N],tag[N/S+5],L[N/S+5],R[N/S+5],cnt[N/S+5];
void rebuild(int B,int l,int r,int x)
{
	for(int i=L[B];i<=R[B];++i)a[i]=max(1,a[i]-tag[B]-(l<=i&&i<=r?x:0)),b[i]=bel[a[i]]==bel[i]?b[a[i]]:a[i];
	tag[B]=0;
}
int main()
{
	int n,q;read(n,q);
	for(int i=2;i<=n;++i)read(a[i]);
	bel[1]=1,L[1]=R[1]=1;
	int cur=1;
	for(int l=2,r=S+1;l<=n;l+=S,r+=S)
	{
		chmin(r,n),++cur;
		for(int k=l;k<=r;++k)bel[k]=cur;
		L[cur]=l,R[cur]=r;
	}
	for(int i=2;i<=n;++i)b[i]=bel[a[i]]==bel[i]?b[a[i]]:a[i];
	int opt,l,r,x,y;
	while(q--)
	{
		read(opt);
		if(opt==1)
		{
			read(l,r,x);
			if(bel[l]==bel[r])rebuild(bel[l],l,r,x);
			else
			{
				rebuild(bel[l],l,r,x),rebuild(bel[r],l,r,x);
				for(int i=bel[l]+1;i<bel[r];++i)
				{
					tag[i]+=x,chmin(tag[i],inf);
					if(cnt[i]<=S)rebuild(i,l,r,0);
					cnt[i]+=x,chmin(cnt[i],inf);
				}
			}
		}
		else
		{
			read(x,y);
			int lx=x,ly=y;
			while(x!=y)x>y?(lx=x,x=max(1,b[x]-tag[bel[x]])):(ly=y,y=max(1,b[y]-tag[bel[y]]));
			while(lx!=ly)lx>ly?lx=max(1,a[lx]-tag[bel[lx]]):ly=max(1,a[ly]-tag[bel[ly]]);
			printf("%d\n",lx);
		}
	}
	return 0;
}