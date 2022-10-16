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
    ll n, k;
    cin >> n >> k;
    ll odd = (n - 1) / 2 + 1;
    if (k > odd) {
        ll ind = k - odd;
        cout << 2 * ind << endl;
    } else {
        cout << 1 + 2 * (k - 1) << endl;
    }
    return 0;
}