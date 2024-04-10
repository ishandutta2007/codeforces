#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int s, v, vv, t, tt;

int main() {
    scanf("%d%d%d%d%d", &s, &v, &vv, &t, &tt);
    int fi = 2 * t + v * s;
    int se = 2 * tt + vv * s;
    if (fi == se) {
        cout << "Friendship" << endl;
    } else if (fi < se) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}