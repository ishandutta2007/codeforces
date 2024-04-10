#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E5+10;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
void cmin(auto &l,auto r){l=l<r?l:r;}
void cmax(auto &l,auto r){l=l>r?l:r;}
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
    vector<vector<int>>a(n,vector<int>(m+1));
    vector<vector<int>>b(n,vector<int>(m));
    vector<vector<int>>c(n,vector<int>(m));
    vector<vector<int>>d(n,vector<int>(m));
    vector<vector<int>>e(n,vector<int>(m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)a[i][j]=read();
        a[i][m]=i;
    }
    sort(a.begin(),a.end(),[](vector<int>l,vector<int>r){return l[0]>r[0];});
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            b[i][j]=c[i][j]=d[i][j]=e[i][j]=a[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=1;j<m;++j)
        {
            cmin(b[i][j],b[i][j-1]);
            cmax(d[i][j],d[i][j-1]);
        }
        for(int j=m-2;j>=0;--j)
        {
            cmax(c[i][j],c[i][j+1]);
            cmin(e[i][j],e[i][j+1]);
        }
    }
    for(int j=0;j<m;++j)
    {
        for(int i=1;i<n;++i)
        {
            cmin(b[i][j],b[i-1][j]);
            cmax(c[i][j],c[i-1][j]);
        }
        for(int i=n-2;i>=0;--i)
        {
            cmax(d[i][j],d[i+1][j]);
            cmin(e[i][j],e[i+1][j]);
        }
    }
    for(int i=0;i<n-1;++i)
    {
        for(int j=0;j<m-1;++j)
        {
            if(b[i][j]<=d[i+1][j]||c[i][j+1]>=e[i+1][j+1])continue;
            string ans;
            ans.resize(n);
            for(int k=0;k<n;++k)ans[a[k][m]]=k>i?'B':'R';
            cout<<"YES\n"<<ans<<' '<<j+1<<endl;
            return;
        }
    }
    puts("NO");
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}