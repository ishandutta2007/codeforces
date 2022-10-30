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
int x[5],y[5];
std::vector<pi> nd[5];
int calc(std::vector<pi> v)
{
	for(int i=0;i<4;++i) if(v[i].first!=x[i]&&v[i].second!=y[i]) return inf;
	int x1=inf,y1=inf,x2=-inf,y2=-inf;
	for(auto it:v) chmin(x1,it.first),chmin(y1,it.second),chmax(x2,it.first),chmax(y2,it.second);
	int c1=0,c2=0,c3=0,c4=0;
	for(auto it:v) c1+=it.first==x1,c2+=it.second==y1,c3+=it.first==x2,c4+=it.second==y2;
	if(c1!=2||c2!=2||c3!=2||c4!=2) return inf;
	if(x2>x1&&x2-x1==y2-y1)
	{
		int ans=0;
		for(int i=0;i<4;++i)
		{
			pi c=v[i];
			chmax(ans,abs(c.first-x[i])+abs(c.second-y[i]));
		}
		return ans;
	}
	else return inf;
}
void MAIN()
{
	for(int i=0;i<4;++i) read(x[i],y[i]),nd[i].clear();
	std::vector<int> qwq;
	for(int i=0;i<4;++i) for(int j=i+1;j<4;++j) qwq.pb(abs(x[i]-x[j])),qwq.pb(abs(y[i]-y[j]));
	std::sort(qwq.begin(),qwq.end());
	qwq.erase(std::unique(qwq.begin(),qwq.end()),qwq.end());
	std::vector<pi> v;
	for(int i=0;i<4;++i) for(int j=i;j<4;++j) v.pb(mkpr(x[i],y[j])),v.pb(mkpr(x[j],y[i]));
	std::sort(v.begin(),v.end()),v.erase(std::unique(v.begin(),v.end()),v.end());
	int ans=inf;pi _A,_B,_C,_D;
	for(auto d:qwq)
	{
		std::vector<pi> a(v);
		for(int i=0;i<4;++i)
		{
			for(int j=0;j<4;++j)
			{
				a.pb(mkpr(x[i]-d,y[j]));
				a.pb(mkpr(x[i]+d,y[j]));
				a.pb(mkpr(x[j],y[i]-d));
				a.pb(mkpr(x[j],y[i]+d));
				
				int tmp=abs(d-abs(x[i]-x[j]))>>1;
				a.pb(mkpr(x[i]-tmp,y[i]));
				a.pb(mkpr(x[i]+tmp,y[i]));
				++tmp;
				a.pb(mkpr(x[i]-tmp,y[i]));
				a.pb(mkpr(x[i]+tmp,y[i]));
				
				tmp=abs(x[i]-x[j])>>1;
				a.pb(mkpr(x[i]-tmp,y[i]));
				a.pb(mkpr(x[i]+tmp,y[i]));
				++tmp;
				a.pb(mkpr(x[i]-tmp,y[i]));
				a.pb(mkpr(x[i]+tmp,y[i]));
				
				tmp=abs(d-abs(y[i]-y[j]))>>1;
				a.pb(mkpr(x[i],y[i]-tmp));
				a.pb(mkpr(x[i],y[i]+tmp));
				++tmp;
				a.pb(mkpr(x[i],y[i]-tmp));
				a.pb(mkpr(x[i],y[i]+tmp));
				
				tmp=abs(y[i]-y[j])>>1;
				a.pb(mkpr(x[i],y[i]-tmp));
				a.pb(mkpr(x[i],y[i]+tmp));
				++tmp;
				a.pb(mkpr(x[i],y[i]-tmp));
				a.pb(mkpr(x[i],y[i]+tmp));
			}
		}
		std::sort(a.begin(),a.end());
		a.erase(std::unique(a.begin(),a.end()),a.end());
		for(auto it:a)
		{
			for(int b=-1;b<=1;++b)
			{
				if(!b) continue;
				for(int c=-1;c<=1;++c)
				{
					if(!c) continue;
					std::vector<pi> v({it,mkpr(it.first+b*d,it.second),mkpr(it.first,it.second+c*d),mkpr(it.first+b*d,it.second+c*d)});
					std::sort(v.begin(),v.end());
					do{
						int tmp=calc(v);
						if(ans>tmp)
						{
							ans=tmp;
							_A=v[0],_B=v[1],_C=v[2],_D=v[3];
						}
					}while(std::next_permutation(v.begin(),v.end()));
					
				}
			}
		}
	}
	if(ans==inf) printf("-1\n");
	else printf("%d\n%d %d\n%d %d\n%d %d\n%d %d\n",ans,_A.first,_A.second,_B.first,_B.second,_C.first,_C.second,_D.first,_D.second);
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}