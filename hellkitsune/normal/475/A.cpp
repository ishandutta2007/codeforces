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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;

void printLine() {
    cout << '+';
    REP(i, 24) cout << '-';
    cout << "+\n";
}

void pLine(int cnt, bool d = false) {
    printf("|");
    REP(i, cnt) printf("O.");
    REP(i, 11 - cnt) printf("#.");
    printf("|");
    if (d) printf("D");
    else printf(".");
    printf("|");
}

void pLine2() {
    printf("|");
    if (n < 3) printf("#");
    else printf("O");
    REP(i, 23) printf(".");
    printf("|");
}

int main() {
    scanf("%d", &n);
    printLine();
    int m = n - 4;
    if (n == 0) pLine(0, true);
    else if (n <= 4) pLine(1, true);
    else pLine(1 + (m + 2) / 3, true);
    printf(")\n");
    if (n <= 1) pLine(0);
    else if (n <= 4) pLine(1);
    else pLine(1 + (m + 1) / 3);
    printf("\n");
    pLine2();
    printf("\n");
    if (n <= 3) pLine(0);
    else if (n == 4) pLine(1);
    else pLine(1 + m / 3);
    printf(")\n");
    printLine();
    return 0;
}