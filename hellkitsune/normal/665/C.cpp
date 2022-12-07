#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[200005];
int n;

int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 1; i < n; ++i) if (s[i] == s[i - 1]) {
        for (char c = 'a'; c <= 'z'; ++c) {
            if (c != s[i - 1] && (i == n - 1 || c != s[i + 1])) {
                s[i] = c;
                break;
            }
        }
    }
    printf("%s\n", s);
    return 0;
}