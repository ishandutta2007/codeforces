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
const int N=1010;
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
int a[N];
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    ll ans=0;
    for(int i=1;i<n;i+=2)
    {
        ll y=0,z=0;
        for(int j=i+1;j<=n;++j)
        {
            if(j&1)z+=a[j];
            else
            {
                if(a[i]<y)break;
                ans+=max(min(a[i]-y+!!y,a[j]-z+!!z),0LL);
                z-=a[j];
                if(z<0)y-=z,z=0;
            }
        }
    }
    write(ans,'\n');
}