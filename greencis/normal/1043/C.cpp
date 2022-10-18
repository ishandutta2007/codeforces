#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string s;
int ans[1005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> s;
    int n = (int)s.size();
    int i = 0;
    while (i < n) {
        int nxt = i;
        while (nxt < n && s[nxt] == 'b')
            ++nxt;
        int nxt2 = nxt;
        while (nxt2 < n && s[nxt2] == 'a')
            ++nxt2;
        if (nxt > 0)
            ans[nxt - 1] ^= 1;
        if (nxt2 > 0)
            ans[nxt2 - 1] ^= 1;
        i = nxt2;
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
}