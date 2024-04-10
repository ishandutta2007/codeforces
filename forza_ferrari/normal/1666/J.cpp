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
int f[1010][1010],pos[1010][1010],p[1000010],c[1010][1010],n;
int qry(int l1,int r1,int l2,int r2)
{
	if(l1>r1||l2>r2)return 0;
	return c[r1][r2]-c[l1-1][r2]-c[r1][l2-1]+c[l1-1][l2-1];
}
int sum(int l,int r)
{
	return qry(1,l-1,l,r)+qry(r+1,n,l,r);
}
int dfs(int l,int r)
{
	if(l>r)return 0;
	if(l==r)
	{
		pos[l][r]=l;
		return 0;
	}
	if(f[l][r]!=-1)return f[l][r];
	int ans=1e16;
	for(int i=l;i<=r;i++)
	{
		int nxt=dfs(l,i-1)+dfs(i+1,r)+(i!=l)*sum(l,i-1)+(i!=r)*sum(i+1,r);
		if(nxt<ans)ans=nxt,pos[l][r]=i;
	}
	return f[l][r]=ans;
}
void dfs2(int l,int r,int pre)
{
	// cout<<l<<' '<<r<<' '<<pos[l][r]<<'\n';
	if(l>r)return;
	p[pos[l][r]]=pre;
	dfs2(l,pos[l][r]-1,pos[l][r]);
	dfs2(pos[l][r]+1,r,pos[l][r]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=qr;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)in(c[i][j]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)c[i][j]+=c[i-1][j]+c[i][j-1]-c[i-1][j-1];
	}
	memset(f,-1,sizeof(f));
	dfs(1,n);
	dfs2(1,n,0);
	for(int i=1;i<=n;i++)cout<<p[i]<<' ';
	return 0;
}