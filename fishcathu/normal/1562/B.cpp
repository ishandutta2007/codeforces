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
const int N=60;
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
bool check(int x)
{
    if(x==1)return 0;
    for(int i=2;i*i<=x;++i)
    {
        if(!(x%i))
        {
            return 0;
        }
    }
    return 1;
}
void solve()
{
    int n=read();
    scanf("%s",a+1);
    for(int i=1;i<=n;++i)
    {
        if(!check(a[i]&15))
        {
            puts("1");
            putchar(a[i]);
            return;
        }
    }
    for(int j=2;j<=n;++j)
    {
        for(int i=1;i<j;++i)
        {
            if(!check((a[i]&15)*10+a[j]-48))
            {
                puts("2");
                putchar(a[i]);
                putchar(a[j]);
                return;
            }
        }
    }

}
int main()
{
    for(int x=read();x--;)
    {
        solve();
        putchar('\n');
    }
}