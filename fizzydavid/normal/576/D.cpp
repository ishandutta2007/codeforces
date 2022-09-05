//by yjz
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
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
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
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,m;
bitset<151>h[151],v[151];
struct matrix
{
    bitset<151> a[151];
    matrix()
    {
        for(int i=1;i<=150;i++)a[i].reset();
    }
    void set1()
    {
        for(int i=1;i<=n;i++)a[i][i]=1;
    }
    matrix operator*(const matrix &tmp)
    {
        matrix res;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j])
                    res.a[i]|=tmp.a[j];
        return res;
    }
}res,pw[40],mo;
struct edge
{
    int x,y,c;
}a[155];
vector<int>cs;
int main()
{
    getii(n,m);
    for(int i=1;i<=m;i++)
    {
        getiii(a[i].x,a[i].y,a[i].c);
        cs.PB(a[i].c);
    }
    cs.PB(2000000000);
    sort(cs.begin(),cs.end());
    cs.erase(unique(cs.begin(),cs.end()),cs.end());
    res.set1();
    int last=0;
    for(int i=0;i<cs.size();i++)
    {
//      cout<<i<<":"<<endl;
        int dis=cs[i]-last,mx=0;
//      cout<<"dis:"<<dis<<endl;
//      res.see();
        pw[0]=mo;
        for(int j=1;j<=n;j++)pw[0].a[j][j]=1;
        for(int j=1;(1ll<<j)<=dis;j++,mx=j)pw[j]=pw[j-1]*pw[j-1];
        bool f=0;
        matrix tmp=res;
        for(int j=mx;j>=0;j--)
        {
            if(f||((dis>>j)&1))
            {
                matrix nxt=pw[j]*tmp;
                if(!nxt.a[n][1])
                {
                    tmp=nxt,last+=(1<<j);
                }else f=1;
            }
        }
        if(last!=cs[i])
        {
            putsi(last+1);
            return 0;
        }
        pw[0]=mo;
        for(int j=1;(1ll<<j)<=dis;j++,mx=j)pw[j]=pw[j-1]*pw[j-1];
        for(int j=mx;j>=0;j--)
            if((dis>>j)&1)
                res=pw[j]*res;
        for(int j=1;j<=m;j++)
        {
            if(cs[i]==a[j].c)
            {
                mo.a[a[j].y][a[j].x]=1;
            }
        }
    }
    puts("Impossible");
    return 0;
}