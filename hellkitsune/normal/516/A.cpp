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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;
int d[100] = {};

void ad(int x) {
    for (int i = 2; x > 1; ++i) if (x % i == 0) {
        while (x % i == 0) {
            x /= i;
            ++d[i];
        }
    }
}

string ans;

int main() {
    cin >> n >> s;
    REP(i, n) {
        int dig = s[i] - '0';
        for (int j = 2; j <= dig; ++j)
            ad(j);
    }
    for (int i = 7; i >= 2; --i) {
        assert(d[i] >= 0);
        while (d[i]) {
            ans += char('0' + i);
            for (int j = i; j >= 2; --j) {
                if (j == 7) --d[7];
                else if (j == 6) --d[2], --d[3];
                else if (j == 5) --d[5];
                else if (j == 4) d[2] -= 2;
                else if (j == 3) --d[3];
                else --d[2];
            }
        }
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}