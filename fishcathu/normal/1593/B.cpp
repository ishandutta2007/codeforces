#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=50;
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
char a[N];
void solve()
{
    scanf("%s",a+1);
    int n=strlen(a+1);
    for(int i=n,j=0,k=0;1;--i)
    {
        if(j&&(a[i]=='0'||a[i]=='5')||k&&(a[i]=='2'||a[i]=='7'))
        {
            write(n-i-1,'\n');
            return;
        }
        if(a[i]=='0')j=1;
        if(a[i]=='5')k=1;
    }
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}