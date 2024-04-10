#include<bits/stdc++.h>

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
#define rank _rank

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

bool is_prime[1100];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    for (int i = 2; i < 1100; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i * i < 1100; i++) {
        for (int j = i * i; j < 1100; j += i) {
            is_prime[j] = false;
        }
    }
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 2; i < 1100; i++) {
        if (is_prime[i]) {
            for (int j = i; j <= n; j *= i) {
                ans.pb(j);
            }
        }
    }
    cout << (int) ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " \n"[i == (int) ans.size() - 1];
    }
    return 0;
}