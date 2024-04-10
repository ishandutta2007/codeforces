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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int l = 0, r = n - 1;
        int A = 0, B = 0;
        int prv = 0;
        int h = 0;
        while (1) {
            int cur = 0;
            while (l <= r && cur <= prv) {
                cur += a[l];
                ++l;
            }   
            A += cur;
            h += cur > 0;
            if (cur <= prv)
                break;
            prv = cur;

            cur = 0;
            while (r >= l && cur <= prv) {
                cur += a[r];
                --r;                    
            }   
            B += cur;
            h += cur > 0;
            if (cur <= prv)
                break;
            prv = cur;
        }   

        cout << h << ' ' << A << ' ' << B << endl;
    }
}