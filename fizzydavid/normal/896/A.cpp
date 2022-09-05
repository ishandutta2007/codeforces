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
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll q,n,k;
string s0="What are you doing at the end of the world? Are you busy? Will you save us?";
string t0="What are you doing while sending \"";
string t1="\"? Are you busy? Will you send \"";
string t2="\"?";
ll len[100011];
int main()
{
	len[0]=s0.size();
	for(int i=1;i<=100000;i++)
	{
		len[i]=t0.size()+len[i-1]+t1.size()+len[i-1]+t2.size();
		len[i]=min(len[i],ll(4e18));
	}
	cin>>q;
	while(q--)
	{
		cin>>n>>k;k--;
		for(int i=n;i>=0;i--)
		{
			if(i==0)
			{
				if(k>=s0.size())
				{
					cout<<'.';
					break;
				}
				else
				{
					cout<<s0[k];
					break;
				}
			}
			ll n0=t0.size();
			ll n1=len[i-1]+n0;
			ll n2=t1.size()+n1;
			ll n3=len[i-1]+n2;
			ll n4=t2.size()+n3;
			if(k<n0)
			{
				cout<<t0[k];
				break;
			}
			else if(k>=n0&&k<n1)
			{
				k-=n0;
			}
			else if(k>=n1&&k<n2)
			{
				k-=n1;
				cout<<t1[k];
				break;
			}
			else if(k>=n2&&k<n3)
			{
				k-=n2;
			}
			else if(k>=n3&&k<n4)
			{
				k-=n3;
				cout<<t2[k];
				break;
			}
			else if(k>=n4)
			{
				cout<<'.';
				break;
			}
		}
	}
	return 0;
}