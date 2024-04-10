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
int a[N][2];
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)a[i][0]=read();
    for(int i=1;i<=n;++i)a[i][1]=read();
    for(int i=1,b[2]={0};i<=n;++i)
    {
        bool k=a[i][1]>a[i][0]||a[i][1]==a[i][0]&&b[1]>b[0];
        ll t=a[i][k]+b[k]-a[i][!k]*1LL*m;
        if(t>m)
        {
            puts("NO");
            return 0;
        }
        if(t>0)
        {
            b[k]=t;
            b[!k]=0;
        }
        else b[0]=b[1]=0;
    }
    puts("YES");
}