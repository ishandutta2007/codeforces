#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1E6+10;
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
char q[N];
void solve()
{
    int n=read(),m=read();
    int a=1,b=n,c=1,d=m;
    scanf("%s",q);
    for(int i=0,j=0,k=0;q[i];++i)
    {
        if(q[i]=='L')
        {
            --k;
            int t=max(c,1-k);
            if(t>d)break;
            c=t;
        }
        else if(q[i]=='R')
        {
            ++k;
            int t=min(d,m-k);
            if(t<c)break;
            d=t;
        }
        else if(q[i]=='U')
        {
            --j;
            int t=max(a,1-j);
            if(t>b)break;
            a=t;
        }
        else
        {
            ++j;
            int t=min(b,n-j);
            if(t<a)break;
            b=t;
        }
    }
    printf("%d %d\n",a,c);
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}