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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    int n, k;
    cin >> n >> k;
    vector <int> ans;
    for (int i = 0; i < k + 1; ++i) {
        cout << "? ";
        for (int j = 0; j < k + 1; ++j) {
            if (j != i) {
                cout << j + 1 << ' ';
            }   
        }   
        cout << endl;
        fflush(stdout);
        int pos, val;
        cin >> pos >> val;
        ans.app(val);
    }   
    const int INF = 1e9 + 7;
    int mx = 0;
    for (int e : ans)
        mx = max(mx, e);
    int cnt = 0;
    for (int e : ans)
        cnt += e == mx;
    cout << "! " << cnt << endl;
    fflush(stdout);
}