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

string s;
int zzz;

int cnt[26] = {}, ans = 0;

int main() {
    cin >> zzz >> s;
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            ++cnt[c - 'a'];
        } else {
            if (cnt[c - 'A'] == 0)
                ++ans;
            else
                --cnt[c - 'A'];
        }
    }
    cout << ans << endl;
    return 0;
}