#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 15e6;

int p10[10], p, q;
int cnt;
bool is_prime[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    p10[0] = 1;
    scanf("%d%d", &p, &q);
    for (int i = 2; i < N; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 1; i < 10; i++) {
        p10[i] = p10[i - 1] * 10;
    }
    ll cnt1 = 0, cnt2 = 0, mx = 0;
    for (int i = 1; i < N; i++) {
        bool flag = true;
        int c = 0;
        int n = i;
        while (n) {
            c++;
            n /= 10;
        }
        for (int j = 0; j < c / 2; j++) {
            if ((i / (p10[j])) % 10 != (i / (p10[c - 1 - j])) % 10) {
                flag = false;
            }
        }
        if (flag) {
            cnt2++;
        }
        if (is_prime[i]) {
            cnt1++;
        }
//        if (i < 3500) {
//            cout << i << ' ' << cnt1 << ' ' << cnt2 << endl;
//        }
        if (cnt1 * q <= cnt2*p) {
            mx = i;
        }
    }
    if (mx > 0) printf("%d\n", mx);
    else {
        printf("Palindromic tree is better than splay tree\n");
    }
    return 0;
}