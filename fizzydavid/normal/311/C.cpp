//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) puti(x),putendl()
#define putsii(x,y) putii(x,y),putendl()
#define putsiii(x,y,z) putiii(x,y,z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
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
const int maxn=100011;
const int maxk=10011;
const int SGTsize=262144;
struct SGT
{
	int a[SGTsize+10];
	SGT()
	{
		memset(a,0,sizeof(a));
	}
	void modify(int id,int x)
	{
//		cout<<"modify:"<<id<<" += "<<x<<endl;
		int pos=id+(SGTsize>>1);
		a[pos]+=x;
		while(pos!=1)
		{
			pos>>=1;
			a[pos]=max(a[pos<<1],a[(pos<<1)+1]);
		}
	}
	int delmax()
	{
//		cout<<"delmax"<<endl;
		int pos=1;
		while(true)
		{
			if((pos<<1)>=SGTsize)break;
			else if(a[pos<<1]>=a[(pos<<1)+1])
				pos=(pos<<1);
			else
				pos=(pos<<1)+1;
		}
		int ans=a[pos];
		modify(pos-(SGTsize>>1),-a[pos]);
		return ans;
	}
}sgt;
ll n,m,k,c[maxn],p[maxn],dis[maxk];
vector<ll>methods;
set<pair<ll,int> >st;
bool can[maxn];
void op1(ll x)
{
	for(int i=0;i<k;i++)dis[i]=LINF;
	dis[1%k]=0;
	methods.PB(x);
	st.insert(MP(0,1%k));
	while(st.size()>0)
	{
		ll d=st.begin()->FF,u=st.begin()->SS;
		st.erase(st.begin());
		for(int i=0;i<methods.size();i++)
		{
			ll v=(u+methods[i])%k,d2=methods[i];
			if(d+d2<dis[v])
			{
				dis[v]=d+d2;
				st.insert(MP(dis[v],v));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!can[i]&&dis[p[i]%k]<=p[i])
		{
//			cout<<i<<" becomes reachable"<<endl;
			can[i]=1;
			sgt.modify(i-1,c[i]);
		}
	}
}
void op2(int x,ll delta)
{
	c[x]-=delta;
	if(can[x])sgt.modify(x-1,-delta);
}
int main()
{
	getii(n,n);
	getii(m,k);
	for(int i=1;i<=n;i++)getii(p[i],c[i]);
	op1(k);
	int op;
	ll x,y;
	while(m--)
	{
		geti(op);
		if(op==1)
		{
			geti(x);
			op1(x);
		}
		else if(op==2)
		{
			getii(x,y);
			op2(x,y);
		}
		else
		{
			putsi(sgt.delmax());
		}
	}
	return 0;
}