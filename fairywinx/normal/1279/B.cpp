#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

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

    srand(time(NULL));
}

signed main() {
    setup();

    int t;
    cin >> t;
    for(int u = 0; u < t; ++u) {
        int n, s;
        cin >> n >> s;
        int mx = 0;
        int ans = 0;
        int anss = 0;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (mx < a) {
                mx = a;
                ans = i + 1;
            }
            sum += a;
            if (sum > s) {
                if (anss == 0) anss = ans;
                if (sum - mx <= s) 
                    anss = ans;
            }
        }
        cout << anss << '\n';
    }
}