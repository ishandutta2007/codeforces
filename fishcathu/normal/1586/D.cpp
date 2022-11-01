#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=110;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
void cmin(auto &l,auto r){l=l<r?l:r;}
void cmax(auto &l,auto r){l=l>r?l:r;}
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
int a[N],n;
int ask(int x,int y)
{
    printf("? ");
    for(int i=n;--i;)write(x,' ');
    write(y,'\n');
    fflush(stdout);
    return read();
}
int main()
{
    a[n=read()]=1;
    while(a[n]<n&&ask(a[n]+1,1))++a[n];
    for(int i=1;i<=n;++i)
    {
        if(i==a[n])continue;
        a[ask(a[n],i)]=i;
    }
    printf("! ");
    for(int i=1;i<=n;++i)write(a[i],' ');
}