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
const int N=2010;
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
bitset<N>b;
bool ask(int x,int l,int r)
{
    printf("? 1 ");
    write(r-l+1,'\n');
    write(x,'\n');
    while(l<=r)write(l++,' ');
    fflush(stdout);
    return read();
}
void solve()
{
    int n=read();
    int k=2;
    while(!ask(k,1,k-1))++k;
    int l=1;
    for(int r=k-1;l!=r;)
    {
        int m=l+r>>1;
        ask(k,l,m)?r=m:l=m+1;
    }
    b[l]=b[k]=1;
    int s=n-2;
    for(int i=k;++i<=n;)
    {
        if(ask(k,i,i))
        {
            b[i]=1;
            --s;
        }
    }
    printf("! ");
    write(s,' ');
    for(int i=1;i<=n;++i)
    {
        if(b[i])b[i]=0;
        else write(i,' ');
    }
    fflush(stdout);
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}