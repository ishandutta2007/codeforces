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

int a[3];
string s;

int main() {
    REP(i, 3) {
        cin >> s;
        if (s[0] == 'r') a[i] = 0;
        else if (s[0] == 'p') a[i] = 1;
        else a[i] = 2;
    }
    REP(i, 3) {
        bool ok = true;
        REP(j, 3) if (j != i && a[i] != (a[j] + 1) % 3) {
            ok = false;
            break;
        }
        if (ok) {
            if (i == 0) printf("F\n");
            else if (i == 1) printf("M\n");
            else printf("S\n");
            return 0;
        }
    }
    printf("?\n");
    return 0;
}