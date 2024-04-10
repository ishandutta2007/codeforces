#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string s;

int main()
{
    cin >> s;
    int idx = 0;
    while (idx < s.size() && s[idx] == 'a') ++idx;
    if (idx == s.size()) {
        s[s.size() - 1] = 'z';
        cout << s << endl;
        return 0;
    }
    int idx2 = idx;
    while (idx2 < s.size() && s[idx2] >= 'b') ++idx2;
    for (int i = idx; i < idx2; ++i) {
        s[i] -= 1;
    }
    cout << s << endl;

    return 0;
}