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

int a;
char s1[10], s2[10];
int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d %s %s", &a, s1, s2);
    if (s2[0] == 'w') {
        a -= 5;
        a = (a % 7 + 7) % 7;
        int ans = 366 / 7;
        if (a < 366 % 7) {
            ans++;
        }
        cout << ans << endl;
    } else {
        int ans = 0;
        for (int i = 0; i < 12; i++) {
            if (days[i] >= a) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}