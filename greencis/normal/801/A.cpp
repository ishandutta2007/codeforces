#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string s;

int main()
{
    int ans = 0, was = 0;
    cin >> s;
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (s[i] == 'V' && s[i + 1] == 'K')
            ++ans, ++i;
        else if (s[i] == 'K') {
            if (s[i + 1] == 'K') {
                if (!was) {
                    was = 1;
                    ++ans;
                    ++i;
                }
            }
        } else {
            if (s[i + 2] != 'K') {
                if (!was) {
                    was = 1;
                    ++ans;
                    ++i;
                }
            }
        }
    }
    cout << ans;

    return 0;
}