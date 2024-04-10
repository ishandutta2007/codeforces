#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
pair<pi,vector<pi> >solve(vector<int>v,int d,int k)
{
    int n=v.size();
    vector<int>p(n*2+5,0);
    for(int&t:v)
        p[t]++;
    for(int i=1;i<n*2+5;i++)
        p[i]+=p[i-1];
    int x=-1,y=-1;
    for(int i=1;i<=n;i++)
    {
        int okn=p[i+d]-p[i-1];
        if(okn-(n-okn)>=k)
        {
            x=i,y=i+d;
            break;
        }
    }
    if(x==-1)
        return pair<pi,vector<pi> >(pi(inf,inf),vector<pi>());
    vector<int>cutv;
    cutv.eb(0);
    vector<int>p2(1,0);
    for(int&t:v)
        p2.eb(p2.back()+(x<=t&&t<=y?1:-1));
    int D=1;
    for(int i=0;i<=n;i++)
        if(D==p2[i])
            cutv.eb(i),D++;
    cutv.resize(k);
    cutv.eb(n);
    vector<pi>intv;
    for(int i=0;i<k;i++)
        intv.eb(cutv[i]+1,cutv[i+1]);
    return pair<pi,vector<pi> >(pi(x,y),intv);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        int s=0,e=n;
        while(s<e)
        {
            int m=s+(e-s)/2;
            if(solve(v,m,k).fi.fi!=inf)
                e=m;
            else
                s=m+1;
        }
        auto asdf=solve(v,s,k);
        cout<<asdf.fi.fi<<' '<<asdf.fi.se<<'\n';
        for(pi&t:asdf.se)
            cout<<t.fi<<' '<<t.se<<'\n';
    }
    return 0;
}