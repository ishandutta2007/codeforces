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
const int N=510;
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
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N][5010];
pii b[N];
int fa[N<<1],val[N<<1];
int main()
{
    int n=read(),s=n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            b[j].fi=read();
            b[j].se=j;
        }
        sort(b+1,b+1+n);
        val[i]=b[1].fi;
        for(int j=2,k=i;j<=n;++j)
        {
            int t=b[j].fi;
            if(t==b[j-1].fi)continue;
            if(b[j].se<i)
            {
                fa[k]=a[b[j].se][t];
                break;
            }
            a[i][t]=k=fa[k]=++s;
            val[k]=t;
        }
    }
    write(s,'\n');
    for(int i=1;i<=s;++i)write(val[i],' ');
    putchar('\n');
    write(a[1][b[n].fi],'\n');
    for(int i=1;i<=s;++i)if(fa[i])
    {
        write(i,' ');
        write(fa[i],'\n');
    }
}