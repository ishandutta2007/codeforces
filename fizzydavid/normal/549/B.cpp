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
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
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

int n,t[111];
vector<int>con[111],rev[111];
bool used[111];
void dfs(int x)
{
    for(int _=0;_<rev[x].size();_++)
    {
        int i=rev[x][_];
        if(!used[i])
        {
            used[i]=1;
            for(int j=0;j<con[i].size();j++)
            {
                t[con[i][j]]--;
            }
            bool ok=1;
            for(int j=1;j<=n;j++)
            {
                if(t[j]==0)
                {
                    dfs(j);
                    ok=0;
                    break;
                }
            }
            if(ok)
            {
                int cnt=0;
                for(int j=1;j<=n;j++)cnt+=used[j];
                putsi(cnt);
                for(int j=1;j<=n;j++)if(used[j])puti(j);
                putendl();
                exit(0);
            }
            used[i]=0;
            for(int j=0;j<con[i].size();j++)
            {
                t[con[i][j]]++;
            }
        }
    }
    used[x]=0;
}
int main()
{
    geti(n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(getchar()=='1')
            {
                con[i].PB(j);
                rev[j].PB(i);
            }
        }
        getchar();
    }
    for(int i=1;i<=n;i++)
    {
        geti(t[i]);
        if(t[i]==0&&rev[i].size()==0)
        {
            puts("-1");
            return 0;
        }
    }
    bool ok=0;
    for(int i=1;i<=n;i++)
    {
        if(t[i]==0)
        {
            ok=1;
            dfs(i);
            break;
        }
    }
    if(ok)
    {
        puts("-1");
    }
    else
    {
        puts("0");
    }
    return 0;
}