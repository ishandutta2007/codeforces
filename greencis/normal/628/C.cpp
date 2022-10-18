#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int n,k,can;
char s[300105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> s;
    for (int i = 0; s[i]; ++i) {
        int z = s[i] - 'a';
        can += max(z, 25 - z);
    }
    if (can < k) cout << -1;
    else {
        for (int i = 0; i < n; ++i) {
            if (s[i] <= 'm') {
                int z = min(k, 'z' - s[i]);
                s[i] += z;
                k -= z;
            } else {
                int z = min(k, s[i] - 'a');
                s[i] -= z;
                k -= z;
            }
        }
        cout << s;
    }

    return 0;
}