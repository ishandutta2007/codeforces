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
const int N=310;
const int inf=1<<30;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
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
int a[N];
void solve()
{
    int n=read(),m=read(),res=0;
    while(n--)
    {
        for(int i=1;i<=m;++i)
        {
            a[i]=read();
            for(int j=1;j<i;++j)
            {
                if(a[j]<a[i])
                {
                    ++res;
                }
            }
        }
    }
    write(res,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}