//while(true)rp++;
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
#define puti(x) putnum(x)
#define putii(x,y) puti(x),putnum(y)
#define putiii(x,y,z) putii(x,y),putnum(z)
#define putsi(x) puti(x),putendl()
#define putsii(x,y) putii(x,y),putendl()
#define putsiii(x,y,z) putiii(x,y,z),putendl()
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
int n,s1,s2,a[11],b[11];
set<pair<int,int> >s;
void leftshift()
{
    for(int i=2;i<=s1;i++)a[i-1]=a[i];s1--;
    for(int i=2;i<=s2;i++)b[i-1]=b[i];s2--;
}
int main()
{
    geti(n);
    geti(s1);
    for(int i=1;i<=s1;i++)geti(a[i]);
    geti(s2);
    for(int i=1;i<=s2;i++)geti(b[i]);
    int ans=0;
    while(true)
    {
        int topa=a[1],topb=b[1];
        leftshift();
        if(topa>topb)
        {
            a[++s1]=topb;
            a[++s1]=topa;
        }
        else
        {
            b[++s2]=topa;
            b[++s2]=topb;
        }
        ans++;
        if(s1==0)
        {
            puti(ans),putsp(),puts("2");
            return 0;
        }
        else if(s2==0)
        {
            puti(ans),putsp(),puts("1");
            return 0;
        }
        int state=0,base=1;
        for(int i=1;i<=s1;i++)state+=base*(a[i]-1),base*=10;
        for(int i=1;i<=s2;i++)state+=base*(b[i]-1),base*=10;
        if(s.find(MP(state,s1))!=s.end())
        {
            puts("-1");
            return 0;
        }
        s.insert(MP(state,s1));
    }
    return 0;
}