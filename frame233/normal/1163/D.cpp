// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while((ch<65||ch>122||(ch>90&&ch<97))&&(ch!='*')) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)||ch=='*') *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=1005;
struct ac_automation{
	struct node{
		int ch[26],fail;
	}f[55];
	int node_cnt;
	int _q[N],_l,_r;
	void Insert(char *s,const int &len)
	{
		int cur=0,tmp;
		for(int i=1;i<=len;++i)
		{
			tmp=s[i]-97;
			if(!f[cur].ch[tmp]) f[cur].ch[tmp]=++node_cnt;
			cur=f[cur].ch[tmp];
		}
	}
	void GetFail()
	{
		_l=1,_r=0;
		for(int i=0;i<26;++i)
		{
			if(f[0].ch[i])
			{
				_q[++_r]=f[0].ch[i];
			}
		}
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			for(int i=0;i<26;++i)
			{
				if(f[x].ch[i])
				{
					f[f[x].ch[i]].fail=f[f[x].fail].ch[i];
					_q[++_r]=f[x].ch[i];
				}
				else
				{
					f[x].ch[i]=f[f[x].fail].ch[i];
				}
			}
		}
	}
}trs,trt;
int f[N][53][53];
char c[N],s[N],t[N];
int main()
{
	memset(f,-63,sizeof(f));
	f[0][0][0]=0;
	int lc=read_str(c+1);
	int ls=read_str(s+1);
	int lt=read_str(t+1);
	trs.Insert(s,ls);
	trs.GetFail();
	trt.Insert(t,lt);
	trt.GetFail();
	for(int i=0;i<lc;++i)
	{
		if(c[i+1]=='*')
		{
			for(int ch=0;ch<26;++ch)
			{
				for(int j=0;j<=ls;++j)
				{
					for(int k=0;k<=lt;++k)
					{
						chmax(f[i+1][trs.f[j].ch[ch]][trt.f[k].ch[ch]],f[i][j][k]+(trs.f[j].ch[ch]==ls)-(trt.f[k].ch[ch]==lt));
					}
				}
			}
		}
		else
		{
			int ch=c[i+1]-97;
			for(int j=0;j<=ls;++j)
			{
				for(int k=0;k<=lt;++k)
				{
					chmax(f[i+1][trs.f[j].ch[ch]][trt.f[k].ch[ch]],f[i][j][k]+(trs.f[j].ch[ch]==ls)-(trt.f[k].ch[ch]==lt));
				}
			}
		}
	}
	int ans=-inf;
	for(int i=0;i<=ls;++i)
	{
		for(int j=0;j<=lt;++j)
		{
			chmax(ans,f[lc][i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}