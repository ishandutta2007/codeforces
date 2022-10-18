#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, p[300105], revp[300105];
vector<pii> ans;

void my_swap(int i, int j) {
    if (i == j)
        return;
    if (i > j) swap(i, j);
    ans.emplace_back(i, j);
    swap(p[i], p[j]);
    revp[p[i]] = i;
    revp[p[j]] = j;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        revp[p[i]] = i;
    }
    if (n == 2) {
        if (p[1] == 1) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
            cout << "1 2" << endl;
        }
        return 0;
    }
    if (revp[1] - 1 >= n / 2)
        my_swap(1, revp[1]);
    else {
        my_swap(revp[1], n);
        my_swap(1, n);
    }
    for (int i = 2; i <= n; ++i) {
        if (p[i] != i) {
            if (revp[i] - i >= n / 2)
                my_swap(i, revp[i]);
            else {
                int to = revp[i];
                if (i - 1 >= n / 2 && revp[i] - 1 >= n / 2) {
                    my_swap(1, i);
                    my_swap(1, to);
                    my_swap(1, i);
                } else if (n - i >= n / 2 && n - revp[i] >= n / 2) {
                    my_swap(n, i);
                    my_swap(n, to);
                    my_swap(n, i);
                } else {
                    my_swap(i, n);
                    my_swap(n, 1);
                    my_swap(1, to);
                    my_swap(n, 1);
                    my_swap(i, n);
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for (const auto& p : ans)
        cout << p.first << " " << p.second << "\n";
}