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
const int N=2030;
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
int a[N],b[N];
vector<int>q;
void rev(int n)
{
    q.pb(n);
    for(int i=1,j=n;i^j;++i,--j)
    {
        swap(a[i],a[j]);
        b[a[i]]=i;
        b[a[j]]=j;
    }
}
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)b[a[i]=read()]=i;
    for(int i=1;i<=n;++i)
    {
        if(a[i]+i&1)
        {
            puts("-1");
            return;
        }
    }
    q.clear();
    for(int i=n,j=i-1;j;)
    {
        if(b[i]==i&&b[j]==j)i-=2,j-=2;
        else if(b[i]==1&&b[j]==2)rev(i);
        else if(b[i]==b[j]+1)rev(b[i]);
        else if(b[i]==b[j]-1)rev(i);
        else if(b[i]==1)rev(b[j]-1);
        else rev(b[i]);
    }
    write(q.size(),'\n');
    for(int x:q)write(x,' ');
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}