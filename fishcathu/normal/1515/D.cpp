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
int a[N],b[N];
void solve()
{
    int n=read(),l=read(),r=read();
    for(int i=1;i<=n;++i)a[i]=b[i]=0;
    for(int i=l;i--;)++a[read()];
    for(int i=r;i--;)++b[read()];
    for(int i=1;i<=n;++i)
    {
        int x=min(a[i],b[i]);
        a[i]-=x;
        b[i]-=x;
        l-=x;
        r-=x;
    }
    if(l>r)
    {
        swap(l,r);
        for(int i=1;i<=n;++i)swap(a[i],b[i]);
    }
    int ans=0;
    for(int i=1;i<=n&&l!=r;++i)
    {
        while(b[i]>=2)
        {
            b[i]-=2;
            r-=2;
            ++ans;
            if(r==l)break;
        }
    }
    write(r+ans,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}