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

const int INF = (int) 1e9 + 100;
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
    int n;
    scanf("%d", &n);
    for (int i = 20; i >= 0; i--) {
        if (n & (1 << i)) {
            printf("%d ", i + 1);
        }
    }
    return 0;
}