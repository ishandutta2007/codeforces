#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1<<17;
const int inf=1<<30;
template<typename T>bool cmin(T &l,T r){return l>r?l=r,1:0;}
template<typename T>bool cmax(T &l,T r){return l<r?l=r,1:0;}
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
int f[N<<1][6];
void modify(int i,int x)
{
    i+=N;
    f[i][0]=f[i][1]=f[i][2]=0;
    f[i][x-97]=1;
    while(i>>=1)
    {
        f[i][0]=f[ls][0]+f[rs][0];
        f[i][1]=f[ls][1]+f[rs][1];
        f[i][2]=f[ls][2]+f[rs][2];
        f[i][3]=min(f[ls][3]+f[rs][1],f[rs][3]+f[ls][0]);
        f[i][4]=min(f[ls][4]+f[rs][2],f[rs][4]+f[ls][1]);
        f[i][5]=min({f[ls][5]+f[rs][2],f[rs][5]+f[ls][0],f[ls][3]+f[rs][4]});
    }
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)modify(i,getchar());
    while(m--)
    {
        int p=read();
        modify(p,getchar());
        write(f[1][5],'\n');
    }
}