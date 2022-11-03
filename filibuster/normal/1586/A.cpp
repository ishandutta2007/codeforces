//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

bool is(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0)
            return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    if(is(s)) {
        cout << n << endl;
        for(int i = 1; i <= n; i++)
            cout << i << ' ';
        cout << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(is(s - a[i])) {
            cout << n - 1 << endl;
            for(int j = 1; j <= n; j++)
                if(j != i + 1)
                    cout << j << ' ';
            cout << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

}