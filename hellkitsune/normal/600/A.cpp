#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[100005];
string cur;
vector<string> a, b;
int n;

bool check(string &s) {
    if (s.empty()) return false;
    for (char c : s) if (!(c >= '0' && c <= '9')) return false;
    if (s[0] == '0' && (int)s.length() > 1) return false;
    return true;
}

void out(vector<string> &a) {
    if (a.empty()) {
        printf("-\n");
        return;
    }
    printf("\"");
    REP(i, a.size()) {
        if (i) printf(",");
        printf("%s", a[i].c_str());
    }
    printf("\"\n");
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    s[n++] = ',';
    REP(i, n) if (s[i] == ',' || s[i] == ';') {
        if (check(cur)) a.pb(cur);
        else b.pb(cur);
        cur = "";
    } else {
        cur += s[i];
    }
    out(a);
    out(b);
    return 0;
}