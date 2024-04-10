#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

void fail() {
    cout << "NO" << endl;
    exit(0);
}

int n;
pair<ll, int> s[300105];
pair<ll, int> t[300105];
vector<pair<pii, ll>> ans;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    ll checksum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i].first;
        s[i].second = i + 1;
        checksum += s[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i].first;
        t[i].second = i + 1;
        checksum -= t[i].first;
    }
    if (checksum) fail();
    sort(s, s + n);
    sort(t, t + n);
    ll spare = 0;
    vector<pair<int, ll>> st;
    for (int i = 0; i < n; ++i) {
        if (s[i].first - spare > t[i].first)
            fail();
        if (s[i].first > t[i].first) {
            ll need = -t[i].first + s[i].first;
            spare -= need;
            while (need > 0) {
                ll cut = min(st.back().second, need);
                need -= cut;
                st.back().second -= cut;
                ans.push_back({{s[st.back().first].second, s[i].second}, cut});
                if (st.back().second == 0)
                    st.pop_back();
            }
        } else if (s[i].first < t[i].first) {
            spare += t[i].first - s[i].first;
            st.emplace_back(i, t[i].first - s[i].first);
        }
    }
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (const auto& p : ans) {
        cout << p.first.first << " " << p.first.second << " " << p.second << "\n";
    }
}