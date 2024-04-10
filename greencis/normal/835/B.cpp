#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int k, a[100];
string s;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> k >> s;
    int sum = 0;
    for (char c : s) {
        ++a[c - '0'];
        sum += c - '0';
    }
    k -= sum;
    int ans = 0;
    if (k > 0) {

    for (int i = 0; i < 9; ++i) {
        int can = a[i] * (9 - i);
        if (can >= k) {
            ans += (k + 8 - i) / (9 - i);
            break;
        }
        k -= can;
        ans += a[i];
    }
    }
    cout << ans << endl;

    return 0;
}