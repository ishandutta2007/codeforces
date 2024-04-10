#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

int n;
pii p[105];
vector<pii> ans;

void fail() { puts("-1"); exit(0); }

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first;
        p[i].second = i + 1;
    }
    sort(p + 1, p + n);
    reverse(p + 1, p + n);

    int k = 0;
    int process = 1;
    while (k < n && process < n) {
        if (k >= process)
            fail();
        if (!p[k].first) {
            ++k;
            continue;
        }
        --p[k].first;
        ans.push_back(make_pair(k, process));
        ++process;
    }
    if (k >= process || (int)ans.size() != n - 1)
        fail();

    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); ++i)
        cout << p[ans[i].first].second << " " << p[ans[i].second].second << endl;

    return 0;
}