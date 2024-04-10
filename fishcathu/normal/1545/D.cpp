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
ll b[N];
int main()
{
    int m=read(),n=read();
    for(int i=1;i<=n;++i)
    {
        for(int j=m;j--;)
        {
            int t=read();
            a[i]+=t;
            b[i]+=t*1LL*t;
        }
    }
    for(int i=2,k=(a[n]-a[1])/(n-1);1;++i)
    {
        int res=a[i]-a[i-1]-k;
        if(!res)continue;
        write(i-1,' ');
        ll ans=b[i]*2-b[i-1]-b[i+1];
        if(i<4)ans-=b[5]*2-b[4]-b[6];
        else ans-=b[2]*2-b[1]-b[3];
        write((ans/2-res*1LL*res)/2/res,'\n');
        return 0;
    }
}