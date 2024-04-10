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
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=0x05ad13b4;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
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

const int N=2100005;
int a[N],b[N];
struct edge{
    int v,nxt;
    int id;
}c[N<<1];
int front[N],cnt=-1;
Finline void addedge(int u,int v,int id)
{
    c[++cnt]=(edge){v,front[u],id};
    front[u]=cnt;
}
int dg[N];
bool used[N];
int ans[N],pos;
void dfs(int x)
{
    for(int i=front[x];~i;i=front[x])
    {
        front[x]=c[i].nxt;
        if(!used[c[i].id])
        {
            used[c[i].id]=1;
            dfs(c[i].v);
            if(i&1) ans[++pos]=-c[i].id;
            else ans[++pos]=c[i].id;
        }
    }
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i],b[i]);
	}
	if(n==1)
	{
		if(a[1]==b[1])
		{
			printf("20\n");
			printf("%d %d\n",1,2);
			return 0;
		}
		else
		{
			int x=a[1]^b[1];
			for(int k=0;;++k)
			{
				if((x>>k)&1)
				{
					printf("%d\n",k);
					break;
				}
			}
			printf("%d %d\n",1,2);
			return 0;
		}
	}
	for(int i=20;i>=0;--i)
	{
		memset(front,255,sizeof(front));
		memset(dg,0,sizeof(dg));
		cnt=-1;
		for(int j=1;j<=n;++j)
		{
			a[j]&=((1<<i)-1);
			b[j]&=((1<<i)-1);
			addedge(a[j],b[j],j);
			addedge(b[j],a[j],j);
			++dg[a[j]],++dg[b[j]];
		}
		bool flag=false;
        for(int i=0;i<1<<20;++i)
        {
            if(dg[i]&1)
            {
            	flag=true;
            	break;
            }
        }
        if(flag) continue;
        memset(used,0,sizeof(used));
        pos=0;
        for(int i=0;i<1<<20;++i)
        {
        	if(~front[i])
        	{
	            dfs(i);
	            break;
	        }
        }
        if(pos!=n) continue;
        std::reverse(ans+1,ans+pos+1);
        printf("%d\n",i);
        for(int j=1;j<=pos;++j)
        {
        	int t=abs(ans[j]);
        	if(ans[j]>0) printf("%d %d ",t+t-1,t+t);
        	else printf("%d %d ",t+t,t+t-1);
        }
        printf("\n");
        return 0;
	}
	return 0;
}