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
void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector <vector <int> > cnt(k, vector <int> (2));
    for (int i = 0; i < n; ++i) {
        if (s[i] != '?') {
            cnt[i % k][s[i]-'0']++;
        }
    }   
    
    for (int i = 0; i < k; ++i) {
        if (cnt[i][0] && cnt[i][1]) {
            cout << "NO" << endl;
            return;
        }   
    }   

    vector <int> a(2);
    for (int i = 0; i < k; ++i) {
        if (cnt[i][0])
            ++a[0];
        if (cnt[i][1])
            ++a[1];
    }   
    if (max(a[0], a[1]) > k/2) {
        cout << "NO" << endl;
    }   
    else {
        cout << "YES" << endl;
    }   
}
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
        solve();
    }   
}