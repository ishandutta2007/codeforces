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
    int n;
    cin >> n;
    for (int t = 0; t < n; ++t) {
        int x;
        cin >> x;
        bool found = false;
        for (int a = 0; a < x; ++a) {
            for (int b = 0; b < x; ++b) {
                if (3 * a + 7 * b == x) {
                    cout << "YES" << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if(!found) cout << "NO" << endl;
    }
    return 0;
}