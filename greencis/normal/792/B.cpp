#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    int cur = 0;
    while (k--) {
        int x;
        cin >> x;
        (cur += x) %= v.size();
        cout << v[cur] << " ";
        v.erase(v.begin() + cur);
    }

    return 0;
}