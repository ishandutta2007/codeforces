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
void solve()
{
    int n=read(),m=read(),s=n*m;
    bool b=0,c=0;
    for(int i=n;i--;)
    {
        int t=read();
        (t==m?b:c)=1;
        s-=t; 
    }
    if(!c)puts("0");
    else if(b||!s)puts("1");
    else puts("2");
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}