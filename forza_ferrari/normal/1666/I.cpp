#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<iomanip>
#include<map>
#include<stack>
#include<set>
#include<functional>
#define in(x) x=read()
#define qr read()
#define int ll
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline ll read()
	{
        bool sign=0; char ch=nc();ll x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
        return x;
    }
    #undef BUF_SIZE
};
using namespace fastIO;
int qry(int x,int y)
{
	cout<<"SCAN "<<x<<' '<<y<<endl;
	int res;cin>>res;return res;
}
int f(int x,int y)
{
	cout<<"DIG "<<x<<' '<<y<<endl;
	int res;cin>>res;return res;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T;cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		int x1=qry(1,1),x2=qry(1,m);
		int s1=(x1-n-m+2+x2-n-m+2)/2,s2=(x1-n-m+2-(x2-n-m+2))/2;//s1=d1-d2,s2=d3-d4
		// cout<<s1<<' '<<s2<<endl;
		int p=(s1+n+1)/2;
		int x3=qry(p,m);
		int s3=n+m-2-x3-s2;
		p=(s2+m+1)/2;
		x3=qry(n,p);
		int s4=n+m-2-x3-s1;//s3=d1+d2,s4=d3+d4;
		// cout<<s3<<' '<<s4<<endl;
		int d1=(s1+s3)/2,d2=(s3-s1)/2,d3=(s2+s4)/2,d4=(s4-s2)/2;
		if(f(d1+1,d3+1))f(n-d2,m-d4);
		else
		{
			f(d1+1,m-d4);
			f(n-d2,d3+1);
		}
	}
	return 0;
}