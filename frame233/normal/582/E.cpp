// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
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
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=505;
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
char s[N];
int len;
int ls[N],rs[N];
char type[N];
int node_cnt;
int solve(int l,int r)
{
	if(l>r) return 0;
	int cnt=0;
	int cur=++node_cnt;
	for(int i=l;i<=r;++i)
	{
		if(s[i]=='(') ++cnt;
		else if(s[i]==')') --cnt;
		else if(!cnt)
		{
			type[cur]=s[i];
			ls[cur]=solve(l+1,i-2);
			rs[cur]=solve(i+2,r-1);
			return cur;
		}
	}
	return -1;
}
int f[9][1<<16];
void doit(int t,int qwq)
{
	for(int st=0;st<1<<16;++st)
	{
		bool flag=true;
		for(int i=0;i<16;++i)
		{
			flag&=((st>>i)&1)==(((i>>t)&1)^qwq);
		}
		if(flag) f[qwq*4+t][st]=1;
	}
}
int q[16];
void fwt_or(int *a,int limit){for(int len=2;len<=limit;len<<=1)for(int pos=0;pos<limit;pos+=len)for(int i=pos;i<pos+(len>>1);++i)add(a[i+(len>>1)],a[i]);}
void fwt_and(int *a,int limit){for(int len=2;len<=limit;len<<=1)for(int pos=0;pos<limit;pos+=len)for(int i=pos;i<pos+(len>>1);++i)add(a[i],a[i+(len>>1)]);}
void ifwt_or(int *a,int limit){for(int len=2;len<=limit;len<<=1)for(int pos=0;pos<limit;pos+=len)for(int i=pos;i<pos+(len>>1);++i)sub(a[i+(len>>1)],a[i]);}
void ifwt_and(int *a,int limit){for(int len=2;len<=limit;len<<=1)for(int pos=0;pos<limit;pos+=len)for(int i=pos;i<pos+(len>>1);++i)sub(a[i],a[i+(len>>1)]);}
int dp[N][1<<16];
int t1[1<<16],t2[1<<16],t3[1<<16];
void dfs(int x)
{
	if(ls[x])
	{
		dfs(ls[x]);
		dfs(rs[x]);
		if(type[x]=='&')
		{
			memcpy(t1,dp[ls[x]],sizeof(t1));
			memcpy(t2,dp[rs[x]],sizeof(t2));
			fwt_and(t1,1<<16);
			fwt_and(t2,1<<16);
			for(int i=0;i<1<<16;++i) dp[x][i]=1ll*t1[i]*t2[i]%mod;
			ifwt_and(dp[x],1<<16);
		}
		else if(type[x]=='|')
		{
			memcpy(t1,dp[ls[x]],sizeof(t1));
			memcpy(t2,dp[rs[x]],sizeof(t2));
			fwt_or(t1,1<<16);
			fwt_or(t2,1<<16);
			for(int i=0;i<1<<16;++i) dp[x][i]=1ll*t1[i]*t2[i]%mod;
			ifwt_or(dp[x],1<<16);
		}
		else
		{
			memcpy(t1,dp[ls[x]],sizeof(t1));
			memcpy(t2,dp[rs[x]],sizeof(t2));
			fwt_and(t1,1<<16);
			fwt_and(t2,1<<16);
			for(int i=0;i<1<<16;++i) dp[x][i]=1ll*t1[i]*t2[i]%mod;
			ifwt_and(dp[x],1<<16);
			memcpy(t1,dp[ls[x]],sizeof(t1));
			memcpy(t2,dp[rs[x]],sizeof(t2));
			fwt_or(t1,1<<16);
			fwt_or(t2,1<<16);
			for(int i=0;i<1<<16;++i) t3[i]=1ll*t1[i]*t2[i]%mod;
			ifwt_or(t3,1<<16);
			for(int i=0;i<1<<16;++i) add(dp[x][i],t3[i]);
		}
	}
	else
	{
		if(type[x]>='a'&&type[x]<='d')
		{
			memcpy(dp[x],f[type[x]-'a'+4],sizeof(dp[x]));
		}
		else if(type[x]>='A'&&type[x]<='D')
		{
			memcpy(dp[x],f[type[x]-'A'],sizeof(dp[x]));
		}
		else
		{
			memcpy(dp[x],f[8],sizeof(dp[x]));
		}
	}
}
int main()
{
	len=read_str(s+1);
	solve(1,len);
	for(int i=0;i<4;++i)
	{
		doit(i,0);
		doit(i,1);
	}
	for(int i=0;i<1<<16;++i)
	{
		for(int j=0;j<8;++j) add(f[8][i],f[j][i]);
	}
	int n;
	read(n);
	int a,b,c,d,e;
	memset(q,255,sizeof(q));
	for(int i=1;i<=n;++i)
	{
		read(a,b,c,d,e);
		q[a|(b<<1)|(c<<2)|(d<<3)]=e;
	}
	dfs(1);
	int ans=0;
	for(int st=0;st<1<<16;++st)
	{
		bool flag=true;
		for(int i=0;i<16;++i)
		{
			if(q[i]!=-1)
			{
				flag&=((st>>i)&1)==q[i];
			}
		}
		if(!flag) continue;
		add(ans,dp[1][st]);
	}
	printf("%d\n",ans);
	return 0;
}