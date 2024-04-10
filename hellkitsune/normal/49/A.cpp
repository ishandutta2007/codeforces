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

char ans = 'z';
string s;

int main() {
    while (cin >> s) {
        for (char c : s) if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            ans = c;
        }
    }
    if (ans >= 'A' && ans <= 'Z') ans += 'a' - 'A';
    if (ans == 'a' || ans == 'e' || ans == 'i' || ans == 'o' || ans == 'u' || ans == 'y') {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}