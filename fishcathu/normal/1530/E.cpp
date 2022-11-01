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
const char N=123;
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
#define put(x) putchar(x),--a[x]
int a[N];
char nex(char x)
{
    char y=x;
    while(y<N&&!a[++y]);
    return y;
}
void solve()
{
    int n=0;
    char c;
    do c=getchar();while(c<97);
    do ++a[c],++n;while((c=getchar())>96);
    for(char i=97;i<N;++i)
    {
        if(a[i]==1)
        {
            put(i);
            return;
        }
    }
    char u=nex(96);
    put(u);
    if(n>=a[u]<<1)
    {
        while(1)
        {
            put(u);
            if(!a[u])break;
            put(nex(u));
        }
    }
    else
    {
        char v=nex(u),t=nex(v);
        if(t^N)
        {
            put(v);
            while(a[u])put(u);
            put(t);
        }
        else while(a[v])put(v);
    }
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
        for(char i=97;i<N;++i)
        {
            while(a[i])
            {
                put(i);
            }
        }
        putchar('\n');
    }
}