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
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
std::vector<std::string> ans;
int st[25],top;
std::string NtoS(ll x)
{
	std::string t;
	if(!x) return "0";
	while(x)
	{
		st[++top]=x%10;
		x/=10;
	}
	while(top) t.pb(st[top--]+48);
	return t;
}
std::string A(ll x,ll y)
{
	return NtoS(x)+" + "+NtoS(y);
}
std::string B(ll x,ll y)
{
	return NtoS(x)+" ^ "+NtoS(y);
}
void mul(ll x,ll k)
{
	ll a=x,res=a;
	--k;
	while(k)
	{
		if(k&1) ans.pb(A(res,a)),res+=a;
		ans.pb(A(a,a)),a+=a,k>>=1;
	}
}
int main()
{
	int x;read(x);
	int tmp=0;for(int i=0;i<=20;++i) if((x>>i)&1) tmp=i;
	mul(x,1<<tmp);
	ans.pb(B(x,(ll)x<<tmp));
	ll a=x,b=x^((ll)x<<tmp);
	for(ll i=1;i<=a+a;++i)
	{
		ll tmp=i*b;
		tmp^=1;
		if(tmp%a==0)
		{
			mul(a,tmp/a);
			mul(b,i);
			ans.pb(B(i*b,tmp));
			break;
		}
	}
	printf("%d\n",SZ(ans));
	for(auto it:ans) printf("%s\n",it.c_str());
	return 0;

}