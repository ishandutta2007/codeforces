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
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    int k1, k2;
    cin >> k1;
    queue<int> q1, q2;
    for (int i = 0; i < k1; i++) {
        int a;
        cin >> a;
        q1.push(a);
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int a;
        cin >> a;
        q2.push(a);
    }

    int cur = k1;

    for (int i = 0; i < 50000000; i++) {
        if (q1.size() == 0) {
            cout << i << " 2";
            return 0;
        }
        if (q2.size() == 0) {
            cout << i << " 1";
            return 0;
        }

        int a = q1.front(), b = q2.front();
        q1.pop(), q2.pop();
        if (a > b) {
            q1.push(b);
            q1.push(a);
        } else {
            q2.push(a);
            q2.push(b);
        }
    }

    cout << "-1" << endl;

    return 0;
}