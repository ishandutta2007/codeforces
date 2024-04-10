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

bool ab, bc, ac;
string s;
const string IMP = "Impossible";

int main() {
    REP(i, 3) {
        cin >> s;
        bool a = false, b = false, c = false;
        bool ls;
        if (s[0] > s[2]) {
            swap(s[0], s[2]);
            ls = s[1] == '>';
        } else {
            ls = s[1] == '<';
        }
        REP(i, 3) if (s[i] == 'A') a = true;
        else if (s[i] == 'B') b = true;
        else if (s[i] == 'C') c = true;
        if (a && b) ab = ls;
        else if (b && c) bc = ls;
        else if (a && c) ac = ls;
    }
    if (ab && bc && ac) cout << "ABC" << endl;
    else if (ab && bc && !ac) cout << IMP << endl;
    else if (ab && !bc && ac) cout << "ACB" << endl;
    else if (ab && !bc && !ac) cout << "CAB" << endl;
    else if (!ab && bc && ac) cout << "BAC" << endl;
    else if (!ab && bc && !ac) cout << "BCA" << endl;
    else if (!ab && !bc && ac) cout << IMP << endl;
    else if (!ab && !bc && !ac) cout << "CBA" << endl;
    return 0;
}