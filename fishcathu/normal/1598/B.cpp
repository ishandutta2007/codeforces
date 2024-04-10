#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1010;
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
bool a[N][5];
int b[5];
void solve()
{
    int n=read();
    for(int j=0;j<5;++j)b[j]=0;
    for(int i=0;i<n;++i)for(int j=0;j<5;++j)b[j]+=a[i][j]=read();
    for(int j=1;j<5;++j)
    {
        if(b[j]<n>>1)continue;
        for(int k=0;k<j;++k)
        {
            if(b[k]<n>>1)continue;
            int i=0;
            while(i<n&&a[i][j]|a[i][k])++i;
            if(i==n){puts("YES");return;}
        }
    }
    puts("NO");
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}