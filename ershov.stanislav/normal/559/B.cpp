#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define fs first
#define sc second
#define all(x) x.begin(), x.end()

#define y1 hrhrthrtethet

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;
typedef long long ll;

const int N = 2e5 + 100;

char s[N], t[N];

bool check(int l1, int r1, int l2, int r2) {
    if ((r1 - l1) & 1) {
        bool ans = true;
        for (int i = l1; i < r1; i++) {
            if (s[i] != t[i + l2 - l1]) {
                ans = false;
            }
        }
//        cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << ' ' << ans << endl;
        return ans;
    }
    int mid1 = (l1 + r1) / 2;
    int mid2 = (l2 + r2) / 2;
    if (rand() & 1) {
        if (check(l1, mid1, l2, mid2)) {
            if (check(mid1, r1, mid2, r2)) {
                return true;
            }
        }
        if (check(l1, mid1, mid2, r2)) {
            if (check(mid1, r1, l2, mid2)) {
                return true;
            }
        }
        return false;
    } else {
        if (check(l1, mid1, mid2, r2)) {
            if (check(mid1, r1, l2, mid2)) {
                return true;
            }
        }
        if (check(l1, mid1, l2, mid2)) {
            if (check(mid1, r1, mid2, r2)) {
                return true;
            }
        }
        return false;
    }
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    srand(time(NULL));
    scanf("%s %s", s, t);
    int n = strlen(s);
    if (check(0, n, 0, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}