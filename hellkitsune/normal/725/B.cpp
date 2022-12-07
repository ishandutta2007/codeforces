#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;
LL ans = 0;

int main() {
    cin >> s;
    while (!(s.back() >= 'a' && s.back() <= 'f')) {
        s.pop_back();
    }
    char c = s.back();
    s.pop_back();
    istringstream iss(s);
    LL pos;
    iss >> pos;
    --pos;
    ans = (pos / 4) * 12;
    ans += pos;
    pos %= 4;
    if (pos == 1 || pos == 3) {
        ans += 6;
    }
    if (pos == 2 || pos == 3) {
        ans -= 2;
    }
    if (c == 'f') ans += 1;
    if (c == 'e') ans += 2;
    if (c == 'd') ans += 3;
    if (c == 'a') ans += 4;
    if (c == 'b') ans += 5;
    if (c == 'c') ans += 6;

    cout << ans << endl;
    return 0;
}