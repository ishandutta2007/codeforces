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
int a[4];
int main()
{
    int n=read();
    ll ans=1;
    for(int i=1;i<=3;++i)ans=ans*(n+1-i)/i;
    for(int i=1;i<=n;++i)++a[(read()&2)|(read()&2)>>1];
    for(int i=0;i<4;++i)
    {
        ll res=1;
        for(int j=0;j<4;++j)
        {
            if(j^i)
            {
                res*=a[j];
            }
        }
        ans-=res;
    }
    write(ans,'\n');
}