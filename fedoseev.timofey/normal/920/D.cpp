#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const int N = 5007;

int dp[N];
int tmp[N];
int p[N];
bool used[N];

int main() {
    int n, k, v;
    cin >> n >> k >> v;
    vector <int> a(n);
    ll sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
    }
    if (sm < v) {
        cout << "NO" << endl;
        return 0;
    }
    dp[0] = 1;
    p[0] = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            tmp[j] = 0;
        }
        for (int j = 0; j < k; ++j) {
            int cur = (j + a[i]) % k;
            if (dp[j] == 1 && dp[cur] == 0) {
                tmp[cur] = 1;
                p[cur] = i;
            }
        }
        for (int j = 0; j < k; ++j) {
            if (tmp[j]) dp[j] = 1;
        }
    }
    if (dp[v % k] == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int cur = v % k;
    vector <int> s;
    while (p[cur] != -1) {
        s.push_back(p[cur]);
        int x = a[p[cur]] % k;
        cur = (cur - x + k) % k;
    }
    reverse(s.begin(), s.end());
    int x; ll sx;
    if (s.size() != 0) {
        x = s[0];
        used[x] = 1;
        sx = a[x];
        for (int i = 1; i < s.size(); ++i) {
            if (a[s[i]] != 0) cout << (a[s[i]] + k - 1) / k << " " << s[i] + 1 << " " << x + 1 << endl;
            used[s[i]] = 1;
            sx += a[s[i]];
        }
    }
    else {
        sx = 0;
        x = n - 1;
    }
    int y = -1;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            if (y == -1) {
                y = i;
            }
            else {
                if (a[i] != 0) cout << (a[i] + k - 1) / k << " " << i + 1 << " " << y + 1 << endl;
            }
        }
    }
    if (y == -1) y = n - 1;
    if (sx > v) {
        cout << (sx - v) / k << " " << x + 1 << " " << y + 1 << endl;
    }
    else if (sx < v) {
        cout << (v - sx) / k << " " << y + 1 << " " << x + 1 << endl;
    }
}