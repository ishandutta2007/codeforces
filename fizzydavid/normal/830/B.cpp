//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,a[100111],cnt[100111];
pair<int,int> p[100111];
int sum[100111];
void add(int x,int v)
{
	for(int i=x;i<=100005;i+=i&(-i))sum[i]+=v;
}
int query(int x)
{
	int ret=0;
	for(int i=x;i>0;i-=i&(-i))ret+=sum[i];
	return ret;
}
set<int> pos[100111];
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		p[i]=MP(a[i],i);
		add(i,1);
		pos[a[i]].insert(i);
	}
	sort(p+1,p+n+1);
	int pre=0;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=p[i].FF,cur;
		set<int>::iterator it=pos[x].lower_bound(pre);
		if(it==pos[x].end())
		{
			cur=*pos[x].begin();
			pos[x].erase(pos[x].begin());
		}
		else
		{
			cur=*it;
			pos[x].erase(it);
		}
		if(pre<cur)
		{
			ans+=query(cur)-query(pre);
		}
		else
		{
			ans+=query(n)-query(pre)+query(cur);
		}
		add(cur,-1);
		pre=cur;
	}
	cout<<ans<<endl;
	return 0;
}