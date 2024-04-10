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
using std::string;
string ans;
Finline char rev(char ch)
{
	if(ch=='l') return 'r';
	if(ch=='r') return 'l';
	if(ch=='u') return 'd';
	if(ch=='d') return 'u';
	assert(0);
}
Finline void copy(char ch) // poing at new
{
	ans.pb(ch);
	ans+="10",ans.pb(rev(ch)),ans.pb('t');
}
Finline void move(char ch)
{
	copy(ch);
	ans.pb(rev(ch));
	ans.pb('e');
	ans.pb(ch);
}
Finline void _and()
{
	ans+="0ut";
}
Finline void _or()
{
	ans+="ust1ddsutu";
}
Finline void ops()
{
	copy('r');
	ans+="01lt";
	move('l');
}
Finline void _xor()
{
	ans+="ust";
	ops();
	ans+="ddsutu";
}
Finline void init()
{
	for(int i=0;i<=30;++i) ans.pb('l');
	for(int i=0;i<=30;++i) ans+="srt0";
	for(int i=0;i<=30;++i) ans.pb('r');
	for(int i=0;i<=30;++i) ans+="slt";
	ans.pb('l');
}
int main()
{
	ans+="rd0ul";
	init();ans+="u";
	init();ans+="d";
	for(int i=0;i<=30;++i)
	{
		copy('r'),ans+="ul",copy('r'),ans+="dd";
		copy('l');ans+="r";
		_xor();move('u');
		_xor(),move('u'),move('u'),move('l'),move('u');
		
		ans+="ddd";
		copy('r'),ans+="dl",copy('r');
		_and(),copy('r');
		
		ans+="lluu";
		copy('r');
		move('d');
		ans+="dl";copy('r');_and();
		ans+="lu";_and();
		
		copy('r');ans+="d";_or();
		ans+="r",move('u'),move('l'),ans+="d",_or();
		move('l');
		ans+="ul";
	}
	ans+="uuur";
	std::cout<<ans<<std::endl;
	return 0;
}