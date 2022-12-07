#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b;
char s[100005];

int main() {
    scanf("%d%d%d", &n, &a, &b);
    scanf("%s", s);
    --a, --b;
    if (s[a] == s[b]) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}