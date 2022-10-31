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
typedef std::pair<int,int> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&((a=b),1);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&((a=b),1);}
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

const int N=200015;
int a[N+1],b[N+2],c[N+3],cnt[N+4],sum[N+5];
int t[N+6];
struct node{
	int val,id;
	Finline bool operator < (const node &o)const
	{
		return val<o.val;
	}
	Finline node operator + (const int &o)const
	{
		return (node){val+o,id};
	}
	Finline node operator - (const int &o)const
	{
		return (node){val-o,id};
	}
}dp[N+7];
int opt[N];
const int D=100005;
struct BIT1{
	node c[N];
	Finline BIT1(){for(int i=0;i<N;++i)c[i]=(node){-inf,-1};}
	int st[N],top;
	Finline void add(int x,node C){x+=D;st[++top]=x;for(;x<N;x+=lowbit(x))chmax(c[x],C);}
	Finline node sum(int x){x+=D;node ans=(node){-inf,-1};for(;x;x-=lowbit(x))chmax(ans,c[x]);return ans;}
	Finline void clear()
	{
		while(top)
		{
			for(int x=st[top];x<N;x+=lowbit(x))c[x]=(node){-inf,-1};
			--top;
		}
	}
}tr1;
struct BIT2{
	node c[N];
	int st[N],top;
	Finline BIT2(){for(int i=0;i<N;++i)c[i]=(node){-inf,-1};}
	Finline void add(int x,node C){x+=D;st[++top]=x;for(;x;x-=lowbit(x))chmax(c[x],C);}
	Finline node sum(int x){x+=D;node ans=(node){-inf,-1};for(;x<N;x+=lowbit(x))chmax(ans,c[x]);return ans;}
	Finline void clear()
	{
		while(top)
		{
			for(int x=st[top];x;x-=lowbit(x))c[x]=(node){-inf,-1};
			--top;
		}
	}
}tr2;
void solve(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)>>1;
	solve(l,mid);
	int i=l,j=mid+1;
	for(int i=l;i<=r;++i) c[i]=i;
	std::sort(c+l,c+mid+1,[](int A,int B)->bool{return a[A]<a[B];});
	std::sort(c+mid+1,c+r+1,[](int A,int B)->bool{return a[A]<a[B];});
	while(i<=mid&&j<=r)
	{
		if(a[c[i]]<a[c[j]])
		{
			if(a[c[i]]!=-1)
			{
				tr1.add(cnt[a[c[i]]]-sum[c[i]],dp[c[i]]-sum[c[i]]);
				tr2.add(cnt[a[c[i]]]-sum[c[i]],dp[c[i]]-cnt[a[c[i]]]);
			}
			++i;
		}
		else
		{
			if(a[c[j]]!=-1)
			{
				node tmp=tr1.sum(cnt[a[c[j]]-1]-sum[c[j]])+sum[c[j]]+1;
				if(dp[c[j]]<tmp)
				{
					dp[c[j]].val=tmp.val;
					opt[c[j]]=tmp.id;
				}
				tmp=tr2.sum(cnt[a[c[j]]-1]-sum[c[j]])+cnt[a[c[j]]-1]+1;
				if(dp[c[j]]<tmp)
				{
					dp[c[j]].val=tmp.val;
					opt[c[j]]=tmp.id;
				}
			}
			++j;
		}
	}
	while(i<=mid)
	{
		if(a[c[i]]!=-1)
		{
			tr1.add(cnt[a[c[i]]]-sum[c[i]],dp[c[i]]-sum[c[i]]);
			tr2.add(cnt[a[c[i]]]-sum[c[i]],dp[c[i]]-cnt[a[c[i]]]);
		}
		++i;
	}
	while(j<=r)
	{
		if(a[c[j]]!=-1)
		{
			node tmp=tr1.sum(cnt[a[c[j]]-1]-sum[c[j]])+sum[c[j]]+1;
			if(dp[c[j]]<tmp)
			{
				dp[c[j]].val=tmp.val;
				opt[c[j]]=tmp.id;
			}
			tmp=tr2.sum(cnt[a[c[j]]-1]-sum[c[j]])+cnt[a[c[j]]-1]+1;
			if(dp[c[j]]<tmp)
			{
				dp[c[j]].val=tmp.val;
				opt[c[j]]=tmp.id;
			}
		}
		++j;
	}
	tr1.clear();
	tr2.clear();
	solve(mid+1,r);
}
int ans[N];
int f[N];
int main()
{
	int n;
	read(n);
	int pos=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		if(~a[i]) t[++pos]=a[i];
		sum[i]=sum[i-1]+(a[i]==-1);
	}
	sum[n+1]=sum[n];
	int m;
	read(m);
	for(int i=1;i<=m;++i)
	{
		read(b[i]);
		t[++pos]=b[i];
	}
	a[0]=t[++pos]=0;
	a[n+1]=t[++pos]=1000000001;
	std::sort(t+1,t+pos+1);
	pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=0;i<=n+1;++i)
	{
		if(~a[i]) a[i]=std::lower_bound(t+1,t+pos+1,a[i])-t;
	}
	std::multiset<int> S;
	for(int i=1;i<=m;++i)
	{
		b[i]=std::lower_bound(t+1,t+pos+1,b[i])-t;
		++cnt[b[i]];
		S.insert(b[i]);
	}
	for(int i=1;i<=pos+1;++i)
	{
		chmin(cnt[i],1);
		cnt[i]+=cnt[i-1];
	}
	for(int i=0;i<=n+1;++i) dp[i]=(node){a[i]==-1?-inf:1,i};
	solve(0,n+1);
	fprintf(stderr,"%d\n",dp[n+1].val-2);
	int cur=n+1;
	while(cur)
	{
		int last=opt[cur];
		int qwq=a[last];
		for(int i=last+1;i<cur;++i)
		{
			if(a[i]==-1)
			{
				auto it=S.upper_bound(qwq);
				if(it!=S.end()&&*it>qwq&&*it<a[cur])
				{
					ans[i]=*it;
					qwq=*it;
					S.erase(it);
				}
			}
		}
		cur=last;
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i]==-1&&!ans[i])
		{
			ans[i]=*S.begin();
			S.erase(S.begin());
		}
		else if(~a[i])
		{
			ans[i]=a[i];
		}
		ans[i]=t[ans[i]];
	}
	ans[n+1]=inf;
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}