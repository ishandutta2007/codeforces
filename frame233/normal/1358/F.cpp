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
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=0x05ad13b4;
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
bool ck1(const std::vector<ll> &v)
{
	ll last=0;
	for(auto it:v)if(it<last) return false;else last=it;
	return true;
}
bool ck2(const std::vector<ll> &v)
{
	ll last=1e18;
	for(auto it:v)if(it>last) return false;else last=it;
	return true;
}
std::vector<ll> rev(std::vector<ll> v)
{
	std::reverse(v.begin(),v.end());
	return v;
}
void do1(std::vector<ll> &v){for(int i=SZ(v)-1;i>=1;--i) v[i]-=v[i-1];}
void do2(std::vector<ll> &v)
{
	for(int i=0;i+1<SZ(v);++i) v[i]-=v[i+1];
	std::reverse(v.begin(),v.end());
}
bool ck(const std::vector<ll> &v)
{
	for(auto it:v) if(it<=0) return false;
	return true;
}
int count(std::string s)
{
	if(s[0]=='I') return 1e9;
	int ans=0;
	for(auto it:s) ans+=it=='P';
	return ans;
}
void print(const std::vector<ll> &v)
{
	for(auto it:v) printf("%lld ",it);
	printf("\n");
}
std::string solve(std::vector<ll> v1,std::vector<ll> v2)
{
	if(v1==v2) return "";
	std::string ans;
	while(v1!=v2&&rev(v1)!=v2&&ck(v2))
	{
		if(ck1(v2)) do1(v2),ans+="P";
		else if(ck2(v2)) do2(v2),ans+="RP";
		else return "IMPOSSIBLE";
	}
	if(!ck(v2)) return "IMPOSSIBLE";
	if(v1!=v2) ans+="R";
	std::reverse(ans.begin(),ans.end());
	return ans;
}
void _solve(std::vector<ll> v1,std::vector<ll> v2)
{
	if(v1==v2||rev(v1)==v2) return;
	ll A=v1[0],B=v1[1];
	ll cnt=0;
	while(v1!=v2&&rev(v1)!=v2&&ck(v2))
	{
		ll a=v2[0],b=v2[1];
		if(a<b) std::swap(a,b);
		if(b==B&&a>=A&&(a-A)%b==0)
		{
			cnt+=(a-A)/b;
			if(cnt>200000)
			{
				printf("BIG\n%lld\n",cnt);
				exit(0);
			}
			return;
		}
		std::swap(A,B);
		if(b==B&&a>=A&&(a-A)%b==0)
		{
			cnt+=(a-A)/b;
			if(cnt>200000)
			{
				printf("BIG\n%lld\n",cnt);
				exit(0);
			}
			return;
		}
		cnt+=a/b;
		a%=b;
		v2[0]=a,v2[1]=b;
	}
	printf("IMPOSSIBLE\n");
	exit(0);
}
int main()
{
	int n;
	read(n);
	std::vector<ll> a(n),b(n);
	for(auto &&it:a) read(it);
	for(auto &&it:b) read(it);
	if(a==b)
	{
		printf("SMALL\n0\n\n");
		return 0;
	}
	if(n==1)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	if(n==2)
	{
		_solve(a,b);
	}
	std::string A=solve(a,b);
	std::string B=solve(a,rev(b));
	B+="R";
	if(A[0]=='I'&&B[0]=='I') printf("%s\n",A.c_str());
	else if(min(count(A),count(B))>200000) printf("BIG\n%d\n",min(count(A),count(B)));
	else
	{
		if(count(A)<=count(B)) printf("SMALL\n%d\n%s\n",SZ(A),A.c_str());
		else printf("SMALL\n%d\n%s\n",SZ(B),B.c_str());
	}
	return 0;
}