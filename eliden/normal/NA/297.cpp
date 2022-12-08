#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

double dist(double x1, double y1, double x2, double y2) {
    double dx = x2-x1;
    double dy = y2-y1;
    return sqrt(dx*dx+dy*dy);
}
vector<tuple<double,double,double>> toline(ll x, ll y, ll a, ll b, ll c) {
    vector<tuple<double,double,double>> res;
    if(a*x+b*y==c) res.emplace_back(0,x,y);
    else {
        double rem1  = -(c+a*x);
        if(b!=0) {
            double yy = rem1/b;
            res.emplace_back(abs(y-yy),x,yy);
        }
        double rem2 = -(c+b*y);
        if(a!=0) {
            double xx = rem2/a;
            res.emplace_back(abs(x-xx),xx,y);
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b,c,x1,y1,x2,y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    double best = abs(x1-x2)+abs(y1-y2);
    auto res1 = toline(x1,y1,a,b,c);
    auto res2 = toline(x2,y2,a,b,c);
    for(auto p1:res1) {
        for(auto p2:res2) {
            double d1,d2,xx1,yy1,xx2,yy2;
            tie(d1,xx1,yy1) = p1;
            tie(d2,xx2,yy2) = p2;
            best = min(best,d1+d2+dist(xx1,yy1,xx2,yy2));
        }
    }
    cout<<setprecision(10);
    cout<<best<<endl;
}