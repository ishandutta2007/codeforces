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
int a[N][N];
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i][0]=-1;
    const int b[2][2]={0,-1,1,0};
    for(int i=1;i<=n;++i)
    {
        a[i][i]=read();
        for(int j=a[i][i],u=i,v=i;--j;)
        {
            bool t=a[u+b[0][0]][v+b[0][1]];
            a[u+=b[t][0]][v+=b[t][1]]=a[i][i];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            write(a[i][j],' ');
        }
        putchar('\n');
    }
}