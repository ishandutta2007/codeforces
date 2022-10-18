#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll val[256];
const ll MOD = 1000003;

int main()
{
    val['>'] = 8;
    val['<'] = 9;
    val['+'] = 10;
    val['-'] = 11;
    val['.'] = 12;
    val[','] = 13;
    val['['] = 14;
    val[']'] = 15;
    string s;
    cin >> s;
    ll ans = 0;
    for (char c : s) {
        ans = (ans * 16 + val[c]) % MOD;
    }
    cout << ans;

    return 0;
}