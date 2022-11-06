#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=3e5+5;
int t,n,m,k1,k2,a[N],b[N],ans[N],st[N],top;

pair<int,int> c1[N],c2[N];

vector<int> v1,v2;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=1;i<=n;++i)
		{
			char op[5];
			scanf("%s",op+1);
			if(op[1]=='L') b[i]=0;
			else b[i]=1;
		}
		k1=0;k2=0;
		for(int i=1;i<=n;++i)
			if(a[i]%2==1)
				c1[++k1]=mp(a[i],i);
			else c2[++k2]=mp(a[i],i);
		sort(c1+1,c1+1+k1);
		sort(c2+1,c2+1+k2);
		top=0;
		for(int i=1;i<=k1;++i)
			if(b[c1[i].se]==1)
				st[++top]=c1[i].se;
			else if(top)
			{
				int res=abs(a[st[top]]-a[c1[i].se])/2;
				ans[st[top]]=ans[c1[i].se]=res;
				--top;
			}
		v1.clear();v2.clear();
		for(int i=1;i<=k1;++i)
			if(!ans[c1[i].se])
			{
				if(b[c1[i].se]==0)
					v1.push_back(c1[i].se);
				else v2.push_back(c1[i].se);
			}
		for(int i=0;i+1<v1.size();i+=2)
		{
			int res=(a[v1[i]]+a[v1[i+1]])/2;
			ans[v1[i]]=ans[v1[i+1]]=res;
		}
		for(int i=(int)v2.size()-1;i>=1;i-=2)
		{
			int res=(m*2-a[v2[i]]-a[v2[i-1]])/2;
			ans[v2[i]]=ans[v2[i-1]]=res;
		}
		if(v1.size()%2==1&&v2.size()%2==1)
		{
			int res=(a[v1[v1.size()-1]]+2*m-a[v2[0]])/2;
			ans[v1[v1.size()-1]]=ans[v2[0]]=res;
		}
		top=0;
		for(int i=1;i<=k2;++i)
			if(b[c2[i].se]==1)
				st[++top]=c2[i].se;
			else if(top)
			{
				int res=abs(a[st[top]]-a[c2[i].se])/2;
				ans[st[top]]=ans[c2[i].se]=res;
				--top;
			}
		v1.clear();v2.clear();
		for(int i=1;i<=k2;++i)
			if(!ans[c2[i].se])
			{
				if(b[c2[i].se]==0)
					v1.push_back(c2[i].se);
				else v2.push_back(c2[i].se);
			}
		for(int i=0;i+1<v1.size();i+=2)
		{
			int res=(a[v1[i]]+a[v1[i+1]])/2;
			ans[v1[i]]=ans[v1[i+1]]=res;
		}
		for(int i=(int)v2.size()-1;i>=1;i-=2)
		{
			int res=(m*2-a[v2[i]]-a[v2[i-1]])/2;
			ans[v2[i]]=ans[v2[i-1]]=res;
		}
		if(v1.size()%2==1&&v2.size()%2==1)
		{
			int res=(a[v1[v1.size()-1]]+2*m-a[v2[0]])/2;
			ans[v1[v1.size()-1]]=ans[v2[0]]=res;
		}
		for(int i=1;i<=n;++i)
			if(ans[i])
			{
				printf("%lld ",ans[i]);
				ans[i]=0;
			}
			else printf("-1 ");
		printf("\n");
	}
	return 0;
}