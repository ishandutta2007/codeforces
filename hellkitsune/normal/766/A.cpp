#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string a, b;

int main() {
    cin >> a >> b;
    if (a == b) {
        cout << -1 << endl;
    } else {
        cout << max(int(a.size()), int(b.size()));
    }
    return 0;
}