#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(NULL);
    int k; cin >> k;
    if (k % 2 == 0) { cout << "NO"; return 0; }
    cout << "YES" << endl;
    int n = (k - 1) * (k - 1);
    vector <int> v(n);
    vector < pair <int, int> > ans;
    for (int i = 0; i < (k - 1) / 2; i++)
        for (int j = 0; j < n; j++)
            ans.push_back({j, (i + j + 1) % n});
    for (int i = 0; i < n; i++)
        ans.push_back({i, i / (k - 1) + n});
    for (int i = 0; i < (k - 1); i++)
        ans.push_back({n + k - 1, n + i});

    cout << 2 * (n + k) << " " << 2 * ans.size() + 1 << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i].first + n + k + 1 << " " << ans[i].second + n + k + 1 << endl;
    cout << n + k << " " << 2 * (n + k);
}