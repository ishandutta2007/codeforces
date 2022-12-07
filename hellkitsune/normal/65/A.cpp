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

int a, b, c, d, e, f;

int main() {
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    if (d == 0) {
        printf("Hermione\n");
        return 0;
    }
    if (b == 0) {
        if (c == 0) {
            printf("Ron\n");
        } else {
            printf("Hermione\n");
        }
        return 0;
    }
    if (f == 0) {
        if (a == 0 || c == 0) {
            printf("Ron\n");
        } else {
            printf("Hermione\n");
        }
        return 0;
    }
    if (b * d * f > a * c * e) {
        printf("Ron\n");
    } else {
        printf("Hermione\n");
    }
    return 0;
}