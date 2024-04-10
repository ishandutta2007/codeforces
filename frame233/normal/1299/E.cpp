// Author -- Frame

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

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
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

const int N=805;
int query(std::vector<int> v)
{
	printf("? %d ",SZ(v));
	for(auto it:v) printf("%d ",it);
	printf("\n");fflush(stdout);
	int x;read(x);return x;
}
int a[N],pos[N],n;
int main()
{
	read(n);
	bool fir=false;
	for(int i=1;i<=n;++i)
	{
		std::vector<int> tmp;
		for(int j=1;j<=n;++j) if(i!=j) tmp.pb(j);
		int x=query(tmp);
		if(x)
		{
			if(!fir) a[i]=1,fir=true,pos[1]=i;
			else a[i]=n,pos[n]=i;
		}
	}
	for(int k=2;k<=4&&k<=n>>1;++k)
	{
		for(int i=1;i<=n;++i)
		{
			if(a[i]) continue;
			std::vector<int> tmp;
			for(int j=1;j<=n;++j) if(i!=j&&(!a[j]||a[j]==k||a[j]==n-k+1)) tmp.pb(j);
			int x=query(tmp);
			if(x)
			{
				if(query({pos[1],i})==(k&1)) a[i]=k,pos[k]=i;
				else a[i]=n-k+1,pos[n-k+1]=i;
			}
		}
	}
	if(n<=8)
	{
		if(a[1]>(n>>1)) for(int i=1;i<=n;++i) a[i]=n+1-a[i];
		printf("! ");for(int i=1;i<=n;++i) printf("%d%c",a[i]," \n"[i==n]);
		fflush(stdout);
		return 0;
	}
	std::vector<std::vector<int> > v3,v5,v7;
	v3.pb({1,2}),v3.pb({1,3}),v3.pb({2,3});
	v5.pb({n-1,1,2,3}),v5.pb({n-1,1,2,4}),v5.pb({n-1,1,3,4}),v5.pb({n-1,2,3,4}),v5.pb({n,2,3,4});
	v7.pb({n-1,n-2,n-3,1,2,3}),v7.pb({n-1,n-2,n-3,1,2,4}),v7.pb({n-1,n-2,n-3,1,3,4});
	v7.pb({n-1,n-2,n-3,2,3,4}),v7.pb({n,n-1,n-2,1,2,4}),v7.pb({n,n-1,n-2,1,3,4}),v7.pb({n,n-1,n-2,2,3,4});
	for(auto &&it:v3) for(auto &&itt:it) itt=pos[itt];
	for(auto &&it:v5) for(auto &&itt:it) itt=pos[itt];
	for(auto &&it:v7) for(auto &&itt:it) itt=pos[itt];
	std::mt19937 _(std::chrono::steady_clock::now().time_since_epoch().count());
	for(int i=1;i<=n;++i)
	{
		if(!a[i])
		{
			std::vector<int> v;for(int j=0;j<3;++j) v.pb(j);
			std::shuffle(v.begin(),v.end(),_);
			int a3=-1,a5=-1,a7=-1;
			for(int j=0;j<3;++j)
			{
				std::vector<int> tmp(v3[v[j]]);tmp.pb(i);
				if(j+1==3||query(tmp))
				{
					a3=(33333-v[j])%3;
					break;
				}
			}
			for(int j=3;j<5;++j) v.pb(j);
			std::shuffle(v.begin(),v.end(),_);
			for(int j=0;j<5;++j)
			{
				std::vector<int> tmp(v5[v[j]]);tmp.pb(i);
				if(j+1==5||query(tmp))
				{
					a5=(55555-v[j]-n)%5;
					break;
				}
			}
			for(int j=5;j<7;++j) v.pb(j);
			std::shuffle(v.begin(),v.end(),_);
			for(int j=0;j<7;++j)
			{
				std::vector<int> tmp(v7[v[j]]);tmp.pb(i);
				if(j+1==7||query(tmp))
				{
					a7=(77777-v[j]-n-n-n)%7;
					break;
				}
			}
			assert(a3>=0),assert(a5>=0),assert(a7>=0);
			int a8;
			if(query({i,pos[2]})) // a[i] mod 2 =0 
			{
				if(query({i,pos[1],pos[3],pos[4]})) // a[i] mod 4 = 0
				{
					if(query({i,pos[1],pos[2],pos[3],pos[n],pos[n-3],pos[n-1],pos[n-2]})) // a[i] mod 8 = 0
					{
						a8=0;
					}
					else
					{
						a8=4;
					}
				}
				else // a[i] mod 4 = 2
				{
					if(query({i,pos[1],pos[3],pos[4],pos[n],pos[n-3],pos[n-1],pos[n-2]})) // a[i] mod 8 = 6
					{
						a8=6;
					}
					else
					{
						a8=2;
					}
				}
			}
			else // a[i] mod 2 = 1
			{
				if(query({i,pos[1],pos[2],pos[4]})) // a[i] mod 4 = 1
				{
					if(query({i,pos[2],pos[3],pos[4],pos[n],pos[n-1],pos[n-2],pos[n-3]}))
					{
						a8=5;
					}
					else
					{
						a8=1;
					}
				}
				else // a[i] mod 4 = 3
				{
					if(query({i,pos[1],pos[2],pos[4],pos[n],pos[n-1],pos[n-2],pos[n-3]}))
					{
						a8=7;
					}
					else
					{
						a8=3;
					}
				}
			}
			for(int j=1;j<=n;++j)
			{
				if(j%3==a3&&j%5==a5&&j%7==a7&&j%8==a8)
				{
					a[i]=j;
					pos[j]=i;
					break;
				}
			}
		}
	}
	if(a[1]>(n>>1)) for(int i=1;i<=n;++i) a[i]=n+1-a[i];
	printf("! ");for(int i=1;i<=n;++i) printf("%d%c",a[i]," \n"[i==n]);
	fflush(stdout);
	return 0;
}