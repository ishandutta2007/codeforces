#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <chrono>
#include <random>
#include <map>
#include <bitset>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = a[n - 1] - a[0];
    multiset<ll> s;
    for (int i = 1; i < n; i++)
    {
        s.insert(a[i - 1] - a[i]);
    }
    for (int i = 0; i < k - 1; i++)
    {
        ans += *s.begin();
        s.erase(s.begin());
    }
    cout << ans << "\n";
    return 0;
}