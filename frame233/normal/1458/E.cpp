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
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=100005;
int X[N],Y[N],a[N],t[N],n;
struct seg_tr{
	int val[N<<2],M,cur;
	struct node{
		int v,p;
		inline bool operator < (const node &o)const{return v<o.v;}
	}_[N];
	void build(int *arr)
	{
		for(M=1;M<=n+1;M<<=1);
		for(int i=1;i<=n;++i) val[M+a[i]]=arr[i],_[i]={arr[i],a[i]};
		std::sort(_+1,_+n+1);
		for(int i=M-1;i>=1;--i) val[i]=min(val[i<<1],val[i<<1|1]);
		cur=1;
	}
	void upd(int x,int C){for(val[x+=M]=C,x>>=1;x;x>>=1) val[x]=min(val[x<<1],val[x<<1|1]);}
	int ask(int l,int r)
	{
		if(l>r) return inf;
		int ans=inf;
		for(int s=l+M-1,t=r+M+1;s^t^1;s>>=1,t>>=1)
		{
			if(~s&1) chmin(ans,val[s^1]);
			if(t&1) chmin(ans,val[t^1]);
		}
		return ans;
	}
	int QueryL(int L)
	{
		X[n+1]=L,Y[n+1]=0;
		int pos=std::lower_bound(t+1,t+n+1,n+1,[&](int A,int B)->bool{return X[A]-Y[A]<X[B]-Y[B];})-t;
		return ask(pos,n);
	}
	int QueryR(int R)
	{
		X[n+1]=R,Y[n+1]=0;
		int pos=std::upper_bound(t+1,t+n+1,n+1,[&](int A,int B)->bool{return X[A]-Y[A]<X[B]-Y[B];})-t-1;
		return ask(1,pos);
	}
	void maintain(int lim){while(cur<=n&&_[cur].v<lim) upd(_[cur].p,inf),++cur;}
}tr1,tr2;
struct node{
	int x,y,t;
	inline bool operator < (const node &o)const{return x==o.x?y<o.y:x<o.x;}
};
std::vector<node> S;
std::vector<pi> orig;
int main()
{
	int q;read(n,q);
	for(int i=1;i<=n;++i)
	{
		read(X[i],Y[i]),t[i]=i;
		orig.pb({X[i],Y[i]});
	}
	orig.pb({inf,inf});
	std::sort(orig.begin(),orig.end());
	std::sort(t+1,t+n+1,[&](int A,int B)->bool{return X[A]-Y[A]<X[B]-Y[B];});
	for(int i=1;i<=n;++i) a[t[i]]=i;
	tr1.build(X),tr2.build(Y);
	int x=0,y=0;
	tr1.maintain(x),tr2.maintain(y);
	while(x<inf&&y<inf)
	{
		int it1=tr1.QueryL(x-y),it2=tr2.QueryR(x-y);
		int A=it1-x,B=it2-y,tmp=min(A,B);
		S.pb({x,y,tmp});
		x+=tmp,y+=tmp;
		if(x==it1) ++x;
		if(y==it2) ++y;
		tr1.maintain(x),tr2.maintain(y);
	}
	std::sort(S.begin(),S.end());
	while(q--)
	{
		read(x,y);
		if(*std::lower_bound(orig.begin(),orig.end(),mkpr(x,y))==mkpr(x,y)) puts("LOSE");
		else
		{
			auto it=std::upper_bound(S.begin(),S.end(),(node){x,y,0});
			if(it==S.begin()) puts("WIN");
			else
			{
				--it;
				if(it->x-it->y==x-y&&x<it->x+it->t) puts("LOSE");
				else puts("WIN");
			}
		}
	}
	return 0;
}