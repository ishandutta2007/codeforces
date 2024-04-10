#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int used[256];
int cnt, n;
string s;
set<char> st;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; s[i]; ++i)
        st.insert(s[i]);
    int L = 0, R = -1;
    int ans = n;
    while (L < n) {
        if (L <= R && (cnt == st.size() || R == n - 1)) {
            if (!--used[s[L++]])
                --cnt;
        } else {
            if (!used[s[++R]]++)
                ++cnt;
        }
        if (cnt == st.size())
            ans = min(ans, R - L + 1);
    }
    cout << ans;

    return 0;
}