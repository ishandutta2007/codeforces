#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (k & 1) {
            if (a < 4) {
                ans ^= (a & 1);
            } else {
                int cnt = 0;
                while (a % 2 == 0) {
                    a /= 2;
                    cnt++;
                }
                if (cnt != 0) {
                    if (a != 3) {
                        if (cnt & 1) {
                            ans ^= 1;
                        } else {
                            ans ^= 2;
                        }
                    } else {
                        if (cnt & 1) {
                            ans ^= 2;
                        } else {
                            ans ^= 1;
                        }
                    }
                }
            }
        } else {
            if (a < 3) {
                ans ^= a;
            } else {
                if (a % 2 == 0) {
                    ans ^= 1;
                }
            }
        }
    }
    if (ans) {
        printf("Kevin\n");
    } else {
        printf("Nicky\n");
    }
    return 0;
}