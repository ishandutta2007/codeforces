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
int n,a[200111],p[200111],cnt[200111],mx=1,ans[200111];
bool f[200111];
map<int,vector<int> >mp;
int gf(int x)
{
    return x==p[x]?x:p[x]=gf(p[x]);
}
void un(int x,int y)
{
    x=gf(x),y=gf(y);
    if(x==y)return;
    p[y]=x;
    cnt[x]+=cnt[y];
    mx=max(mx,cnt[x]);
}
int main()
{
    geti(n);
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        geti(a[i]);
        mp[a[i]].PB(i);
        cnt[i]=1;
    }
    for(map<int,vector<int> >::iterator it=--mp.end();;it--)
    {
        vector<int> &v=it->SS;
        for(int i=0;i<v.size();i++)
        {
            f[v[i]]=1;
            if(f[v[i]-1])un(v[i]-1,v[i]);
            if(f[v[i]+1])un(v[i]+1,v[i]);
            ans[mx]=max(ans[mx],it->FF);
        }
        if(it==mp.begin())break;
    }
    int res=ans[n];
    for(int i=n;i>=1;i--)
    {
        if(ans[i]!=0)res=ans[i];
        ans[i]=res;
    }
    for(int i=1;i<=n;i++)puti(ans[i]),putsp();
    return 0;
}