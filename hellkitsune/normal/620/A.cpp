#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL x, y, xx, yy;

int main() {
    cin >> x >> y >> xx >> yy;
    cout << max(abs(x - xx), abs(y - yy)) << endl;
    return 0;
}