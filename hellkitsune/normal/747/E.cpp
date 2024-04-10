#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[1000005];
int n;
vector<string> ans[500005];
int mx = 0;

string cur;

int pos;

int getNum(string &s) {
    istringstream iss(s);
    int x;
    iss >> x;
    return x;
}

void solve(int dep) {
    mx = max(mx, dep);
    cur.clear();
    while (pos < n && s[pos] != ',') {
        cur += s[pos];
        ++pos;
    }
    ans[dep].pb(cur);
    ++pos;
    cur.clear();
    while (pos < n && s[pos] != ',') {
        cur += s[pos];
        ++pos;
    }
    int num = getNum(cur);
    forn(i, num) {
        ++pos;
        solve(dep + 1);
    }
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    pos = 0;
    while (pos < n) {
        solve(0);
        ++pos;
    }
    printf("%d\n", mx + 1);
    forn(i, mx + 1) {
        bool firstTime = true;
        for (string s : ans[i]) {
            if (!firstTime) {
                printf(" ");
            }
            firstTime = false;
            printf("%s", s.c_str());
        }
        puts("");
    }
    return 0;
}