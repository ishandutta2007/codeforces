#include <bits/stdc++.h>
#define double      long double
#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,mark[100005];
template <class T>
struct Point 
{
    typedef Point P;
    T x, y;
    explicit Point(T x1=0, T y1=0) : x(x1), y(y1) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-* this).cross(b-* this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to xaxis in interval [pi , pi ]
    double angle() const { return atan2(y, x); }
    P unit() const { return * this/dist(); } // makes d i s t ()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated a  radians ccw around the origin
    P rotate(double a) const { return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};
typedef Point<double> P;
P pts[100005];
bool onSegment(const P& s,const P& e,const P& p){
    P ds=p-s,de=p-e;
    return ds.cross(de)==0 && ds.dot(de)<=0;
}
double lineDist(const P& a, const P& b, const P& p){
    return (double)(b-a).cross(p-a);
}
double area(int a,int b,int c){
    return abs(pts[a].x*(pts[b].y-pts[c].y)-pts[a].y*(pts[b].x-pts[c].x)+(pts[b].x*pts[c].y-pts[b].y*pts[c].x));
}
bool isinside(int a,int b,int c,int x){
    return abs(area(a,b,x)+area(a,c,x)+area(b,c,x)-area(a,b,c))<=1e-9;
}
void solve(){
    cin>>n;
    rep(i,0,n) cin>>pts[i].x>>pts[i].y;
    int l=0,r=1;
    rep(i,2,n){
        if(onSegment(pts[l],pts[r],pts[i])){
            r=i;
        }
    }
    int g=-1;
    rep(i,0,n){
        if(i==l || i==r) continue;
        if(abs(lineDist(pts[l],pts[r],pts[i]))<=1e-9) mark[i]=1;
        if(!mark[i]) g=i;
    }
    assert(g>=0);
    rep(i,0,n){
        if(mark[i] || i==l || i==r || i==g) continue;
        if(isinside(l,r,g,i)) g=i;
    }
    cout<<l+1<<" "<<r+1<<" "<<g+1<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}