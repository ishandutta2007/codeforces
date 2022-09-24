#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
inline pl operator-(pl x,pl y)
{
    return pl(x.fi-y.fi,x.se-y.se);
}
inline ll ccw(pl x,pl y)
{
    return x.fi*y.se-x.se*y.fi;
}
inline ll ccw(pl x,pl o,pl y)
{
    return ccw(x-o,y-o);
}
inline ll sq(pl x)
{
    return x.fi*x.fi+x.se*x.se;
}
inline ld dist(pl x,pl y)
{
    return sqrt(sq(x-y));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<pl>v(n);
    for(pl&t:v)
        cin>>t.fi>>t.se;
    pl st=v[k-1];
    vector<pl>line;
    pl point(INF,INF);
    if(n==3)
    {
        line.eb(v[0]);
        line.eb(v[1]);
        point=v[2];
    }
    else
    {
        pl lp1,lp2;
        if(ccw(v[0],v[2],v[1])==0||ccw(v[0],v[3],v[1])==0)
            lp1=v[0],lp2=v[1];
        else
            lp1=v[2],lp2=v[3];
        for(auto&t:v)
        {
            if(ccw(lp1,t,lp2)==0)
                line.eb(t);
            else
                point=t;
        }
    }
    if(point.fi==INF)
        point=line.back(),line.pop_back();
    sort(all(line));
    ld ans=INF;
    for(int i=0;i<2;i++)
    {
        pl p1=line[0];
        pl p2=line.back();
        pl p3=point;
        { //123
            ld cur=dist(st,p1)+dist(p1,p2)+dist(p2,p3);
            ans=min(ans,cur);
        }
        { //312
            for(int i=1;i<n-1;i++)
            {
                pl p4=line[i-1];
                pl p5=line[i];
                ld cur1=dist(st,p4)+dist(p4,p1)+dist(p1,p3);
                ld cur2=dist(st,p1)+dist(p1,p4)+dist(p4,p3);
                ld cur3=dist(p3,p2)+dist(p2,p5);
                ld cur4=dist(p3,p5)+dist(p5,p2);
                ld cur=min(cur1,cur2)+min(cur3,cur4);
                ans=min(ans,cur);
            }
        }
        { //132
            ld cur=dist(st,p3)+dist(p3,p1)+dist(p1,p2);
            ans=min(ans,cur);
        }
        reverse(all(line));
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}