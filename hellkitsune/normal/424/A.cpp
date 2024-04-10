#include <cstdio>
#include <cmath>
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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;

int main() {
    cin >> n >> s;
    int bal = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'x')
            bal--;
        else
            bal++;
    int ans = abs(bal) / 2;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'x' && bal < 0) {
            s[i] = 'X';
            bal += 2;
        } else if (s[i] == 'X' && bal > 0) {
            s[i] = 'x';
            bal -= 2;
        }
    }
    cout << ans << endl << s << endl;
    return 0;
}