#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;
string bad[11] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA",
                    "VODKA", "WHISKEY", "WINE"};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int ans = 0;
    REP(i, n) {
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9') {
            istringstream iss(s);
            int x;
            iss >> x;
            if (x < 18) ++ans;
        } else {
            bool ok = true;
            REP(i, 11) if (bad[i] == s) {
                ok = false;
                break;
            }
            if (!ok) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}