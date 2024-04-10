#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k, x, ans[905];
vector<int> v[35];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x;
        ans[x] = i + 1;
    }
    for (int i = 1; i <= k; ++i) {
        int cur = 1;
        int cnt = 0;
        while (cnt < n - 1) {
            if (!ans[cur]) {
                ans[cur] = i;
                ++cnt;
            }
            ++cur;
        }
    }
    for (int i = 1; i <= n * k; ++i)
        v[ans[i]].push_back(i);
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j)
            cout << v[i][j] << " ";
        cout << "\n";
    }

    return 0;
}