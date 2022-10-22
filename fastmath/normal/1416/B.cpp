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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n + 1);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }   

        if (sum % n) {
            cout << -1 << endl;
            continue;
        }   

        int s = sum/n;

        cout << 3 * (n - 1) << endl;
        for (int i = 2; i <= n; ++i) {
            int add = 0;
            if (a[i] % i) {
                add = i - (a[i] % i);
            }   

            assert(a[1] >= add);
            cout << 1 << ' ' << i << ' ' << add << endl;
            a[1] -= add;
            a[i] += add;
            cout << i << ' ' << 1 << ' ' << a[i] / i << endl;
            a[1] += a[i];
            a[i] = 0;
        }   
        for (int i = 2; i <= n; ++i) {
            cout << 1 << ' ' << i << ' ' << s << endl;
        }   
    }   
}