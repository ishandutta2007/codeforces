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
const int N=1E5+10;
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
void solve()
{
    vector<pii>a(read());
    for(auto &[x,y]:a)
    {
        y=read();
        for(int i=1;i>1-y;--i)x=max(x,(int)read()+i);
    }
    sort(a.begin(),a.end());
    int res=0,t=0;
    for(auto [x,y]:a)
    {
        res=max(res,x-t);
        t+=y;
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