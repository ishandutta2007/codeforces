//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
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
ll a[500011],b[500011];
int n,k;
ll cost;
priority_queue<int> st1,st2;
int calc(ll coef)
{
	while(!st1.empty())st1.pop();
	while(!st2.empty())st2.pop();
	int cnt=0;
	cost=0;
	for(int i=1;i<=n;i++)
	{
		ll upd1=a[i]+b[i]+coef;
		ll upd2=cnt+1==i?Lbig:b[i]-st1.top()+coef;
		ll upd3=cnt==0?Lbig:b[i]-st2.top();
//		cout<<"i="<<i<<" "<<upd1<<" "<<upd2<<" "<<upd3<<endl;
//		for(auto p:st1)cout<<p.FF<<","<<p.SS<<" ";cout<<endl;
//		for(auto p:st2)cout<<p.FF<<","<<p.SS<<" ";puts("");
		if(upd1>0&&upd2>0&&upd3>0)
		{
			st1.push(-a[i]);
			continue;
		}
		else if(upd1<=upd2&&upd1<=upd3)
		{
			st2.push(b[i]);
			cost+=upd1;
			cnt++;
		}
		else if(upd2<=upd1&&upd2<=upd3)
		{
			st2.push(b[i]);
			st1.pop();
			st1.push(-a[i]);
			cost+=upd2;
			cnt++;
		}
		else
		{
			st1.push(-a[i]);
			st2.pop();
			st2.push(b[i]);
			cost+=upd3;
		}
	}
	return cnt;
}
int main()
{
	getii(n,k);
	for(int i=1;i<=n;i++)geti(a[i]);
	for(int i=1;i<=n;i++)geti(b[i]);
	ll l=-Imx,r=Imx;
	while(l<=r)
	{
		ll m=l+r>>1;
		int curk=calc(m);
		if(curk>=k)l=m+1;
		else r=m-1;
	}
//	cout<<"r="<<r<<endl;
	calc(r);
	cout<<cost-r*k<<endl;
	return 0;
}