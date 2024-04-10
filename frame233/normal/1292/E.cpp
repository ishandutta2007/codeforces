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
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
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
const char dict[]={'C','H','O'};
std::vector<int> Query(std::string s)
{
	printf("? %s\n",s.c_str());
	fflush(stdout);
	int k;read(k);std::vector<int> v(k);
	for(auto &&it:v) read(it),--it;
	return v;
}
void report(std::string s)
{
	printf("! %s\n",s.c_str());
	fflush(stdout);
	int x;read(x);assert(x==1);
}
void MAIN()
{
	int n;read(n);
	std::string ans;ans.resize(n);
	if(n==4)
	{
		std::vector<int> CH=Query("CH"),CO=Query("CO"),HO=Query("HO"),HC=Query("HC");
		if(!CH.empty()||!CO.empty()||!HO.empty()||!HC.empty())
		{
			for(auto it:CH) ans[it]='C',ans[it+1]='H';
			for(auto it:CO) ans[it]='C',ans[it+1]='O';
			for(auto it:HO) ans[it]='H',ans[it+1]='O';
			for(auto it:HC) ans[it]='H',ans[it+1]='C';
			std::string s;s.resize(n);
			std::vector<std::string> valid;
			for(int a=0;a<3;++a)
			{
				for(int b=0;b<3;++b)
				{
					for(int c=0;c<3;++c)
					{
						for(int d=0;d<3;++d)
						{
							s[0]=dict[a],s[1]=dict[b],s[2]=dict[c],s[3]=dict[d];
							auto check=[&](std::string s)->bool
							{
								for(int i=0;i<n;++i) if(ans[i]&&ans[i]!=s[i]) return false;
								for(int i=0;i+1<n;++i)
								{
									if(s.substr(i,2)=="CH"&&std::find(CH.begin(),CH.end(),i)==CH.end()) return false;
									if(s.substr(i,2)=="CO"&&std::find(CO.begin(),CO.end(),i)==CO.end()) return false;
									if(s.substr(i,2)=="HO"&&std::find(HO.begin(),HO.end(),i)==HO.end()) return false;
									if(s.substr(i,2)=="HC"&&std::find(HC.begin(),HC.end(),i)==HC.end()) return false;
								}
								return true;
							};
							if(check(s)) valid.pb(s);
						}
					}
				}
			}
			for(int i=0;i+1<SZ(valid);++i)
			{
				if(!Query(valid[i]).empty())
				{
					report(valid[i]);
					return;
				}
			}
			report(valid.back());
			return;
		}
		else
		{
			std::vector<int> OOO=Query("OOO"),CCC=Query("CCC"),HHH=Query("HHH");
			if(!OOO.empty())
			{
				if(SZ(OOO)==2) report("OOOO");
				else
				{
					ans[0]=ans[1]=ans[2]='O';
					ans[3]='C';
					if(!Query(ans).empty())report(ans);
					else
					{
						ans[3]='H';
						report(ans);
					}
				}
			}
			else if(!CCC.empty())
			{
				if(CCC[0]==0) report("CCCC");
				else report("OCCC");
			}
			else if(!HHH.empty())
			{
				if(HHH[0]==0) report("HHHH");
				else report("OHHH");
			}
			else
			{
				if(!Query("OOCC").empty()) report("OOCC");
				else report("OOHH");
			}
			return;
		}
	}
	else
	{
		std::string ans;ans.resize(n);
		std::vector<int> CC=Query("CC"),CH=Query("CH"),CO=Query("CO"),HO=Query("HO"),OO=Query("OO");
		for(auto it:CC) ans[it]='C',ans[it+1]='C';
		for(auto it:CH) ans[it]='C',ans[it+1]='H';
		for(auto it:CO) ans[it]='C',ans[it+1]='O';
		for(auto it:HO) ans[it]='H',ans[it+1]='O';
		for(auto it:OO) ans[it]='O',ans[it+1]='O';
		for(int i=1;i+1<n;++i) if(!ans[i]) ans[i]='H';
		std::string s=ans;
		(!ans[0])&&(ans[0]='O');(!ans[n-1])&&(ans[n-1]='C');if(!Query(ans).empty()){report(ans);return;}
		ans=s;(!ans[0])&&(ans[0]='O');(!ans[n-1])&&(ans[n-1]='H');if(!Query(ans).empty()){report(ans);return;}
		ans=s;(!ans[0])&&(ans[0]='H');(!ans[n-1])&&(ans[n-1]='C');if(!Query(ans).empty()){report(ans);return;}
		ans=s;(!ans[0])&&(ans[0]='H');(!ans[n-1])&&(ans[n-1]='H');report(ans);
	}
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}