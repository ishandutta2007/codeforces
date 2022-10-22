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
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }   

        int prv = -1;
        int who = 0;
        while (1) {
            int mx = -1;
            for (int i = 0; i < n; ++i) {
                if (i == prv)
                    continue;
                if (mx == -1 || a[i] > a[mx])
                    mx = i;
            }
            if (mx == -1 || a[mx] == 0) {
                if (who == 0) {
                    cout << "HL" << endl;
                }   
                else {
                    cout << "T" << endl;
                }   
                break;
            }   
            who ^= 1;
            prv = mx;
            a[mx]--;
        }   

    }   

}