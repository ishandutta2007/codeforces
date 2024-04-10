#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, t;
string s;

int main()
{
    cin >> n >> t >> s;
    if (s[0] == '.') s = "0" + s;
    int idx = 0;
    while (s[idx] != '.')
        ++idx;
    int d = 1;
    ++idx;
    for (; idx < s.size(); ++idx) {
        if (s[idx] >= '5') {
            s.erase(idx, s.size() - idx);
            bool past_period = false;
            --t;
            for (int i = idx - 1; i >= 0; --i) {
                if (s[i] == '.') {
                    past_period = true; continue;
                }
                s[i] = (s[i] - 48 + d);
                d = s[i] / 10; s[i] %= 10;
                s[i] += 48;
                if (!past_period && s[i] >= '5' && t) {
                    --t;
                    s.erase(i, s.size() - i);
                    d = 1;
                }
            }
            if (d) s = "1" + s;
            break;
        }
    }

    if (s[s.size() - 1] == '.') s.erase(s.size() - 1, 1);
    cout << s << endl;

    return 0;
}