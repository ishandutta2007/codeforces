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

int a[1000];
char s[1005];
int n;

int main() {
    scanf("%d%s", &n, s);
    a[0] = 1;
    REP(i, n - 1) if (s[i] == 'L') {
        if (a[i] == 1) {
            ++a[i];
            for (int j = i; j && s[j - 1] != 'R' && (s[j - 1] != 'L' || a[j] == a[j - 1]); --j) {
                ++a[j - 1];
            }
        }
        a[i + 1] = 1;
    } else if (s[i] == '=') {
        a[i + 1] = a[i];
    } else {
        a[i + 1] = a[i] + 1;
    }
    REP(i, n) printf("%d ", a[i]);
    printf("\n");
    return 0;
}