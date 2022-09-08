//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<deque>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define input1(x) x=getnum()
#define input2(x,y) input1(x),y=getnum()
#define input3(x,y,z) input2(x,y),z=getnum()
#define input4(x,y,z,w) input3(x,y,z),w=getnum()
#define output1(x) putnum(x)
#define output2(x,y) output1(x),putnum(y)
#define output3(x,y,z) output2(x,y),putnum(z)
#define output4(x,y,z,w) output3(x,y,z),putnum(w)
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
const int mod=1e9+7;
int n;
string s;
ll kissme(ll x,ll k)
{
	ll ans=1;
	while(k>0)
	{
		if(k&1)ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
const unsigned long long base1=255;
const unsigned long long base2=0xA06;
unsigned long long hs11[1000111],hs12[1000111];
unsigned long long hs21[1000111],hs22[1000111];
int m;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	int k=s.size();
	if(m==0)
	{
		cout<<kissme(26,n)<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++)
		hs11[i]=hs11[i-1]*base1+s[i-1],hs12[i]=hs12[i-1]*base2+s[i-1];
	unsigned long long t1=1,t2=1;
	for(int i=k;i>=1;i--)
		hs21[i]=hs21[i+1]+t1*s[i-1],hs22[i]=hs22[i+1]+t2*s[i-1],t1*=base1,t2*=base2;
	int pre,x;
	cin>>pre;
	int sum=k;
	for(int i=2;i<=m;i++)
	{
		cin>>x;
		sum=sum+k-max(0,k-(x-pre));
		if(x-pre<k&&(hs21[x-pre+1]!=hs11[k-(x-pre)]||hs22[x-pre+1]!=hs12[k-(x-pre)]))
		{
			cout<<0<<endl;
			return 0;
		}
		pre=x;
	}
	cout<<kissme(26,n-sum)<<endl;
	return 0;
}