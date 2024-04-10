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

struct Rect {
    ll x, y, a;

    bool operator<(const Rect& other) const {
        return x < other.x;
    }
};

ll dp[1000005];
vector<Rect> rects;

void rec(int L, int R, int LO, int HI) {
    if (L >= R) return;
    //cerr << L << " " << R << " " << LO << " " << HI << endl;
    int mid = (9*L + R)/10;
    pair<ll, int> best(0, LO);
    rep(k, LO, min(HI, L)) {
        ll val = dp[k] + (rects[mid].x-rects[k].x)*rects[mid].y - rects[mid].a;
        best = max(best, make_pair(val, k));
    }
    if (best.first > dp[mid]) {
        //cerr << mid << ": " << best.first << endl;
        dp[mid] = best.first;
    }
    rec(L, mid, LO, best.second+1);
    int checked = L;
    while (true) {
        auto prevBest = best;
        rep(k, max(LO, L), min(HI, mid)) {
            ll val = dp[k] + (rects[mid].x-rects[k].x)*rects[mid].y - rects[mid].a;
            best = max(best, make_pair(val, k));
        }
        if (best <= prevBest) {
            break;
        }
        //cerr << mid << " : " << best.first << endl;
        dp[mid] = max(dp[mid], best.first);
        rec(L, mid, checked, best.second+1);
        checked = best.second+1;
    }
    rec(mid+1, R, best.second, HI);
}

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    rects.resize(n);
    rep(i,0,n) {
        cin >> rects[i].x >> rects[i].y >> rects[i].a;
    }
    ++n;
    rects.push_back(Rect());
    rects.back().x = 0;
    rects.back().y = 0;
    rects.back().a = 0;
    sort(all(rects));
    rec(1, n, 0, n+1);
    ll ans = 0;
    rep(i,0,n)
        ans = max(ans, dp[i]);
    cout << ans << endl;
}