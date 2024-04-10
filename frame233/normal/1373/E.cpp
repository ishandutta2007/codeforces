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

const int N=100005;
bool cmp(const std::string &a,const std::string &b)
{
	if(SZ(a)!=SZ(b)) return SZ(a)<SZ(b);
	for(int i=0;i<SZ(a);++i) if(a[i]!=b[i]) return a[i]<b[i];
	return false;
}
void MAIN()
{
	int n,k;
	read(n,k);
	std::string ans;
	for(int i=0;i<100;++i) ans.pb(57);
	std::string orig(ans);
	for(int i=0;i<10;++i)
	{
		if(i+k>=10)
		{
			int tmp=n;
			for(int j=i;j<=i+k;++j) tmp-=j%10;
			for(int j=0;tmp>=0;++j)
			{
				if(j) tmp-=(10-i)*9;
				int qwq=tmp-(i+k-9);
				if(qwq<0||qwq%(k+1)) continue;
				qwq/=k+1;
				std::string cur;
				cur.pb(i+48);
				for(int k=0;k<j;++k) cur.pb(57);
				bool first=true;
				while(qwq)
				{
					int qaq=first?8:9;
					first=false;
					if(qwq>qaq) cur.pb(qaq+48),qwq-=qaq;
					else cur.pb(qwq+48),qwq=0;
				}
				std::reverse(cur.begin(),cur.end());
				if(cmp(cur,ans)) ans=cur;
			}
		}
		else
		{
			int tmp=n;
			for(int j=i;j<=i+k;++j) tmp-=j;
			if(tmp<0||tmp%(k+1)) continue;
			tmp/=k+1;
			std::string cur;
			cur.pb(i+48);
			while(tmp)
			{
				if(tmp>9) cur.pb(57),tmp-=9;
				else cur.pb(tmp+48),tmp=0;
			}
			std::reverse(cur.begin(),cur.end());
			if(cmp(cur,ans)) ans=cur;
		}
	}
	if(ans==orig) printf("%d\n",-1);
	else printf("%s\n",ans.c_str());
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}