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
        int n, k;
        cin >> n >> k;                        

        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int up = 0;
        for (int i = 0; i + 1 < n; ++i)
            if (a[i] < a[i + 1])
                up++;

        if (up == 0) {
            cout << 1 << endl;
        }   
        else if (k == 1) {
            cout << -1 << endl;
        }   
        else {
            k--;
            cout << (up + k - 1) / k << endl;
        }   

    }   

}