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
#define debug(x) std::cout << #x << ": " << x << '\n';
#define double long double
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
        cout.precision(20);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n, L;
        cin >> n >> L;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        double lx = 0, rx = L;
        int l_ptr = 0, r_ptr = n - 1;
        int lv = 1, rv = 1;

        double ans = 0;

        while (1) {

            //cout << lx << ' ' << rx << ' ' << lv << ' ' << rv << endl;

            if (l_ptr > r_ptr) {
                ans += (rx - lx) / (lv + rv);
                cout << ans << endl;
                break;
            }   

            assert(l_ptr < n);
            assert(r_ptr >= 0);

            double t1 = (a[l_ptr] - lx) / lv;
            double t2 = (rx - a[r_ptr]) / rv;
            if (t1 < t2) {
                ans += t1;
                lx = a[l_ptr];
                rx -= rv * t1;
                lv++;
                l_ptr++;
            }   
            else {
                ans += t2;
                rx = a[r_ptr];
                lx += lv * t2;
                rv++;
                r_ptr--;
            }   
        }   
    }   

}