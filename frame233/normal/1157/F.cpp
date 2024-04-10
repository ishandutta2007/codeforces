#include<cstdio>
#include<cstring>
#include<algorithm>

typedef long long ll;

template <typename T>T gcd(const T &a,const T &b){return (!b)?a:gcd(b,a%b);}
template <typename T>inline T abs(const T &a){return a>0?a:-a;}
template <typename T>inline T max(const T &a,const T &b){return a<b?b:a;}
template <typename T>inline T min(const T &a,const T &b){return a<b?a:b;}
template <typename T>inline void chmax(T &a,const T &b){(a<b)&&(a=b);}
template <typename T>inline void chmin(T &a,const T &b){(a>b)&&(a=b);}

template <typename T>inline void read(T& x)
{
    register char ch=getchar();
    while(ch<48||ch>57) ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
}
template <typename T,typename... Args> inline void read(T& t, Args&... args)
{
    read(t);read(args...);
}

const int N=200005;
int cnt[N],l[N],r[N],sum[N];
int main()
{
	int n,x;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(x);
		++cnt[x];
	}
	l[0]=1;
	for(int i=1;i<=200000;++i)
	{
		sum[i]=sum[i-1]+cnt[i];
		if(cnt[i]>=2)
		{
			l[i]=min(i,l[i-1]);
		}
		else
		{
			l[i]=i+1;
		}
	}
	r[200001]=200000;
	for(int i=200000;i>=1;--i)
	{
		if(cnt[i]>=2)
		{
			r[i]=max(i,r[i+1]);
		}
		else
		{
			r[i]=i-1;
		}
	}
	int ans=0,L=0,R=0;
	for(int i=1;i<=200000;++i)
	{
		int _l=l[i],_r=r[i];
		if(cnt[_l-1]==1) --_l;
		if(cnt[_r+1]==1) ++_r;
		if(ans<sum[_r]-sum[_l-1])
		{
			ans=sum[_r]-sum[_l-1];
			L=_l,R=_r;
		}
	}
	for(int i=1;i<200000;++i)
	{
		if(cnt[i]==1&&cnt[i+1]==1)
		{
			if(ans<2)
			{
				ans=2;
				L=i,R=i+1;
				break;
			}
		}
	}
	printf("%d\n",ans);
	for(int i=L;i<=R;++i)
	{
		printf("%d ",i);
		--cnt[i];
	}
	for(int i=R;i>=L;--i)
	{
		for(int j=cnt[i];j>=1;--j)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}
//Frame