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

string s, t;
int n;
string best = "";

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> n;
    REP(i, n) {
        cin >> t;
        if (t.length() >= s.length() && t.substr(0, s.length()) == s) {
            if (best.empty() || best > t) {
                best = t;
            }
        }
    }
    if (best.empty()) best = s;
    cout << best << endl;
    return 0;
}