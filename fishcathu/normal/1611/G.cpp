#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E5+10;
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

void solve()
{
    int n=read(),m=read();
    vector<vector<int>>a(n,vector<int>(m));
    vector<vector<int>>f(n,vector<int>(m));
    vector<int>ans(2);
    for(vector<int>&y:a)for(int &x:y)scanf("%1d",&x);
    function<int(int,int)>g=[&](int i,int j){return i<0||i>=n||j<0?0:f[i][j];};
    for(int j=0;j<m;++j)for(int i=0;i<n;++i)
    {
        f[i][j]=max({g(i-1,j-1),g(i+1,j-1),g(i,j-2)+a[i][j]});
        cmax(ans[i+j&1],f[i][j]);
    }
    write(ans[0]+ans[1],'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}