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
const int N=5010;
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
int a[N>>1],b[N],f[N>>1][N];
int main()
{
    int n=read(),y=0,z=0;
    for(int i=1;i<=n;++i)(read()?a[++y]:b[++z])=i;
    for(int i=1;i<=y;++i)
    {
        f[i][i-1]=inf;
        for(int j=i;j<=z;++j)
        {
            f[i][j]=min(f[i][j-1],f[i-1][j-1]+abs(b[j]-a[i]));
        }
    }
    write(f[y][z],'\n');
}