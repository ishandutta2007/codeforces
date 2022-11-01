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
const int N=1E5+10;
const int inf=0x7f7f7f7f;
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
int f[N],g[N],q[N];
int main()
{
    int n=read();
    memset(f+1,0x7f,n<<2);
    for(int m=read();m--;)
    {
        int a=read(),b=read();
        memcpy(g,f,n+1<<2);
        for(int l=1,r=0,i=0;i<=n;++i)
        {
            if(l<=r&&g[q[r]]>=g[i])--r;
            q[++r]=i;
            if(q[l]<i+a-b)++l;
            int j=b-i;
            if(j>=0&&j<=n)f[j]=min(f[j],g[q[l]]+1);
            f[i]=min(f[i],g[q[l]]+2);
        }
    }
    if(f[n]==inf)puts("Hungry");
    else
    {
        puts("Full");
        write(f[n],'\n');
    }
}