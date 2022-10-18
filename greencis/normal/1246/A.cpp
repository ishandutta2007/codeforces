

    #include <bits/stdc++.h>
    #define all(x) (x).begin(), (x).end()
    using namespace std;
    typedef unsigned long long ull;
    typedef long long ll;
    typedef long double ld;
    typedef pair<int, int> pii;
     
     
     
    int main() {
        ios_base::sync_with_stdio(false);
     
        int n, p;
        cin >> n >> p;
        for (int i = 1; i <= 40; ++i) {
            int x = n - p * i;
            if (x <= 0) continue;
            if (__builtin_popcount(x) <= i && x >= i) {
                cout << i << endl;
                return 0;
            }
        }
        cout << -1 << endl;
    }