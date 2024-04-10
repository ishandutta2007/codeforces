#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i].first >> t[i].second;
    }
    vector <int> achive(m + 1);
    achive[0] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < n; ++j)
            if (t[j].first <= i - 1 && i - 1 <= t[j].second && t[j].first <= i && i <= t[j].second)
                achive[i] = 1;
    for (int i = 0; i <= m; ++i) {
        if (!achive[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}