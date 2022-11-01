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
const int N=2E7+1;
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
int a[N],p[1270608];
int b,c,ans;
void f(int x)
{
    x+=c;
    if(x%b)return;
    ans+=a[x/b];
}
void solve()
{
    b=read();
    c=read();
    ans=0;
    int x=read();
    int i=1;
    while(i*i<x)
    {
        if(!(x%i))
        {
            f(i);
            f(x/i);
        }
        ++i;
    }
    if(i*i==x)f(i);
    write(ans,'\n');
}
int main()
{
    a[1]=1;
    for(int i=2,s=0;i<N;++i)
    {
        if(!a[i])
        {
            a[i]=2;
            p[++s]=i;
        }
        for(int j=1;j<=s;++j)
        {
            int t=i*p[j];
            if(t>=N)break;
            a[t]=a[i];
            if(!(i%p[j]))break;
            a[t]<<=1;
        }
    }
    for(int x=read();x--;)
    {
        solve();
    }
}