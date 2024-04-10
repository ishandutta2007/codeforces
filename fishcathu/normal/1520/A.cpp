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
typedef pair<ll,ll> pll;
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
char a[N];
int b[26];
bool solve()
{
    int n=read();
    memset(b,0,sizeof b);
    scanf("%s",a+1);
    for(int i=1;i<=n;++i)
    {
        a[i]-=65;
        if(b[a[i]]&&b[a[i]]!=i-1)return 0;
        b[a[i]]=i;
    }
    return 1;
}
int main()
{
    for(int x=read();x--;)
    {
        puts(solve()?"YES":"NO");
    }
}