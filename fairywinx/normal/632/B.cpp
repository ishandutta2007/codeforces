#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define mp make_pair

using namespace std;

void setup() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif

    //srand(time(NULL));
}

const int N = 1e5 + 228;
const int inf = 2e9;
const int mod = 1e9 + 9;

signed main() {
    setup();

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) 
        cin >> a[i];

    vector<int> pref(n + 1);
    int z = 0;
    string s;
    cin >> s;
    for(int i = 0; i < n; ++i) {
        if (s[i] == 'B') 
            z += a[i];
    }
    vector<int> su(n + 1);
    su[0] = z;
    pref[0] = z;
    for(int i = 0; i < n; ++i) {
        if (s[i] == 'A')
            pref[i + 1] += a[i];
        else
            pref[i + 1] -= a[i];
        pref[i + 1] += pref[i];

        if (s[n - 1 - i] == 'A')
            su[i + 1] += a[n - 1 - i];
        else
            su[i + 1] -= a[n - 1 - i];
        su[i + 1] += su[i];
    }
    int ans = -1e18;
    for(int i = 0; i <= n; ++i) {
        ans = max(ans, max(su[i], pref[i]));
    }
    cout << ans;
}