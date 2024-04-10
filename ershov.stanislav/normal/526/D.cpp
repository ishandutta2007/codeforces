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

using namespace std;

const int N = 1e6 + 100;

int n, k, z[N];
char s[N];
int add[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    scanf(" %s", s);
    z[0] = n;
    int last = 0, lasti = 0;
    for (int i = 1; i < n; i++) {
        if (i <= last) {
            z[i] = min(last - i + 1, z[i - lasti]);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (last < z[i] + i - 1) {
            last = z[i] + i - 1;
            lasti = i;
        }
    }
//    for (int i = 0; i < n; i++) {
//        cout << z[i] << ' ';
//    }
//    cout << endl;
    for (int i = 1; i * k <= n; i++) {
        bool flag = true;
        for (int j = i; j < i * k; j += i) {
            if (z[j] < i) {
                flag = false;
                break;
            }
        }
        if (flag) {
//            cout << i * k - 1 << ' ' << min(i * k + z[i * k], N - 10) << endl;
            add[i * k - 1]++;
            add[min(min(i * k + z[i * k], N - 10), i * k + i)]--;
        }
    }
    int sum = 0;
    for (int i = 0; i <n; i++) {
        sum += add[i];
        if (sum > 0) {
            printf("1");
        } else {
            printf("0");
        }
    }
    return 0;
}