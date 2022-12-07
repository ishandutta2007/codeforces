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

char s[105], t[105];
bool wasAt = false;
int n, m = 0;

int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ) {
        if (i != 0 && i < n - 2 && !wasAt && s[i] == 'a' && s[i + 1] == 't') {
            t[m++] = '@';
            wasAt = true;
            i += 2;
        } else if (i != 0 && i < n - 3 && s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't') {
            t[m++] = '.';
            i += 3;
        } else {
            t[m++] = s[i++];
        }
    }
    t[m] = '\0';
    printf("%s\n", t);
    return 0;
}