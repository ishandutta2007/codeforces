#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=5E6+10;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
bool cmin(auto &l,auto r){return l>r?l=r,1:0;}
bool cmax(auto &l,auto r){return l<r?l=r,1:0;}
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
vector<int>pri;
bool b[N];
int a[N];
ll ans[N];
int main()
{
    for(int i=2;i<N;++i)
    {
        if(!b[i])pri.pb(i);
        for(int j:pri)
        {
            int t=i*j;
            if(t>=N)break;
            b[t]=1;
            if(!(i%j))break;
        }
    }
    for(int n=read();n--;)++a[read()];
    for(int x:pri)for(int i=(N-10)/x;i>=1;--i)a[i]+=a[i*x];
    for(int i=N;--i;)
    {
        ans[i]=i*1LL*a[i];
        for(int x:pri)
        {
            int j=i*x;
            if(j>=N)break;
            cmax(ans[i],i*1LL*(a[i]-a[j])+ans[j]);
        }
    }
    write(ans[1],'\n');
}