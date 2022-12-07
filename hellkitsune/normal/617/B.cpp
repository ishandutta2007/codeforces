#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, pos = -1;
LL cnt = 1;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            if (pos != -1) {
                cnt *= i - pos;
            }
            pos = i;
        }
    }
    if (pos == -1) {
        printf("%d\n", 0);
    } else {
        cout << cnt << endl;
    }
    return 0;
}