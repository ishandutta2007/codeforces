// Fresh Peach Heart Shower
#include <bits/stdc++.h>
#define reg
#define ALL(x) (x).begin(),(x).end()
#define mem(x,y) memset(x,y,sizeof x)
#define sz(x) (int)(x).size()
#define ln putchar('\n')
#define lsp putchar(32)
#define pb push_back
#define MP std::make_pair
#define MT std::make_tuple
#ifdef _LOCAL_
#define dbg(x) std::cerr<<__func__<<"\tLine:"<<__LINE__<<' '<<#x<<": "<<x<<"\n"
#define dprintf(x...) std::fprintf(stderr,x)
#else
#define dbg(x) 42
#define dprintf(x...) 42
#endif
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
typedef std::pair<int,int> pii;
typedef std::vector<int> poly;
template <class t> inline void read(t &s){s=0;
signed f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=getchar();;s*=f;}
template<class t,class ...A> inline void read(t &x,A &...a){read(x);read(a...);}
template <class t> inline void write(t x){if(x<0)putchar('-'),x=-x;
static int buf[50],top=0;while(x)buf[++top]=x%10,x/=10;if(!top)buf[++top]=0;
while(top)putchar(buf[top--]^'0');}
inline void setIn(std::string s){freopen(s.c_str(),"r",stdin);return;}
inline void setOut(std::string s){freopen(s.c_str(),"w",stdout);return;}
inline void setIO(std::string s=""){setIn(s+".in");setOut(s+".out");return;}
template <class t>inline bool ckmin(t&x,t y){if(x>y){x=y;return 1;}return 0;}
template <class t>inline bool ckmax(t&x,t y){if(x<y){x=y;return 1;}return 0;}
inline int lowbit(int x){return x&(-x);}
const int MaxN=1050;
const int p=998244353;
char s[MaxN];
int f[MaxN],dp[18][1<<17],pw[18][MaxN],n;
inline void add(int &x,int y){(x+=y)>=p&&(x-=p);}
signed main(void)
{
	read(n);
	std::scanf("%s",s+1);
	rep(i,1,n)f[i]=f[i-1]+(s[i]=='?');
	rep(x,1,17)
	{
		pw[x][0]=1;
		rep(i,1,n)pw[x][i]=1LL*pw[x][i-1]*x%p;
	}
	rep(i,1,n)
	{
		rep(x,1,17) // odd
		{
			int mask=0,ext=s[i]=='?'?x:1,rem=f[n];
			rem-=s[i]=='?';
			add(dp[x][mask],1LL*ext*pw[x][rem]%p);
			rep(j,1,std::min(i-1,n-i))
			{
				rem-=s[i-j]=='?';
				rem-=s[i+j]=='?';
				if(s[i-j]==s[i+j])
				{
					if(s[i-j]=='?')ext=1LL*ext*x%p;
				}
				else
				{
					if(s[i-j]=='?')mask|=(1<<(s[i+j]-'a'));
					else if(s[i+j]=='?')mask|=(1<<(s[i-j]-'a'));
					else ext=0;
				}
				if(!ext)break;
				add(dp[x][mask],1LL*ext*pw[x][rem]%p);
			}
		}
		if(i<n)
		rep(x,1,17) //even
		{
			int mask=0,ext=1,rem=f[n];
			rep(j,0,std::min(i-1,n-i-1))
			{
				rem-=s[i-j]=='?';
				rem-=s[i+j+1]=='?';
				if(s[i-j]==s[i+j+1])
				{
					if(s[i-j]=='?')ext=1LL*ext*x%p;
				}
				else
				{
					if(s[i-j]=='?')mask|=(1<<(s[i+j+1]-'a'));
					else if(s[i+j+1]=='?')mask|=(1<<(s[i-j]-'a'));
					else ext=0;
				}
				if(!ext)break;
				add(dp[x][mask],1LL*ext*pw[x][rem]%p);
			}
		}
	}
	rep(x,1,17)rep(j,0,16)rep(i,0,(1<<17)-1)if(i>>j&1)add(dp[x][i],dp[x][i^(1<<j)]);
	int q,w;read(q);
	while(q--)
	{
		std::scanf("%s",s+1);
		w=0;
		int m=std::strlen(s+1);
		rep(j,1,m)w|=(1<<(s[j]-'a'));
		write(dp[__builtin_popcount(w)][w]),ln;
	}
	return 0;
}

/*
 * Check List:
 * 1. Input / Output File (OI)
 * 2. long long 
 * 3. Special Test such as n=1
 * 4. Array Size
 * 5. Memory Limit (OI) int is 4 and longlong is 8
 * 6. Mod (a*b%p*c%p not a*b*c%p  ,  (a-b+p)%p not a-b )
 * 7. Name ( int k; for(int k...))
 * 8. more tests , (T=2 .. more)
 * 9. blank \n after a case
*/