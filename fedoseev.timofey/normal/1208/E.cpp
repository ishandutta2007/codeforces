#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 7;

multiset <int> w[N];

ll sum = 0;

void add(int i, int x) {
    if (!w[i].empty()) sum -= (*w[i].rbegin());
    w[i].insert(x);
    if (!w[i].empty()) sum += (*w[i].rbegin());
}

void del(int i, int x) {
    if (!w[i].empty()) sum -= (*w[i].rbegin());
    w[i].erase(w[i].find(x));
    if (!w[i].empty()) sum += (*w[i].rbegin());
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, w;
    cin >> n >> w;
    vector <vector <int>> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            int y;
            cin >> y;
            a[i].push_back(y);
        }
    }
    sort(a.begin(), a.end(), [&] (const vector <int> &f, const vector <int> &s) {
        return f.size() < s.size();
    });
    for (int i = 0; i < n; ++i) {
        add(i, 0);
    }
    int uk = 0;
    int vk = n - 1;
    for (int i = 0; i < w; ++i) {
        for (int j = uk; j < n; ++j) {
            if (i <= a[j].size()) {
                if (i < (int)a[j].size()) add(j, a[j][i]);
                else add(j, 0);
            }
        }
        while (uk < n && a[uk].size() == i) ++uk;
        int cur = w - i;
        while (vk >= 0 && -1 <= (int)a[vk].size() - cur - 1) --vk;
        for (int j = vk + 1; j < n; ++j) {
            if (-1 <= (int)a[j].size() - cur - 1) {
                if (0 <= (int)a[j].size() - cur - 1) del(j, a[j][(int)a[j].size() - cur - 1]);
                else del(j, 0);
            } 
        }
        cout << sum << ' ';
    }
}