#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,x;
vector<int> a,v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    int ans = 2e9;
    for (int i = 1; i < n-1; ++i) {
        v = a;
        v.erase(v.begin() + i);
        int cur = 0;
        for (int j = 0; j + 1 < v.size(); ++j) cur = max(cur, v[j+1]-v[j]);
        ans = min(ans, cur);
    }
    cout << ans;

    return 0;
}