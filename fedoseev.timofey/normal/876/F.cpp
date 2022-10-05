# include <iostream>
# include <vector>
# include <cstdio>
# include <stack>
# include <set>

using namespace std;

const int Maxn = 200005;
int a[Maxn];

set <pair <pair <int, int>, pair <int, int>>> w;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> largel(n, -1);
    vector <int> larger(n, n);
    vector <int> bitsl(n, -1);
    vector <int> bitsr(n, n);
    vector <int> bits(31, -1);
    stack <pair<int, int>> s;
    s.push({a[0], 0});
    for (int i = 1; i < n; ++i) {
        while (!s.empty() && s.top().first < a[i])
            s.pop();
        if (!s.empty())
            largel[i] = s.top().second;
        s.push({a[i], i});
    }
    while (!s.empty()) s.pop();
    s.push({a[n - 1], n - 1});
    for (int i = n - 2; i >= 0; --i) {
        while (!s.empty() && s.top().first <= a[i])
            s.pop();
        if (!s.empty())
            larger[i] = s.top().second;
        s.push({a[i], i});
    }
    for (int k = 0; k < 30; ++k) if ((1 << k) & a[0]) bits[k] = 0;
    for (int i = 1; i < n; ++i) {
        for (int k = 0; k < 30; ++k)
            if ((1 << k) & a[i])
                bits[k] = i;
            else
                bitsl[i] = max(bitsl[i], bits[k]);
    }
    for (int k = 0; k < 30; ++k)
        if ((1 << k) & a[n - 1])
            bits[k] = n - 1;
        else
            bits[k] = n;
    for (int i = n - 2; i >= 0; --i) {
        for (int k = 0; k < 30; ++k)
            if ((1 << k) & a[i])
                bits[k] = i;
            else
                bitsr[i] = min(bitsr[i], bits[k]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
            int left1 = largel[i] + 1;
            int right1 = larger[i] - 1;
            int left2 = bitsl[i];
            int right2 = bitsr[i];
            if (left2 >= left1)
                ans += (long long)(left2 - left1 + 1) * (right1 - i + 1);
            if (right2 <= right1)
                ans += (long long)(right1 - right2 + 1) * (i - left1 + 1);
            if (left2 >= left1 && right2 <= right1)
                ans -= (long long)(left2 - left1 + 1) * (right1 - right2 + 1);
    }
    cout << ans << endl;
}