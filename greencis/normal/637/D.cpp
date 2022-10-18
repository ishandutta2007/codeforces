#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, s, d, a[200005];
pii p[200005];
set<pii> st;
vector<pii> ans;

void fail() {
    puts("IMPOSSIBLE");
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> s >> d;
    a[0] = -1;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i) {
        if (i == n || a[i] + 1 + s + 1 <= a[i + 1])
            st.insert(make_pair(-(a[i] + 1), i));
    }

    int cur = a[0] + 1, curidx = 0;
    while (cur < m) {
        if (cur > a[n]) {
            if (m - cur > 0)
                ans.push_back(make_pair(0, m - cur));
            break;
        }
        if (cur + s >= a[curidx + 1])
            fail();
        ans.push_back(make_pair(0, a[curidx + 1] - cur - 1));
        set<pii>::iterator it = st.lower_bound(make_pair(-(a[curidx + 1] - 1 + d), -2e9));
        if (it == st.end() || -it->first <= cur)
            fail();
        cur = a[curidx + 1] - 1;
        ans.push_back(make_pair(1, -it->first - cur));
        cur = -it->first;
        curidx = it->second;
    }

    for (size_t i = 0; i < ans.size(); ++i) {
        if (ans[i].first == 0)
            cout << "RUN ";
        else
            cout << "JUMP ";
        cout << ans[i].second << "\n";
    }

    return 0;
}