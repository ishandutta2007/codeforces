#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char buf[55];
string s[50000];

inline bool cmp(const string &lhs, const string &rhs) {
    return lhs + rhs < rhs + lhs;
}

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%s", buf);
        s[i] = string(buf);
    }
    sort(s, s + n, cmp);
    REP(i, n) printf("%s", s[i].c_str());
    cout << endl;
    return 0;
}