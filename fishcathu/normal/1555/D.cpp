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
const int N=2E5+10;
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
int a[N][3][3];
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<3;++j)
        {
            for(int k=0;k<3;++k)
            {
                a[i][j][k]=a[i-1][j][k];
            }
        }
        char c;
        do c=getchar();while(c<97);
        ++a[i][c-97][i%3];
    }
    while(m--)
    {
        int l=read()-1,r=read();
        int res=0;
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                if(j==i)continue;
                int k=i^j^3;
                res=max(res,a[r][0][i]+a[r][1][j]+a[r][2][k]-a[l][0][i]-a[l][1][j]-a[l][2][k]);
            }
        }
        write(r-l-res,'\n');
    }
}