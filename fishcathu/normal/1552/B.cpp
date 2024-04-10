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
const int N=5E4+10;
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
int a[N][5];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<5;++j)
        {
            a[i][j]=read();
        }
    }
    int ans=1;
    for(int i=2;i<=n;++i)
    {
        int res=0;
        for(int j=0;j<5;++j)
        {
            if(a[i][j]<a[ans][j])
            {
                ++res;
            }
        }
        if(res>2)ans=i;
    }
    for(int i=1;i<=n;++i)
    {
        int res=0;
        for(int j=0;j<5;++j)
        {
            if(a[i][j]<a[ans][j])
            {
                ++res;
            }
        }
        if(res>2)
        {
            puts("-1");
            return;
        }
    }
    write(ans,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}