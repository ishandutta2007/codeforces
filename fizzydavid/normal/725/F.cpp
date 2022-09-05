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
ll n,Sa,Sb,a,b;
ll t[100111];
set<pair<ll,int> >s;
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		ll a1,a2,b1,b2;
		getii(a1,b1);
		getii(a2,b2);
		if(a1<=b2&&b1<=a2)continue;
		Sa+=a1;Sa+=a2;
		Sb+=b1;Sb+=b2;
		if(a1+b1<=a2+b2&&(a1<=b2||b1<=a2))
		{
			if(a1<=b2)
			{
				b+=a1+b1;
				a+=a2+b2;
			}
			else if(b1<=a2)
			{
				a+=a1+b1;
				b+=a2+b2;
			}
		}
		else
		{
//			cout<<"insert:"<<endl;
			s.insert(MP(-(a1+b1),i));
			t[i]=a2+b2;
		}
	}
//	cout<<Sa<<" "<<Sb<<endl;
	bool flag=1;
	while(s.size()>0)
	{
		ll x=-s.begin()->FF,y=s.begin()->SS;
		s.erase(s.begin());
		if(flag)a+=x;else b+=x;
		if(t[y]!=-1)
		{
			s.insert(MP(-t[y],y));
			t[y]=-1;
		}
		flag^=1;
	}
//	cout<<Sa<<" "<<Sb<<" "<<a<<" "<<b<<endl;
	cout<<(a-b+Sa-Sb)/2<<endl;
	return 0;
}