#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, k;
string s;
vector<int> dp[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    dp[1] = vector<int>(k + 1, 1e9);
    dp[1][0] = 0;
    while (n--) {
        cin >> s;
        vector<int> pos;
        for (int i = 0; s[i]; ++i)
            if (s[i] == '1')
                pos.push_back(i);
        vector<int> tm(pos.size() + 1, 1e9);
        tm[pos.size()] = 0;
        for (int i = 0; i < pos.size(); ++i)
            for (int j = i; j < pos.size(); ++j)
                tm[pos.size() - (j - i + 1)] = min(tm[pos.size() - (j - i + 1)], pos[j] - pos[i] + 1);
        swap(dp[0], dp[1]);
        dp[1].assign(k + 1, 1e9);
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= pos.size() && i + j <= k; ++j)
                dp[1][i + j] = min(dp[1][i + j], dp[0][i] + tm[j]);
        }
    }
    cout << *min_element(all(dp[1])) << endl;
}