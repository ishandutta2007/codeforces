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
const int N=3E5;
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
int a[N+1];
ll b[N+1];
void adda(int x){for(;x<=N;x+=x&-x)++a[x];}
void addb(int x,int v){for(;x<=N;x+=x&-x)b[x]+=v;}
int aska(int x){int res=0;for(;x;x-=x&-x)res+=a[x];return res;}
ll askb(int x){ll res=0;for(;x;x-=x&-x)res+=b[x];return res;}
int main()
{
    int n=read();
    ll ans=0,s=0;
    for(int i=0;i<n;++i)
    {
        int x=read();
        ans+=s+x*1LL*i-askb(x);
        for(int j=x;j<=N;j+=x)
        {
            ans-=j*1LL*(aska(min(j+x-1,N))-aska(j-1));
            addb(j,x);
        }
        adda(x);
        s+=x;
        write(ans,' ');
    }
}