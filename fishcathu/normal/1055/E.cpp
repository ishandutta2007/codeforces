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
const int N=1510;
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
int s,y,z;
int a[N],f[N][N];
pii b[N];
bool check(int x)
{
    for(int i=1;i<=s;++i)
    {
        for(int j=max(1,y+i-s);j<=i;++j)
        {
            f[i][j]=0;
            int res=0,r=b[i].se;
            for(int k=i-1;k>=j-1;--k)
            {
                while(r>=b[i].fi&&r>b[k].se)res+=a[r--]<=x;
                f[i][j]=max(f[i][j],res+f[k][j-1]);
            }
        }
    }
    for(int i=y;i<=s;++i)
    {
        if(f[i][y]>=z)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n=read(),m=read();
    y=read(),z=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=m;++i)b[i].fi=read(),b[i].se=read();
    sort(b+1,b+1+m);
    for(int i=1;i<=m;++i)
    {
        if(b[i].se>b[s].se)
        {
            b[++s]=b[i];
        }
    }
    y=min(y,s);
    int l=1;
    for(int r=inf;l!=r;)
    {
        int mid=l+r>>1;
        check(mid)?r=mid:l=mid+1;
    }
    write(l==inf?-1:l,'\n');
}