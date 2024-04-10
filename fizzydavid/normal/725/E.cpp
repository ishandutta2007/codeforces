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
int n,c;
int a[200111];
set<pair<int,int> >s;
vector<pair<int,int> >tmps;
bool used[200111];
int cnt[200111];
int main()
{
	getii(c,n);
	s.insert(MP(-c,0));
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		tmps.clear();
		while(s.size()>0&&-s.begin()->FF>a[i])
		{
			int x=s.begin()->SS,y=-s.begin()->FF+x;
			s.erase(s.begin());
			tmps.PB(MP(-a[i],x));
			tmps.PB(MP(-(y-(x+a[i])),x+a[i]));
		}
		for(int j=0;j<tmps.size();j++)
		{
			s.insert(tmps[j]);
		}
	}
	for(auto x:s)
	{
//		cout<<x.SS<<" "<<x.FF<<endl;
		used[x.SS]=1;
	}
	int tmp=c;
	for(int i=n;i>=1;i--)
	{
		if(tmp>=a[i])
		{
			cnt[a[i]]++;
			cnt[tmp+1]--;
//			cout<<"add:"<<a[i]<<","<<tmp+1<<endl;
			tmp-=a[i];
		}
	}
	int sum=0;
	for(int i=1;i<=c;i++)
	{
		sum+=cnt[i];
//		cout<<i<<":"<<sum<<endl;
		if(sum>0&&!used[c-i])
		{
			cout<<i<<endl;
			return 0;
		}
	}
	puts("Greed is good");
	return 0;
}