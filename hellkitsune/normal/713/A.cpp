#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[50];
map<string, int> cnt;

string nor(string s) {
    reverse(s.begin(), s.end());
    for (char &c : s) {
        if ((c - '0') % 2 == 0) {
            c = '0';
        } else {
            c = '1';
        }
    }
    while ((int)s.length() < 20) {
        s += '0';
    }
    return s;
}

int main() {
    scanf("%d", &n);
    forn(i, n) {
        char qt;
        scanf(" %c", &qt);
        scanf("%s", s);
        string t = string(s);
        if (qt == '+') {
            ++cnt[nor(t)];
        } else if (qt == '-') {
            --cnt[nor(t)];
        } else {
            printf("%d\n", cnt[nor(t)]);
        }
    }
    return 0;
}