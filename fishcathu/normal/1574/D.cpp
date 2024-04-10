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
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
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

int main()
{
    int n=read(),mx=0;
    vector<vector<int>>a(n);
    vector<int>ans(n);
    for(int i=0;i<n;++i)
    {
        a[i].resize(ans[i]=read());
        for(int &x:a[i])x=read();
    }
    set<vector<int>>q;
    for(int m=read();m--;)
    {
        vector<int>x(n);
        for(int &y:x)y=read();
        q.insert(x);
    }
    if(q.count(ans))
    {
        for(vector<int>x:q)
        {
            int s=0;
            for(int i=0;i<n;++i)s+=a[i][x[i]-1];
            for(int i=0;i<n;++i)
            {
                if(x[i]==1)continue;
                --x[i];
                if(!q.count(x))
                {
                    int t=s-a[i][x[i]]+a[i][x[i]-1];
                    if(t>mx)ans=x,mx=t;
                }
                ++x[i];
            }
        }
    }
    for(int x:ans)write(x,' ');
}