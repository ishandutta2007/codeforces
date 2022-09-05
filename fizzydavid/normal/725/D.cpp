//by yjz
#include<bits/stdc++.h>
using namespace std;
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
int n;
ll t[300111],w[300111];
vector<pair<ll,int> >v;
set<pair<ll,int> >st;
int findrank()
{
	return lower_bound(v.begin(),v.end(),MP(-t[1],1))-v.begin();
}
int main()
{
	int kotori=0;
	geti(n);
	for(int i=1;i<=n;i++)
	{
		getii(t[i],w[i]);
		if(i>1)
		{
			v.PB(MP(-t[i],i));
		}
	}
	sort(v.begin(),v.end());
	int rk=findrank(),ans=rk;
//	cout<<"rk="<<rk<<endl;
	for(int i=0;i<rk;i++)
	{
//		cout<<v[i].SS<<" "<<w[v[i].SS]-t[v[i].SS]<<endl;
		st.insert(MP(w[v[i].SS]-t[v[i].SS]+1,i));
	}
	while(st.size()>0&&t[1]>0)
	{
		ll val=st.begin()->FF;
//		cout<<"t[1]="<<t[1]<<" val="<<val<<endl;
		st.erase(st.begin());
		if(t[1]>=val)
		{
			kotori++;
			t[1]-=val;
			int nrk=findrank();
			for(int i=rk;i<nrk;i++)
			{
				st.insert(MP(w[v[i].SS]-t[v[i].SS]+1,i));
			}
			rk=nrk;
			ans=min(ans,rk-kotori);
		}
		else break;
	}
	cout<<ans+1<<endl;
	return 0;
}