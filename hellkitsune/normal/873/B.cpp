#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;
int where[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    int bal = n;
    memset(where, -1, sizeof where);
    where[bal] = 0;
    int ans = 0;
    forn(i, n) {
        if (s[i] == '1') ++bal;
        else --bal;
        if (where[bal] != -1) {
            ans = max(ans, i + 1 - where[bal]);
        } else {
            where[bal] = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}