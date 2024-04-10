#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    int n;
    vector<int> v;
    cin >> n;
    int extra = 1;
    int ans = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (b)
            extra += b - 1, ans += a;
        else
            v.push_back(a);
    }
    sort(all(v), greater<int>());
    for (int i = 0; i < extra && i < v.size(); ++i)
        ans += v[i];
    cout << ans;
}