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
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=600005;
char s[N];
int a[N],st[N],top,nxt[N],anc[N];
std::map<int,int> mp;
void print(__int128 x)
{
	if(x>9)print(x/10);
	putchar(x%10+48);
}
int main()
{
	int n;read(n);
	char ch;int x;
	ll ans=0;
	__int128 lastans=0;
	for(int i=1,j=0;i<=n;++i)
	{
		do{ch=getchar();}while(!isalpha(ch));
		read(x),ch=(ch-97+lastans)%26+97,x^=lastans&((1<<30)-1),s[i]=ch,a[i]=x;
		if(i!=1)
		{
			while(j&&s[j+1]!=s[i])j=nxt[j];
			if(s[j+1]==s[i])++j;
			nxt[i]=j,anc[i-1]=s[nxt[i-1]+1]==s[i]?anc[nxt[i-1]]:nxt[i-1];
			for(int j=nxt[i-1];j;)
			{
				if(s[j+1]==s[i])j=anc[j];
				else
				{
					int l=1,r=top,mid;
					while(l<r)mid=(l+r)>>1,st[mid]>=i-j?r=mid:l=mid+1;
					int val=a[st[l]];
					if(!--mp[val])mp.erase(val);
					ans-=val,j=nxt[j];
				}
			}
			if(s[i]==s[1])ans+=a[i],++mp[a[i]];
		}
		else ans=a[1],++mp[a[1]];
		while(top&&a[i]<=a[st[top]])--top;
		st[++top]=i;
		for(auto it=mp.upper_bound(a[i]);it!=mp.end();)
		{
			ans-=1LL*(it->first-a[i])*it->second,mp[a[i]]+=it->second;
			auto qwq=it;++it,mp.erase(qwq);
		}
		print(lastans+=ans),putchar('\n');
	}
	return 0;
}