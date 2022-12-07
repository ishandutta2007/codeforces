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

int cnt[5];
map<string, int> ma;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    ma["S"] = 0;
    ma["M"] = 1;
    ma["L"] = 2;
    ma["XL"] = 3;
    ma["XXL"] = 4;
    REP(i, 5) cin >> cnt[i];
    cin >> n;
    REP(i, n) {
        string s;
        cin >> s;
        int cur = ma[s];
        for (int delta = 0; delta < 5; ++delta) {
            if (cur + delta < 5 && cnt[cur + delta]) {
                cur += delta;
                break;
            }
            if (cur - delta >= 0 && cnt[cur - delta]) {
                cur -= delta;
                break;
            }
        }
        --cnt[cur];
        if (cur == 0) cout << "S\n";
        else if (cur == 1) cout << "M\n";
        else if (cur == 2) cout << "L\n";
        else if (cur == 3) cout << "XL\n";
        else cout << "XXL\n";
    }
    return 0;
}