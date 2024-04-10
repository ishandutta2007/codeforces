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

const int N=500005;
int val,k;
ll b;
std::set<ll> S;
int a[N];
void MAIN()
{
	int n;read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	S.clear();
	k=1,b=0,val=1;
	int L=1,R=1e9;
	for(int i=1;i<=n;++i)
	{
		k=-k,b=a[i]-b;
		L=a[i]-L,R=a[i]-R;
		std::swap(L,R);
		chmax(L,1),chmin(R,a[i]-1);
		if(L>R) L=1,R=0;
		int A=val+1;
		if(!(a[i]&1))
		{
			int cur=((L<=(a[i]>>1)&&(a[i]>>1)<=R)||S.find(((a[i]>>1)-b)*k)!=S.end())?val:val+1;
			if(cur==A) S.insert(((a[i]>>1)-b)*k);
			else
			{
				A=cur;
				L=1,R=0;
				k=1,b=0;
				S={a[i]>>1};
			}
		}
		while(!S.empty()&&*S.begin()*k+b<=0) S.erase(S.begin());
		while(!S.empty()&&*S.begin()*k+b>=a[i]) S.erase(S.begin());
		while(!S.empty()&&*S.rbegin()*k+b<=0) S.erase(--S.end());
		while(!S.empty()&&*S.rbegin()*k+b>=a[i]) S.erase(--S.end());
		chmax(L,1),chmin(R,a[i]-1);
		if(L>R) L=1,R=0;
		val=A;
		if(S.empty()&&L>R)
		{
			L=1,R=a[i]-1;
			++val;
		}
	}
	printf("%d\n",val);
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}