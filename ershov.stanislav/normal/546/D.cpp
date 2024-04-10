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

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 5000500;
bool prime[N];
int cnt[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    for (int i = 2; i < N; i++) {
        prime[i] = true;
    }
    for (int i = 2; i * i < N; i++) {
        for (int j = i * i; j < N; j += i) {
            prime[j] = false;
        }
    }
    for (int i = 2; i < N; i++) {
        if (prime[i]) {
            for (long long j = i; j < N; j *= i) {
                for (int k = (int) j; k < N; k += (int) j) {
                    cnt[k]++;
                }
            }
        }
    }
    for (int i = 2; i < N; i++) {
        cnt[i] += cnt[i - 1];
    }
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", cnt[a] - cnt[b]);
    }
    return 0;
}