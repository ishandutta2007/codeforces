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

int main() {
    string s;
    cin >> s;
    bool sm = false, cap = false, num = false;
    REP(i, s.length())
        if (s[i] >= 'a' && s[i] <= 'z') sm = true;
        else if (s[i] >= 'A' && s[i] <= 'Z') cap = true;
        else if (s[i] >= '0' && s[i] <= '9') num = true;
    if ((int)s.length() >= 5 && sm && cap && num)
        cout << "Correct" << endl;
    else
        cout << "Too weak" << endl;
    return 0;
}