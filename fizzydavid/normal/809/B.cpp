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
const ll Lbg=2e18;
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
string query(int l,int r)
{
	cout<<1<<" "<<l<<" "<<r<<endl;
	fflush(stdout);
	string ret;
	cin>>ret;
	return ret;
}
int find(int l,int r)
{
	if(l>=r)return l;
	if(l+1==r)
	{
		if(query(l,r)=="TAK")return l;
		else return r; 
	}
	int m=l+r>>1;
	cout<<1<<" "<<m<<" "<<m+1<<endl;
	fflush(stdout);
	string ans;
	cin>>ans;
	if(ans=="TAK")return find(l,m);
	else return find(m+1,r);
}
int main()
{
	int n,k;
	cin>>n>>k;
	int p=find(1,n);
//	cout<<"p="<<p<<endl;
	int q=find(1,p-1);
//	cout<<"q="<<q<<endl;
	if(p==q||query(q,p)=="NIE")q=find(p+1,n);
	cout<<2<<" "<<p<<" "<<q<<endl;
	fflush(stdout);
	return 0;
}