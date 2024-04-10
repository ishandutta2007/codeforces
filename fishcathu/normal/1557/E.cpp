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
int ask(int u,int v)
{
    printf("%d %d\n",u,v);
    fflush(stdout);
    char a[10];
    scanf("%s",a);
    if(a[2]=='n')return 2;
    if(a[0]=='D')return 1;
    if(a[0]=='U')return -1;
    return 0;
}
void solve()
{
    if(ask(1,1)>1)return;
    for(int u=1,v=2,flag=0;1;)
    {
        int t=ask(u,v);
        if(t>1)return;
        if(t>0)++u,flag=1;
        else
        {
            if(t)flag=1;
            v+=2;
            if(v>8)
            {
                if(flag)v=2,flag=0;
                else ++u,v=8,flag=1;
            }
        }
    }
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}