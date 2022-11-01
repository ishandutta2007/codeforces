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
const int N=2E5+10,M=102;
const int inf=1<<30;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
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
mt19937 mtrand(time(0));
bool b[N];
ll a[M][M];
int c[N],n;
ll lcm(int l,int r){return l*1LL*r/__gcd(l,r);}
ll ask(int l,int r){printf("? %d %d\n",l,r),fflush(stdout);return read();}
void solve()
{
    n=read();
    if(n<M)
    {
        for(int i=2;i<=n;++i)for(int j=1;j<i;++j)a[i][j]=a[j][i]=ask(i,j);
        if(n==3)
        {
            for(int i=1;1;++i)
            {
                c[1]=i,c[2]=i+1,c[3]=i+2;
                do
                {
                    if(lcm(c[1],c[2])==a[1][2]&&lcm(c[1],c[3])==a[1][3]&&lcm(c[2],c[3])==a[2][3])
                    {
                        return;
                    }
                }while(next_permutation(c+1,c+4));
            }
        }
        else
        {
            for(int i=1;i<=n;++i)
            {
                ll t=0;
                for(int j=1;j<=n;++j)if(j^i)t=__gcd(t,a[i][j]);
                c[i]=t;
            }
        }
    }
    else
    {
        int x=0,p;
        for(int i=250;i--;)
        {
            int l=mtrand()%n+1;
            ll t=0;
            for(int j=20;j--;)
            {
                int r=mtrand()%n+1;
                if(r==l)continue;
                t=__gcd(t,ask(l,r));
            }
            if(!b[t]&&t>x)x=t,p=l;
        }
        for(int i=1;i<=n;++i)c[i]=i==p?x:ask(i,p)/x;
    }
}
int main()
{
    for(int i=2;i<N;++i)if(!b[i])for(int j=i<<1;j<N;j+=i)b[j]=1;
    for(int x=read();x--;)
    {
        solve();
        printf("! ");
        for(int i=1;i<=n;++i)write(c[i],' ');
        putchar('\n');
        fflush(stdout);
    }
}