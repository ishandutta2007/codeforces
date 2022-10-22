#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    map <ii, vector <double> > d;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        double r = sqrt(x * x + y * y);
        if (x || y) {
            int dv = __gcd(abs(x), abs(y));
            x /= dv;
            y /= dv;
            d[mp(x,y)].app(r);
        }   
    }   

    #ifdef HOME
    cout << "d:" << endl;
    for (auto e : d) {
        cout << e.f.f << ' ' << e.f.s << " : ";
        for (auto r : e.s)
            cout << r << ' ';
        cout << endl;
    }       
    #endif

    vector <vector <double> > a;
    for (auto e : d) {
        a.app(e.s);
        sort(all(a.back()));
    }

    vector <double> cost = {0};
    for (auto e : a) {
        for (int i = 0; i < e.size(); ++i) {
            int r = e.size() - i - 1;
            cost.app(e[i] * (k - 1 - 2 * r));
        }   
    }   

    double ans = 0;
    sort(all(cost));
    reverse(all(cost));
    for (int i = 0; i < k; ++i) 
        ans += cost[i];

    auto get = [](vector <double> a) {
        sort(all(a));
        double sum = 0, ans = 0;
        for (int i = 0; i < a.size(); ++i) {
            ans += i * a[i] - sum;            
            sum += a[i];
        }   
        return ans;
    };           

    int m = (k + 1) / 2;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].size() >= m && n - a[i].size() <= k - m) {
            double sum = 0;
            int cnt = 0;
            vector <double> q;
            for (int j = (int)a[i].size() - m; j < a[i].size(); ++j) {
                sum += a[i][j];
                q.app(a[i][j]);
                ++cnt;
            }   
            int ost = k - m - (n - a[i].size());
            for (int j = 0; j < ost; ++j) {
                sum += a[i][j];
                q.app(a[i][j]);
                ++cnt;
            }
            double nn = get(q);
            for (int j = 0; j < a.size(); ++j) {
                if (j == i)
                    continue;

                for (auto e : a[j]) {
                    nn += sum;
                    nn += cnt * e;
                }   
                for (auto e : a[j]) {
                    sum += e;
                    ++cnt;
                }   
                nn += get(a[j]);
            }
            nn += sum;
            
            
            ans = max(ans, nn);
            #ifdef HOME
            cout << "nn : " << nn << endl;
            #endif
        }   
    }   

    cout.precision(10);
    cout << fixed << ans << endl;
}