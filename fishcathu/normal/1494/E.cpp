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
map<pii,char>w;
int b[2];
char getch()
{
    char c;
    do c=getchar();while(c==10||c==32);
    return c;
}
int main()
{
    read();
    for(int x=read();x--;)
    {
        char c=getch();
        if(c=='?')
        {
            puts(b[read()&1]?"YES":"NO");
            continue;
        }
        int u=read(),v=read();
        pii l=mp(u,v),r=mp(v,u);
        if(c=='+')
        {
            c=getch();
            w[l]=c;
            if(w.count(r))
            {
                ++b[1];
                if(w[r]==c)++b[0];
            }
        }
        else
        {
            c=w[l];
            w.erase(l);
            if(w.count(r))
            {
                --b[1];
                if(w[r]==c)--b[0];
            }
        }
    }
}