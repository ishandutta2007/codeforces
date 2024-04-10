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
int n,m,sz;
char vc[27],s[222],t[222];
vector<pair<int,int> >l[4];
vector<int>con[422];
int st[422],stsz,low[422],dfn[422],ti,tot,fa[422];
bool inst[422],vis[422];
void dfs(int x)
{
    st[stsz++]=x;inst[x]=1;vis[x]=1;
    dfn[x]=++ti;low[x]=dfn[x];
    for(int i=0;i<con[x].size();i++)
    {
        if(!vis[con[x][i]])dfs(con[x][i]),low[x]=min(low[x],low[con[x][i]]);
        else if(inst[con[x][i]])low[x]=min(low[x],dfn[con[x][i]]);
    }
    if(low[x]==dfn[x])
    {
        tot++;
        while(st[stsz]!=x)
        {
            fa[st[--stsz]]=tot;
            inst[st[stsz]]=0;
        }
    }
}
bool check(int len)
{
    for(int i=1;i<=2*n;i++)con[i].clear();
    for(int i=0;i<len;i++)
    {
        if(vc[t[i]-'a']=='C')con[i+1].PB(n+i+1);else con[n+i+1].PB(i+1);
    }
    for(int i=0;i<l[0].size();i++)
    {
        con[l[0][i].FF].PB(l[0][i].SS);
        con[l[0][i].SS+n].PB(l[0][i].FF+n);
    }
    for(int i=0;i<l[1].size();i++)
    {
        con[l[1][i].FF].PB(l[1][i].SS+n);
        con[l[1][i].SS].PB(l[1][i].FF+n);
    }
    for(int i=0;i<l[2].size();i++)
    {
        con[l[2][i].FF+n].PB(l[2][i].SS);
        con[l[2][i].SS+n].PB(l[2][i].FF);
    }
    for(int i=0;i<l[3].size();i++)
    {
        con[l[3][i].FF+n].PB(l[3][i].SS+n);
        con[l[3][i].SS].PB(l[3][i].FF);
    }
    memset(inst,0,sizeof(inst));
    memset(vis,0,sizeof(vis));
    memset(fa,0,sizeof(fa));
    stsz=0;ti=0;tot=0;
    for(int i=1;i<=n*2;i++)if(!vis[i])dfs(i);
    bool ok=1;
    for(int i=1;i<=n;i++)ok&=(fa[i]!=fa[n+i]);
    return ok;
}
int main()
{
    scanf("%s",vc);
    sz=strlen(vc);
    getii(n,m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        char c1,c2;
        geti(x);
        c1=getchar();
        geti(y);
        c2=getchar();
        l[(c1=='C')*2+(c2=='C')].PB(MP(x,y));
    }
    scanf("%s",s);
    for(int i=0;i<n;i++)t[i]=s[i];
    if(check(n))
    {
        printf("%s",s);
        return 0;
    }
    int tmp=-1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=s[i]+1;j<'a'+sz;j++)
        {
            if(vc[j-'a']=='V')
            {
                t[i]=j;
                if(check(i+1))tmp=i;
                break;
            }
        }
        for(int j=s[i]+1;j<'a'+sz;j++)
        {
            if(vc[j-'a']=='C')
            {
                if(tmp==-1||tmp!=-1&&j<t[i])
                {
                    char prev=t[i];
                    t[i]=j;
                    if(!check(i+1))t[i]=prev;else tmp=i;
                    break;
                }
            }
        }
        if(tmp!=-1)break;
        t[i]=s[i];
    }
    if(tmp==-1)
    {
        puts("-1");
        return 0;
    }
    for(int i=tmp+1;i<n;i++)
    {
        bool ok=0;
        for(int j=0;j<sz;j++)
        {
            if(vc[j]=='V')
            {
                t[i]='a'+j;
                if(check(i+1))ok=1;
                break;
            }
        }
        for(int j=0;j<sz;j++)
        {
            if(vc[j]=='C')
            {
                if(!ok||ok&&j+'a'<t[i])
                {
                    char prev=t[i];
                    t[i]='a'+j;
                    if(!check(i+1))t[i]=prev;else ok=1;
                }
                break;
            }
        }
        if(!ok)
        {
            puts("-1");
            return 0;
        }
    }
    printf("%s\n",t);
    return 0;
}