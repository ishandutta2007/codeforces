// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
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

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
struct BIT{
	int c[N];
	Finline void add(int x,int C){for(;x<N;x+=lowbit(x))c[x]+=C;}
	Finline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr1,tr2;
int v[N];
int a[N],b[N],c[N];
int s1[N],s2[N];
bool used[N];
int main()
{
	int n,m,k;
	read(n,m,k);
	int p1=0,p2=0,p3=0;
	int x,y;
	for(int i=1;i<=n;++i)
	{
		read(v[i]);
		read(x,y);
		if(x==1&&y==1) a[++p1]=i,tr1.add(v[i],1),tr2.add(v[i],v[i]);
		else if(x==1) b[++p2]=i;
		else if(y==1) c[++p3]=i;
		else tr1.add(v[i],1),tr2.add(v[i],v[i]);
	}
	std::sort(a+1,a+p1+1,[&](int A,int B)->bool{return v[A]<v[B];});
	std::sort(b+1,b+p2+1,[&](int A,int B)->bool{return v[A]<v[B];});
	std::sort(c+1,c+p3+1,[&](int A,int B)->bool{return v[A]<v[B];});
	for(int i=1;i<=p2;++i) s1[i]=s1[i-1]+v[b[i]];
	for(int i=1;i<=p3;++i) s2[i]=s2[i-1]+v[c[i]];
	int ans=Inf,sum=0;
	int c2=p2,c3=p3;
	int pos=-1;
	for(int r=0;r<=p1&&r<=k;++r)
	{
		if(r)
		{
			tr1.add(v[a[r]],-1);
			tr2.add(v[a[r]],-v[a[r]]);
			sum+=v[a[r]];
		}
		if(k-r>p2||k-r>p3) continue;
		int tmp=sum+s1[k-r]+s2[k-r];
		while(c2>k-r)
		{
			tr1.add(v[b[c2]],1);
			tr2.add(v[b[c2]],v[b[c2]]);
			--c2;
		}
		while(c3>k-r)
		{
			tr1.add(v[c[c3]],1);
			tr2.add(v[c[c3]],v[c[c3]]);
			--c3;
		}
		int rest=m-r-(k-r)*2;
		if(rest<0) continue;
		if(rest>0)
		{
			int l=1,r=10000;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(tr1.sum(mid)>=rest) r=mid;
				else l=mid+1;
			}
			tmp+=tr2.sum(l)-(tr1.sum(l)-rest)*l;
		}
		if(ans>tmp) ans=tmp,pos=r;
	}
	if(ans==Inf) return puts("-1"),0;
	printf("%d\n",ans);
	std::vector<int> v,qwq;
	for(int i=1;i<=pos;++i) v.pb(a[i]);
	for(int i=1;i<=k-pos;++i) v.pb(b[i]),v.pb(c[i]);
	for(auto it:v) used[it]=true;
	for(int i=1;i<=n;++i) if(!used[i]) qwq.pb(i);
	std::sort(qwq.begin(),qwq.end(),[&](int A,int B)->bool{return ::v[A]<::v[B];});
	for(int i=0;i<m-pos-(k-pos)*2;++i) v.pb(qwq[i]);
	std::sort(v.begin(),v.end());
	for(auto it:v) printf("%d ",it);
	printf("\n");
	return 0;
}