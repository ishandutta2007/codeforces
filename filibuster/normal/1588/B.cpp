//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 22;


/*
*/

map<pii, li> mem;
map<int, li> mlf;

//vector<int> A = {2, 1, 5, 4, 3};
//vector<int> A = {1, 3, 2, 5, 4};
vector<int> A = {1, 4, 3, 2};
//vector<int> A = {1, 5, 4, 3, 2};

//li query(int l, int r) {
//    if(mem.count({l, r}))
//        return mem[{l, r}];
//    cout << "? " << l << ' ' << r << endl;
//    li res = 0;
////    cin >> res;
//    for(int i = l - 1; i < r; i++) {
//        for(int j = i + 1; j < r; j++) {
//            res += (A[i] > A[j]);
//        }
//    }
//    cout << res << endl;
//    if(l == 1)
//        mlf[r] = res;
//    return mem[{l, r}] = res;
//}
//
li query(int l, int r) {
    if(mem.count({l, r}))
        return mem[{l, r}];
    cout << "? " << l << ' ' << r << endl;
    li res = 0;
    cin >> res;

    if(l == 1)
        mlf[r] = res;
    return mem[{l, r}] = res;
}

void solve() {
    int n;
    cin >> n;

    mlf.erase(mlf.begin(), mlf.end());
    mem.erase(mem.begin(), mem.end());

    li S = query(1, n);

    int l = 0, r = n;
    int p = -1;
    while(r - l > 1) {
        int m = (l + r) / 2;

        li res = query(1, m);
//        cout <<l << ' ' << m << ' ' << r << ' ' << res << endl;

        if(0 < res && res < S) {
            p = m;
            break;
        }


        if(res > 0)
            r = m;
        else
            l = m;
    }

    if(p == -1) {
//        cout << "! " << n - 2 << ' ' << n - 1 << ' ' << n << endl;
        cout << "! " << r - 2 << ' ' << r - 1 << ' ' << r << endl;
        return;
    }

//    cout << " p = " << p << endl;

    {
//        cout << "sfga" << endl;
        li res = query(p, n);
        li D = 1 + res * 8;
        li sqD = li(sqrt(D) + 0.1);
//        cout << res << ' ' << D << ' ' << sqD << endl;
        if(sqD * sqD == D) {//cout << "sfga" << endl;
            int y = (1 + sqD) / 2;
            int k = p + y - 1;
//            cout << "case k y = " << y << " k = " << k << endl;
            if(query(p, k) == res) {//cout << "sfga" << endl;
                l = 0;
                r = p + 1;
                for(auto pr : mlf) {
                    if(pr.f < p && S - pr.s < (k - pr.f) * 1ll * (k - pr.f - 1) / 2) {
                        l = max(l, pr.f);
                    }
//                    if(pr.s == 0) {
//                        l = max(l, pr.f);
//                    }
//                    if(pr.f > p && pr.s < (pr.f - i) * 1ll * (pr.f - i - 1) / 2) {
//                        r = min(r, pr.f);
//                    }
                }

//                cout << l << ' ' << r << endl;

                while(r - l > 1) {
                    int m = (l + r) / 2;
//
//                    cout << "k bin search " << l << ' ' << m << ' ' << r << endl;

                    if(query(m, n) < (k - m) * 1ll * (k - m + 1) / 2)
                        l = m;
                    else
                        r = m;
                }

                int j = r;
                D = 1 + query(1, j) * 8;
                li sqD = li(sqrt(D) + 0.1);
                int x = (1 + sqD) / 2;
                int i = j - x;
//                cout << "case k" << endl;
                cout << "! " << i << ' ' << j << ' ' << k << endl;
                return;
            }
        }
    }

    {
        li res = query(1, p);
        li D = 1 + res * 8;
        li sqD = li(sqrt(D) + 0.1);
        if(sqD * sqD == D) {
            int x = (1 + sqD) / 2;
            int i = p - x + 1;
//            cout << "case i " << "x = " << x << endl;
            if(query(i, p) == res) {

//                cout << "case i" << endl;
                l = p;
                r = n + 1;
                for(auto pr : mlf) {
                    if(pr.f > p && pr.s < (pr.f - i) * 1ll * (pr.f - i - 1) / 2) {
                        r = min(r, pr.f);
                    }
                }

//                cout << l << ' ' << r << endl;

                while(r - l > 1) {
                    int m = (l + r) / 2;

                    if(query(1, m) < (m - i) * 1ll * (m - i - 1) / 2)
                        r = m;
                    else
                        l = m;
                }

                int j = l;
                D = 1 + query(j, n) * 8;//(S - query(1, j)) * 8;
                li sqD = li(sqrt(D) + 0.1);
                int y = (1 + sqD) / 2;
                int k = j + y - 1;
//                cout << "case i" << endl;
                cout << "! " << i << ' ' << j << ' ' << k << endl;
                return;
            }
        }
    }


}

signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}