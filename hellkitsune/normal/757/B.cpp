#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int cnt[100001] = {};
int n;
int a[100005];

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a + i);
    }
    forn(i, n) {
        int rem = a[i];
        for (int j = 2; j * j <= rem; ++j) {
            if (rem % j == 0) {
                ++cnt[j];
                rem /= j;
                while (rem % j == 0) {
                    rem /= j;
                }
            }
        }
        if (rem > 1) {
            ++cnt[rem];
        }
    }
    int mx = 1;
    forn(i, 100001) {
        mx = max(mx, cnt[i]);
    }
    cout << mx << endl;
    return 0;
}