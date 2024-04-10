// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

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

const int N=25005;
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
struct ACAM{
	int ch[N][10];
	int fail[N];
	bool tag[N];
	int node_cnt;
	int _q[N],_l,_r;
	void insert(char *s,int len)
	{
		int cur=0,tmp;
		for(int i=1;i<=len;++i)
		{
			tmp=s[i]-48;
			if(!ch[cur][tmp]) ch[cur][tmp]=++node_cnt;
			cur=ch[cur][tmp];
		}
		tag[cur]=true;
	}
	void build()
	{
		_l=1,_r=0;
		for(int i=0;i<10;++i)
		{
			if(ch[0][i])
			{
				_q[++_r]=ch[0][i];
			}
		}
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			tag[x]|=tag[fail[x]];
			for(int i=0;i<10;++i)
			{
				if(ch[x][i])
				{
					fail[ch[x][i]]=ch[fail[x]][i];
					_q[++_r]=ch[x][i];
				}
				else
				{
					ch[x][i]=ch[fail[x]][i];
				}
			}
		}
	}
}tr;
char s[1005];
char X[55],Y[55];
int a[55];
int n,d;
int f[55][25005][2];
int dfs(int pos,int cur,bool tag,bool limit)
{
	tag|=tr.tag[cur];
	if(pos==d+1) return tag;
	if(!limit&&~f[pos][cur][tag]) return f[pos][cur][tag];
	int maxx=limit?a[pos]:9;
	int ans=0;
	for(int i=0;i<=maxx;++i)
	{
		add(ans,dfs(pos+1,tr.ch[cur][i],tag,limit&&i==maxx));
	}
	if(!limit) return f[pos][cur][tag]=ans;
	return ans;
}
int solve(char *s)
{
	memset(f,255,sizeof(f));
	for(int i=1;i<=d;++i)
	{
		a[i]=s[i]-48;
	}
	return dfs(1,0,0,1);
}
int main()
{
	n=read_str(s+1);
	d=read_str(X+1);
	read_str(Y+1);
	for(int i=1;i<=n-(d>>1)+1;++i)
	{
		tr.insert(s+i-1,(d>>1));
	}
	tr.build();
	--X[d];
	int cur=d;
	while(cur>1&&X[cur]<48) --X[cur-1],X[cur]+=10,--cur;
	printf("%d\n",(solve(Y)-solve(X)+mod)%mod);
	return 0;
}