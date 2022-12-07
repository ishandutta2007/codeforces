#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[100005];
int n;

int main() {
    scanf("%s", s);
    n = strlen(s);
    int pos = -1;
    forn(i, n) if (s[i] != 'a') {
        pos = i;
        break;
    }
    if (pos == -1) {
        s[n - 1] = 'z';
        printf("%s\n", s);
        return 0;
    }
    for (int i = pos; i < n; ++i) {
        if (s[i] == 'a') break;
        --s[i];
    }
    printf("%s\n", s);
    return 0;
}