#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char buf[15];
string s[200000];
set<string> se;
vector<string> ans;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%s", buf);
        s[i] = string(buf);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (!se.count(s[i])) {
            se.insert(s[i]);
            ans.pb(s[i]);
        }
    }
    for (string s : ans) {
        printf("%s\n", s.c_str());
    }
    return 0;
}