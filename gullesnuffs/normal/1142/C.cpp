#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<pair<ll, ll>> points;
    rep(i,0,n) {
        cin >> x[i] >> y[i];
        y[i] -= x[i]*x[i];
        points.emplace_back(x[i], y[i]);
    }
    sort(all(points));
    vector<pair<ll, ll>> convexHull;
    for (auto it : points) {
        while (sz(convexHull) && convexHull.back().first == it.first)
            convexHull.pop_back();
        while (sz(convexHull) >= 2) {
            auto p1 = convexHull[sz(convexHull)-2];
            auto p2 = convexHull[sz(convexHull)-1];
            auto p3 = it;
            auto x1 = p1.first;
            auto y1 = p1.second;
            auto x2 = p2.first;
            auto y2 = p2.second;
            auto x3 = p3.first;
            auto y3 = p3.second;
            auto dx2 = x2-x1;
            auto dy2 = y2-y1;
            auto dx3 = x3-x1;
            auto dy3 = y3-y1;
            if (dx2*dy3-dx3*dy2 >= 0) {
                convexHull.pop_back();
            }
            else
                break;
        }
        convexHull.emplace_back(it);
    }
    cout << sz(convexHull)-1 << endl;
}