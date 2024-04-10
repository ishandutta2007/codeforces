#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, x, y, u[105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    while (n--) {
        cin >> x >> y;
        for (; x <= y; ++x)
            u[x]++;
    }
    vector<int> ans;
    for (int i = 1; i <= m; ++i)
        if (!u[i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << " ";
}