#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'
#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k, t;
    cin >> n >> k >> t;
    int ans = 0;
    if (t <= k) {
        ans = t;
    } else if (t <= n) {
        ans = k;
    } else {
        ans = k - (t - n);
    }
    cout << ans << endl;
    return 0;
}