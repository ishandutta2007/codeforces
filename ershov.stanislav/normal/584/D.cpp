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

const int MOD = 1e9 + 7;
const int N = 1e5 + 100;

int n;
vector<int> primes;
bool isprime[N];

bool check(int a) {
    for (int i = 0; primes[i] * primes[i] <= a; i++) {
        if (a % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    for (int i = 2; i < N; i++) {
        isprime[i] = true;
    }
    for (int i = 2; i * i < N; i++) {
        if (isprime[i]) {
            for (int j = i * i; j < N; j += i) {
                isprime[j] = false;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (isprime[i]) {
            primes.pb(i);
        }
    }
    cin >> n;
    vector<int> ans;
    if (n == 3) {
        cout << 1 << endl << 3 << endl;
    } else if (n == 5) {
        cout << 2 << endl << 2 << ' ' << 3 << endl;
    } else {
        ans.pb(3);
        n -= 3;
        for (int i = 2; ; i++) {
            if (check(i) && check(n - i)) {
                ans.pb(i);
                ans.pb(n - i);
                break;
            }
        }
        cout << sz(ans) << endl;
        for (auto i : ans) {
            cout << i << " ";
        }
    }
    return 0;
}