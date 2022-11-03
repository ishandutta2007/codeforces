#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int n;
int a[N];
int k;
int b[N], s[N];

bool is(int x) {
    for(int i = 0; i < n; i++) {
        b[i] = (a[i] < x ? -1 : 1);
    }

    s[0] = 0;
    for(int i = 0; i < n; i++) {
        s[i + 1] = s[i] + b[i];
    }
//
//    cout << x << endl;
//    for(int i = 0; i <= n; i++)
//        cout << s[i] << ' ';
//    cout << endl;

    vector<int> mn(2, INF);
    for(int i = 0; i <= n; i++) {
//        cout << i << ' ' << s[i] << ' ' << mn << endl;
        if(s[i] - mn[(i ^ 1) % 2] >= 0)
            return true;

        if(s[i] - mn[i % 2] > 0)
            return true;
        if(i >= k - 1)
            mn[(i - k + 1) % 2] = min(mn[(i - k + 1) % 2], s[i - k + 1]);
    }
    return false;
}


int main() {
//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];

//    if(k % 2 == 0)
//        k++;

    int l = 0, r = n + 1;
    while(r - l > 1) {
        int m = (l + r) / 2;

        if(is(m))
            l = m;
        else
            r = m;
    }

    cout <<l << endl;

//    cout << "ans " << l << ' ' << r << endl;


}