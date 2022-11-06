#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define fan(x) (((x-1)^1)+1)
#define max Max
#define min Min
#define abs Abs

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=1e5+5;
int t,n,x,y;
char s[N];

signed main()
{
	t=read();
    while(t--)
    {
        x=read(),y=read();
        scanf("%s",s+1);
        n=strlen(s+1);
        int a=0,b=0,c=0,d=0;
        for(int i=1;i<=n;++i)
            if(s[i]=='U') b++;
            else if(s[i]=='D') d++;
            else if(s[i]=='R') a++;
            else c++;
        if(x<0) x=-x,swap(a,c);
        if(y<0) y=-y,swap(b,d);
        if(a>=x&&b>=y) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}