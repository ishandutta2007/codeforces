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
int a,b,x,y;
bool check(int n)
{
    ll t=x*1LL*n;
    if(a<t||b<t)return 0;
    if(!y)return 1;
    return (a-t)/y+(b-t)/y>=n;
}
void solve()
{
    a=read(),b=read(),x=read(),y=read();
    if(x>y)swap(x,y);
    y-=x;
    int l=0;
    for(int r=inf;l!=r;)
    {
        int m=l+r+2>>1;
        check(m)?l=m:r=m-1;
    }
    write(l,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}