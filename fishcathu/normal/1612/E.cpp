#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=21,M=2E5+1;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
bool cmax(auto &l,auto r){return l<r?l=r,1:0;}
bool cmin(auto &l,auto r){return l>r?l=r,1:0;}
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
pii a[N][M];
int main()
{
    for(int n=read();n--;)
    {
        int x=read(),y=read();
        for(int i=1;i<N;++i)a[i][x][0]+=min(y,i);
    }
    int ans;
    ll mx=0;
    for(int i=1;i<N;++i)
    {
        for(int j=1;j<M;++j)a[i][j][1]=j;
        nth_element(a[i]+1,a[i]+i,a[i]+M,greater<pii>());
        int s=0;
        for(int j=1;j<=i;++j)s+=a[i][j][0];
        if(cmax(mx,s*232792560LL/i))ans=i;
    }
    write(ans,'\n');
    for(int i=1;i<=ans;++i)write(a[ans][i][1],' ');
}