#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int m,s,s2,cur;
vector<int> v;

int main()
{
    cin >> m >> s;s2 = s;
    if (s == 0) {
        if (m == 1) cout << "0 0";
        else cout << "-1 -1";
        return 0;
    }
    if (s > 9 * m) { cout << "-1 -1"; return 0; }
    for (int i = 0; i < m; ++i) {
        if (s >= 9) v.push_back(9), s -= 9;
        else v.push_back(s), s = 0;
    }
    if (!v.back()) {
        for (int i = v.size() - 1; i >= 0; --i) {
            if (v[i]) {
                --v[i];
                ++v.back();
                break;
            }
        }
    }

    while (v.size()) {
        cout << v.back();
        v.pop_back();
    }
    cout << " ";


    for (int i = 0; i < m; ++i) {
        if (s2 >= 9) s2 -= 9, cout << 9;
        else { cout << s2; s2 = 0; }
    }

    return 0;
}