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

struct S {
    int x, y, z;
    S(int x, int y, int z) : x(x), y(y), z(z) {}
    S() {}
};

vector<S> a, b;
int n;
char s[10005];

inline bool cmp(const S &lhs, const S &rhs) {
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    if (lhs.y != rhs.y) return lhs.y < rhs.y;
    return lhs.z < rhs.z;
}

inline bool eq(const S &lhs, const S &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

int main() {
    a.pb(S(0, 0, 0));
    scanf("%d%s", &n, s);
    REP(i, n) {
        if (s[i] == 'G') {
            for (S &e : a) {
                ++e.x;
            }
        } else if (s[i] == 'S') {
            for (S &e : a) {
                ++e.y;
            }
        } else if (s[i] == 'H') {
            for (S &e : a) {
                ++e.z;
            }
        } else if (s[i] == 'R') {

        } else {
            b.clear();
            for (S e : a) {
                int mn = min(min(min(e.x, e.y), e.z), i - e.x - e.y - e.z);
                if (i - e.x - e.y - e.z == mn) b.pb(e);
                if (e.x == mn) b.pb(S(e.x + 1, e.y, e.z));
                if (e.y == mn) b.pb(S(e.x, e.y + 1, e.z));
                if (e.z == mn) b.pb(S(e.x, e.y, e.z + 1));
            }
            sort(b.begin(), b.end(), cmp);
            b.erase(unique(b.begin(), b.end(), eq), b.end());
            a = b;
        }
    }
    bool G, SS, H, R;
    G = SS = H = R = false;
    for (S e : a) {
        int mn = min(min(min(e.x, e.y), e.z), n - e.x - e.y - e.z);
        if (e.x == mn) G = true;
        if (e.y == mn) SS = true;
        if (e.z == mn) H = true;
        if (n - e.x - e.y - e.z == mn) R = true;
    }
    if (G) printf("Gryffindor\n");
    if (H) printf("Hufflepuff\n");
    if (R) printf("Ravenclaw\n");
    if (SS) printf("Slytherin\n");
    return 0;
}