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
int u[N],v[N];
void solve()
{
    map<int,vector<array<int,3>>>q;
    int n=read();
    for(int i=1;i<=n;++i)
    {
        u[i]=read();
        v[i]=read();
        int w=read();
        q[u[i]+v[i]-w].pb({u[i]-v[i]-min(w,u[i]*2-w),u[i]-v[i]+min(w,v[i]*2-w),i});
    }
    int ans=0;
    for(auto &[p,a]:q)
    {
        sort(a.begin(),a.end());
        a.pb({inf+1});
        for(int i=0,j=0,mn=inf;i<a.size();++i)
        {
            if(a[i][0]>mn)
            {
                while(j<i)
                {
                    u[a[j][2]]-=p+mn>>1;
                    v[a[j][2]]-=p-mn>>1;
                    ++j;
                }
                ++ans;
                mn=a[i][1];
            }
            else cmin(mn,a[i][1]);
        }
    }
    write(ans,'\n');
    for(int i=1;i<=n;++i)printf("%d %d\n",u[i],v[i]);
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}