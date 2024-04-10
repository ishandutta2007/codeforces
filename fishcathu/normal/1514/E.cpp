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
const int N=100;
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
int a[N];
bitset<N>b[N];
bool cmp(const int l,const int r)
{
    printf("1 %d %d\n",l,r);
    fflush(stdout);
    return read();
}
bool ask(const int u,const int v)
{
    printf("2 %d %d ",u,v);
    for(int i=0;i<v;++i)write(a[i],' ');
    putchar('\n');
    fflush(stdout);
    return read();
}
void solve()
{
    int n=read();
    for(int i=0;i<n;++i)
    {
        a[i]=i;
        for(int j=0;j<n;++j)
        {
            b[i][j]=1;
        }
    }
    stable_sort(a,a+n,cmp);
    for(int i=n-1,j=i;1;--i)
    {
        while(j&&ask(a[i],j))--j;
        if(!j)break;
        if(i==j)
        {
            for(int u=0;u<i;++u)
            {
                for(int v=i;v<n;++v)
                {
                    b[a[v]][a[u]]=0;
                }
            }
            --j;
        }
    }
    puts("3");
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            putchar(b[i][j]|48);
        }
        putchar('\n');
    }
    fflush(stdout);
    read();
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}