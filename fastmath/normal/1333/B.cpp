#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 1e5 + 7;
//0 : -1
//1 : 1
bool pref[N][2];
int a[N], b[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1][0] = pref[i][0] || (a[i] < 0);
        pref[i + 1][1] = pref[i][1] || (a[i] > 0);
    }
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            if (!pref[i][1]) {
                cout << "NO" << endl;
                return;
            }   
        }   
        if (a[i] > b[i]) {
            if (!pref[i][0]) {
                cout << "NO" << endl;
                return;
            }   
        }   
    }            
    cout << "YES" << endl;
}   

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
        solve();
    }   
}