#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3E5+10;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
tuple<int,bool,int>a[N<<1];
vector<int>to[N];
set<int>q;
int num[N],f[N],pre[N];
bool vis[N];
int main()
{
    int n=read(),m=0;
    for(int x=read();x--;)
    {
        int i=read();
        a[++m]={read(),1,i};
        a[++m]={read()+1,0,i};
    }
    sort(a+1,a+1+m);
    for(int i=1;i<=m;++i)
    {
        auto [w,b,p]=a[i];
        if(b)
        {
            if(!num[p]++)
            {
                set<int>::iterator it=q.insert(p).fi;
                if(it!=q.begin())to[p].pb(*prev(it));
                if(it!=--q.end())to[*next(it)].pb(p);
            }
        }
        else
        {
            if(!--num[p])
            {
                q.erase(p);
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j:to[i])
        {
            if(f[j]>f[i])
            {
                f[i]=f[j];
                pre[i]=j;
            }
        }
        ++f[i];
    }
    int w=max_element(f+1,f+1+n)-f;
    for(int i=w;i;i=pre[i])vis[i]=1;
    write(n-f[w],'\n');
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            write(i,' ');
        }
    }
}