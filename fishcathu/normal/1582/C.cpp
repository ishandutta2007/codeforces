#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1E5+10;
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
char a[N];
int n;
int check(char x)
{
    int l=0,r=n+1,res=0;
    while(l<r)
    {
        int s=0;
        while(a[++l]==x)++s;
        while(a[--r]==x)--s;
        if(a[l]^a[r])return inf;
        res+=abs(s);
    }
    return res;
}
void solve()
{
    n=read();
    scanf("%s",a+1);
    int ans=inf;
    for(char x='a';x<='z';++x)cmin(ans,check(x));
    write(ans^inf?ans:-1,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}