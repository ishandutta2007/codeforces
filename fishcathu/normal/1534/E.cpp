#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=510;
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
int n,m,x,y,z;
int a[N][N],b[N];
bool check()
{
    int t=x*m-n;
    if(t<0||t%2)return 0;
    t>>=1;
    y=t/n;
    z=t%n;
    return (y+!!z<<1|1)<=x;
}
int main()
{
    n=read(),m=read();
    for(x=1;x<=n&&!check();++x);
    if(x>n)puts("-1");
    else
    {
        y<<=1;
        for(int i=1;i<=z;++i)b[i]=y+3;
        for(int i=z+1;i<=n;++i)b[i]=y+1;
        for(int j=1,k=1;j<=m;++j)
        {
            for(int i=1;i<=x;++i)
            {
                if(!b[k])++k;
                a[i][j]=k;
                --b[k];
            }
        }
        int res=0;
        for(int i=1;i<=x;++i)
        {
            printf("? ");
            for(int j=1;j<=m;++j)write(a[i][j],' ');
            putchar('\n');
            fflush(stdout);
            res^=read();
        }
        printf("! %d\n",res);
    }
}