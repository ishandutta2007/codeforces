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

void solve()
{
    int n=read();
    string a;
    cin>>a;
    if(a.find("aa")<n)puts("2");
    else if(a.find("aba")<n||a.find("aca")<n)puts("3");
    else if(a.find("abca")<n||a.find("acba")<n)puts("4");
    else if(a.find("abbacca")<n||a.find("accabba")<n)puts("7");
    else puts("-1");
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}