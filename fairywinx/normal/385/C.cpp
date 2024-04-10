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

const int N = 1e7 + 228;

int a[N];
int pref[N];

signed main() {
    setup();
    fill_n(a, N, 0);
    fill_n(pref, N, 0);

    int n;
    int mx = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        a[b]++;
        mx = max(mx, b);
    }

    vector<bool> pr(N, 1);
    for(long long i = 2; i < N; i += 1) {
        pref[i] = pref[i - 1];
        if (pr[i] == 1) {
            for (long long j = i * i; j < N + 1; j += i) pr[j] = 0;
            for(int j = i; j < N; j += i) {
                pref[i] += a[j];
            }
        }
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int b, c;
        cin >> b >> c;
        c = min(mx, c);
        if (b > mx) {
            cout << 0 << '\n';
            continue;
        }
        cout << pref[c] - pref[b - 1] << '\n';
    }
}