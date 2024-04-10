#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int INF = 2e9+7;

const int N = 5e5+7;

vector <int> c;
vector <ii> dx[N], dy[N];
int distx[N], disty[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int S, m;
    cin >> S >> m;

    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;

    vector <ii> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].x >> a[i].y;
        c.app(a[i].x);
        c.app(a[i].y);
    }   

    sort(all(c));

    for (int i = 0; i < m; ++i) {   
        a[i].x = lower_bound(all(c), a[i].x) - c.begin();
        a[i].y = lower_bound(all(c), a[i].y) - c.begin();

        dx[a[i].x].app(a[i]);
        dy[a[i].y].app(a[i]);
    }
    
    /*
    for (int i = 0; i < N; ++i)
        distx[i] = disty[i] = INF;
    */

    int ans = INF;

    ans = min(ans, abs(sx - fx) + abs(sy - fy));

    set <ii> msx, msy;
    for (int i = 0; i < c.size(); ++i) {
        distx[i] = abs(sx - c[i]);
        msx.insert(mp(distx[i], i));
        disty[i] = abs(sy - c[i]);
        msy.insert(mp(disty[i], i));
    }   

    auto relax_x = [&] (int x, int d) {
        if (d < distx[x]) {
            msx.erase(mp(distx[x], x));
            distx[x] = d;
            msx.insert(mp(distx[x], x));
        }   
    };

    auto relax_y = [&] (int y, int d) {
        if (d < disty[y]) {
            msy.erase(mp(disty[y], y));
            disty[y] = d;
            msy.insert(mp(disty[y], y));
        }   
    };

    while (msx.size() || msy.size()) {
        if (msy.empty() || (msx.size() && msy.size() && *msx.begin() < *msy.begin())) {

            assert(msx.size());

            int x = msx.begin()->s;
            msx.erase(msx.begin());

            int D = distx[x];

            //cout << "x " << x << ' ' << D << endl;
            
            if (x) {
                relax_x(x - 1, D + abs(c[x] - c[x - 1]));
            }   
            if (x + 1 < c.size()) {
                relax_x(x + 1, D + abs(c[x] - c[x + 1]));
            }

            for (auto p : dx[x]) {
                //cout << "point " << p.x << ' ' << p.y << endl;

                ans = min(ans, D + abs(c[p.x] - fx) + abs(c[p.y] - fy));                

                if (p.x) {
                    relax_x(p.x - 1, D + abs(c[p.x - 1] - c[p.x]));
                }   
                if (p.x + 1 < c.size()) {
                    relax_x(p.x + 1, D + abs(c[p.x + 1] - c[p.x]));
                }   

                if (p.y) {
                    relax_y(p.y - 1, D + abs(c[p.y - 1] - c[p.y]));
                }   
                if (p.y + 1 < c.size()) {
                    relax_y(p.y + 1, D + abs(c[p.y + 1] - c[p.y]));
                }   
            }   
        }   
        else {
            assert(msy.size());

            int y = msy.begin()->s;
            msy.erase(msy.begin());

            int D = disty[y];

            //cout << "y " << y << ' ' << D << endl;

            if (y) {
                relax_y(y - 1, D + abs(c[y] - c[y - 1]));
            }   
            if (y + 1 < c.size()) {
                relax_y(y + 1, D + abs(c[y] - c[y + 1]));
            }

            for (auto p : dy[y]) {                
                ans = min(ans, D + abs(c[p.x] - fx) + abs(c[p.y] - fy));                

                //cout << "point " << p.x << ' ' << p.y << endl;

                if (p.x) {
                    relax_x(p.x - 1, D + abs(c[p.x - 1] - c[p.x]));
                }   
                if (p.x + 1 < c.size()) {
                    relax_x(p.x + 1, D + abs(c[p.x + 1] - c[p.x]));
                }   

                if (p.y) {
                    relax_y(p.y - 1, D + abs(c[p.y - 1] - c[p.y]));
                }   
                if (p.y + 1 < c.size()) {
                    relax_y(p.y + 1, D + abs(c[p.y + 1] - c[p.y]));
                }   
            }   
        }   
    }   
    cout << ans << endl;
}