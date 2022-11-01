#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define forv(a,b) for(auto &a:b)
#define all(a) a.begin(),a.end()
#define pb push_back
const int N=100010;
int na,nb,nc,res;
vector<int> a,b,c;
void Calvv(vector<int> &a,vector<int> &b,vector<int> &c)
{
    forv(x,a)
    {
        int yy=lower_bound(all(b),x)-b.begin();
        int zz=lower_bound(all(c),x)-c.begin();
        FOR(i,yy-1,yy+1) FOR(j,zz-1,zz+1)
        {
            if(i<0||i>=b.size()||j<0||j>=c.size()) continue;
            res=min(res,(x-b[i])*(x-b[i])+(x-c[j])*(x-c[j])+(b[i]-c[j])*(b[i]-c[j]));
        }
    }
}
main()
{
    //freopen("baiB.inp","r",stdin);
    int T=in;
    FOR(cs,1,T)
    {
        na=in,nb=in,nc=in;
        a.clear(),b.clear(),c.clear();
        FOR(i,1,na)
        {
            int x=in;
            a.pb(x);
        }
        FOR(i,1,nb)
        {
            int x=in;
            b.pb(x);
        }
        FOR(i,1,nc)
        {
            int x=in;
            c.pb(x);
        }
        sort(all(a));sort(all(b));sort(all(c));
        int oo=LLONG_MAX;
        res=oo;
        Calvv(a,b,c);Calvv(b,a,c);Calvv(c,a,b);
        cout<<res<<"\n";
    }
}