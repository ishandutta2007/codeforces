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
int a[N];
int t[N];
std::vector<int> v[N];
void MAIN()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) v[i].clear();
	int pos=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		t[++pos]=a[i];
	}
	std::sort(t+1,t+pos+1);
	pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i) a[i]=std::lower_bound(t+1,t+pos+1,a[i])-t;
	for(int i=1;i<=n;++i) v[a[i]].pb(i);
	int ans=0;
	for(int i=1;i<=pos;++i)
	{
		int j=i;
		int tmp=SZ(v[i]);
		while(j<pos&&v[j+1][0]>v[j].back()) ++j,tmp+=SZ(v[j]);
		if(i>1) tmp+=std::lower_bound(v[i-1].begin(),v[i-1].end(),v[i][0])-v[i-1].begin();
		if(j<pos) tmp+=v[j+1].end()-std::lower_bound(v[j+1].begin(),v[j+1].end(),v[j].back());
		chmax(ans,tmp);
		i=j;
	}
	for(int i=1;i<pos;++i)
	{
		for(int j=0;j<SZ(v[i]);++j)
		{
			int tmp=j+1+(v[i+1].end()-std::lower_bound(v[i+1].begin(),v[i+1].end(),v[i][j]));
			chmax(ans,tmp);
		}
	}
	printf("%d\n",n-ans);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}