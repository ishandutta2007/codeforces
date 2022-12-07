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
typedef unsigned long long ULL;
typedef pair<int, int> PII;

string s;
bool mns = false;
ULL A = 128;
ULL B = 32768;
ULL C = 2147483648;
ULL D = 9223372036854775808;

int main() {
    cin >> s;
    if (s[0] == '-') {
        mns = true;
        s.erase(s.begin());
    }
    if ((int)s.length() > 19) {
        cout << "BigInteger" << endl;
        return 0;
    }
    ULL x;
    istringstream iss(s);
    iss >> x;
    if (!mns) {
        --A, --B, --C, --D;
    }
    if (x <= A) cout << "byte" << endl;
    else if (x <= B) cout << "short" << endl;
    else if (x <= C) cout << "int" << endl;
    else if (x <= D) cout << "long" << endl;
    else cout << "BigInteger" << endl;
    return 0;
}