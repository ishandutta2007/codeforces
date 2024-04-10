#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, x, u[1000105];
vector<int> v;
vector<pii> can;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    while (n--) {
        cin >> x;
        u[x] = 1;
    }
    for (int i = 1; i <= 500000; ++i)
        if (!u[i] && !u[1000001 - i])
            can.push_back({i, 1000001 - i});
    for (int i = 1; i <= 1000000; ++i) {
        if (u[i]) {
            if (!u[1000001 - i])
                v.push_back(1000001 - i);
            else {
                u[i] = u[1000001 - i] = 0;
                v.push_back(can.back().first);
                v.push_back(can.back().second);
                can.pop_back();
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int x : v)
        cout << x << " ";

    return 0;
}