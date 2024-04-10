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
const int mod=1000000007;
const int inv2=(mod+1)>>1;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int pw[N],inv[N];
char s[21][1000005],S[21][1000005],t[N],w[1000005];
int len[21],z1[2000005],z2[2000005];
int sum[N][26],L;
char tp[2000005];
void Z(int n,int *z)
{
	tp[n+1]=0;
	int l=0,r=0;
	for(int i=2;i<=n;++i)
	{
		z[i]=i<=r?min(z[i-l+1],r-i+1):0;
		while(tp[z[i]+1]==tp[i+z[i]]) ++z[i];
		if(i+z[i]-1>r) r=i+z[i]-1,l=i;
	}
}
int calc(char *s,char *S,char mid,int _)
{
	int tmp=min(L,_);
	memcpy(tp+1,S+1,tmp),tp[tmp+1]='#',memcpy(tp+tmp+2,w+1,L),std::reverse(tp+tmp+2,tp+tmp+2+L),Z(tmp+L+1,z1);
	memcpy(tp+1,s+1,tmp),tp[tmp+1]='#',memcpy(tp+tmp+2,w+1,L),Z(tmp+L+1,z2);
	int ans=0;
	for(int i=1;i<=L;++i) if(w[i]==mid&&z1[tmp+2+L-(i-1)]>=i-1&&z2[tmp+2+i]>=L-i) ++ans;
	return ans;
}
int count()
{
	int tmp=len[0],ans=0;
	memcpy(tp+1,w+1,L),tp[L+1]='#',memcpy(tp+L+2,s[0]+1,tmp),Z(tmp+L+1,z1);
	for(int i=1;i<=tmp-L+1;++i) if(z1[i+L+1]>=L) ++ans;
	return ans;
}
int main()
{
	pw[0]=1;for(int i=1;i<N;++i) pw[i]=pw[i-1],add(pw[i],pw[i]);
	inv[0]=1;for(int i=1;i<N;++i) inv[i]=1LL*inv[i-1]*inv2%mod;
	int n,q;read(n,q);
	len[0]=read_str(s[0]+1);
	read_str(t+1);
	for(int i=21;i<=n;++i) for(int j=0;j<26;++j) sum[i][j]=sum[i-1][j],(t[i]==j+97)&&(add(sum[i][j],inv[i]),0);
	memcpy(S[0],s[0],sizeof(s[0]));
	std::reverse(S[0]+1,S[0]+len[0]+1);
	for(int i=1;i<=20;++i)
	{
		memcpy(s[i],s[i-1],len[i-1]+1),len[i]=len[i-1];
		if(len[i]<1e6) s[i][++len[i]]=t[i];
		if(len[i]<1e6)
		{
			int tmp=min(1000000-len[i],len[i-1]);
			memcpy(s[i]+len[i]+1,s[i-1]+1,tmp);
			len[i]+=tmp;
		}
		memcpy(S[i],S[i-1],len[i-1]+1);
		int L=len[i-1];
		if(L<1e6) S[i][++L]=t[i];
		if(L<1e6)
		{
			int tmp=min(1000000-L,len[i-1]);
			memcpy(S[i]+L+1,S[i-1]+1,tmp);
		}
	}
	while(q--)
	{
		int x;read(x);
		L=read_str(w+1);
		int ans=count();
		for(int i=1;i<=20&&i<=x;++i) add(ans,1LL*inv[i]*calc(s[i-1],S[i-1],t[i],len[i-1])%mod);
		for(int i=0;i<26;++i) if(sum[x][i]) add(ans,1LL*sum[x][i]*calc(s[20],S[20],i+97,len[20])%mod);
		printf("%lld\n",1LL*pw[x]*ans%mod);
	}
	return 0;
}