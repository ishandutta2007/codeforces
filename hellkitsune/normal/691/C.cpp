#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char buf[1000005];
string s;
int n;

int main() {
    scanf("%s", buf);
    s = string(buf);
    n = (int)s.length();
    int pos = n;
    REP(i, n) if (s[i] == '.') pos = i;
    if (pos != n) {
        s.erase(pos, 1);
        --n;
    }
    --pos;
    int beg = 0;
    while (s[beg] == '0') ++beg;
    pos -= beg;
    s.erase(0, beg);
    while (s.back() == '0') s.pop_back();
    if ((int)s.length() > 1) {
        s.insert(1, ".");
    }
    printf("%s", s.c_str());
    if (pos != 0) {
        printf("E%d", pos);
    }
    printf("\n");
    return 0;
}