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
#define mp(x,y) make_pair(x,y)
#define lc (x<<1)
#define rc (x<<1|1)
#define fi first
#define se second
#define mid ((l+r)>>1)
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
int t,n,k,sum[N][30];
char s[N];

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();k=read();
		scanf("%s",s+1);
		int flag=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=26;++j)
				sum[i][j]=sum[i-1][j];
			sum[i][s[i]-'a'+1]++;
		}
		for(int i=1;i<=26;++i)
			if(sum[n][i]%k!=0)
				flag=0;
		if(flag)
		{
			puts(s+1);
			continue;
		}
		int res=-1,mx,pos;
		for(int i=n;i>=1;--i)
		{
			if(s[i]=='z') continue;
			int tmp=0;
			mx=-1e18,pos=-1;
			for(int j=1;j<=26;++j)
			{
				if(j>=s[i]-'a'+2)
				{
					if((k-sum[i-1][j]%k)%k-(k-(sum[i-1][j]+1)%k)%k>mx)
						mx=(k-sum[i-1][j]%k)%k-(k-(sum[i-1][j]+1)%k)%k,pos=j;
				}
				tmp+=(k-sum[i-1][j]%k)%k;
			}
			tmp-=(k-sum[i-1][s[i]-'a'+2]%k)%k;
			tmp+=(k-(sum[i-1][s[i]-'a'+2]+1)%k)%k;
			if(n-i<tmp) goto ne;
			if((n-i-tmp)%k!=0) goto ne;
			res=i;pos=s[i]-'a'+2;break;
				
ne:			tmp+=(k-sum[i-1][s[i]-'a'+2]%k)%k;
			tmp-=(k-(sum[i-1][s[i]-'a'+2]+1)%k)%k;
			tmp-=(k-sum[i-1][pos]%k)%k;
			tmp+=(k-(sum[i-1][pos]+1)%k)%k;
			if(n-i<tmp) continue;
			if((n-i-tmp)%k!=0) continue;
			res=i;break;
		}
		if(res==-1)
		{
			printf("-1\n");
			continue;
		}
		s[res]=pos+'a'-1;
		int now=res;
		for(int i=1;i<=26;++i)
		{
			int tmp=(k-sum[res-1][i]%k)%k;
			if(i==s[res]-'a'+1) tmp=(k-(sum[res-1][i]+1)%k)%k;
			for(int j=1;j<=tmp;++j)
				s[++now]=i+'a'-1;
		}
		while(now<n) s[++now]='a';
		sort(s+res+1,s+n+1);
		puts(s+1);
	}
	return 0;
}