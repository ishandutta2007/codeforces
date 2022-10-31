// luogu-judger-enable-o2
#include<cstdio>
#define Finline __inline__ __attribute__ ((always_inline))
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<24,stdin),p1==p2)?EOF:*p1++)
typedef long long ll;
char ibuf[1<<24],*p1=ibuf,*p2=ibuf;
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    while(ch<48||ch>57) ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
}
const int N=1000005;
struct edge{
	int v,nxt;
}c[N<<1];
struct node{
	ll size1,size2;
	ll sum1,sum2;
	ll ans;
};
int front[N],cnt;
ll dep[N];
inline void add(const int &u,const int &v){c[++cnt]=(edge){v,front[u]},front[u]=cnt;}
node dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	node cur,tmp;
	cur.ans=0;
	cur.size1=cur.size2=cur.sum1=cur.sum2=0;
	if(dep[x]&1)
	{
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(c[i].v!=fa)
			{
				tmp=dfs(c[i].v,x);
				
				cur.ans+=(tmp.sum1-dep[x]*tmp.size1)>>1ll;
				cur.ans+=(tmp.sum2-tmp.size2-dep[x]*tmp.size2)>>1ll;
				cur.ans+=tmp.size2;
				
				cur.ans+=(cur.sum1*tmp.size1+tmp.sum1*cur.size1-dep[x]*2ll*cur.size1*tmp.size1)>>1ll;
				cur.ans+=((cur.sum1*tmp.size2+(tmp.sum2-tmp.size2)*cur.size1-dep[x]*2ll*cur.size1*tmp.size2)>>1ll)+tmp.size2*cur.size1;
				cur.ans+=(cur.sum2*tmp.size2+tmp.sum2*cur.size2-dep[x]*2ll*cur.size2*tmp.size2)>>1ll;
				cur.ans+=((cur.sum2*tmp.size1+(tmp.sum1-tmp.size1)*cur.size2-dep[x]*2ll*cur.size2*tmp.size1)>>1ll)+tmp.size1*cur.size2;
				
				cur.ans+=tmp.ans;
				cur.sum1+=tmp.sum1;
				cur.sum2+=tmp.sum2;
				cur.size1+=tmp.size1;
				cur.size2+=tmp.size2;
				
			}
		}
	}
	else
	{
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(c[i].v!=fa)
			{
				tmp=dfs(c[i].v,x);
				
				cur.ans+=(tmp.sum1-tmp.size1-dep[x]*tmp.size1)>>1ll;
				cur.ans+=(tmp.sum2-dep[x]*tmp.size2)>>1ll;
				cur.ans+=tmp.size1;
				
				cur.ans+=(cur.sum1*tmp.size1+tmp.sum1*cur.size1-dep[x]*2ll*cur.size1*tmp.size1)>>1ll;
				cur.ans+=((cur.sum1*tmp.size2+(tmp.sum2-tmp.size2)*cur.size1-dep[x]*2ll*cur.size1*tmp.size2)>>1ll)+tmp.size2*cur.size1;
				cur.ans+=(cur.sum2*tmp.size2+cur.size2*tmp.sum2-dep[x]*2ll*cur.size2*tmp.size2)>>1ll;
				cur.ans+=((cur.sum2*tmp.size1+(tmp.sum1-tmp.size1)*cur.size2-dep[x]*2ll*cur.size2*tmp.size1)>>1ll)+tmp.size1*cur.size2;
				
				cur.ans+=tmp.ans;
				cur.sum1+=tmp.sum1;
				cur.sum2+=tmp.sum2;
				cur.size1+=tmp.size1;
				cur.size2+=tmp.size2;
			}
		}
	}
	cur.size1+=(dep[x]&1);
	cur.size2+=!(dep[x]&1);
	cur.sum1+=(dep[x]&1)?dep[x]:0;
	cur.sum2+=(dep[x]&1)?0:dep[x];
	return cur;
}
int main()
{
// 	freopen("rap.in","r",stdin);
// 	freopen("rap.out","w",stdout);
	int n,x,y;
	read(n);
	for(int i=1;i<n;++i)
	{
		read(x);read(y);
		add(x,y);add(y,x);
	}
	printf("%lld\n",dfs(1,0).ans);
	return 0;
}