#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;

int main() {
    cin >> s;
    int ans = 0;
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ++ans;
        }
        if (c == '1' || c == '3' || c == '5' || c == '7' || c == '9') {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}