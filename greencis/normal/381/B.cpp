#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, a[100105], b[100105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], ++b[a[i]];
    vector<int> ans;
    for (int i = 1; i <= 5000; ++i) {
        if (b[i]) {
            --b[i];
            ans.push_back(i);
        }
    }
    for (int i = ans.back() - 1; i >= 1; --i) {
        if (b[i]) {
            --b[i];
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int i : ans)
        cout << i << " ";

    return 0;
}