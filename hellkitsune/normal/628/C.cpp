#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
char s[100005];

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    REP(i, n) {
        int val = s[i] - 'a';
        if (val < 13) {
            int mx = min(25 - val, k);
            val += mx;
            k -= mx;
        } else {
            int mx = min(val, k);
            val -= mx;
            k -= mx;
        }
        s[i] = val + 'a';
    }
    if (k) {
        printf("-1\n");
    } else {
        printf("%s\n", s);
    }
    return 0;
}