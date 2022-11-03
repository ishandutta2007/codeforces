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

int n;

int get(vector<int> a) {
    cout << "? ";
    for(int x : a)
        cout << x << ' ';
    cout << endl;

    int res;
    cin >> res;

    return res - 1;
}

void out(vector<int> a) {
    cout << "! ";
    for(int x : a)
        cout << x << ' ';
    cout << endl;
}

void solve() {

    cin >> n;

    vector<int> a(n, 1);
    vector<int> p(n, -1);
    for(a[n - 1] = n; a[n - 1] >= 1; a[n - 1]--) {
        int res = get(a);

        if(res != -1) {
            p[n - 1] = n - a[n - 1] + 1;
            break;
        }
    }

    if(p[n - 1] == -1) {
        p[n - 1] = n;
    }

    for(int i = 0; i < n; i++) {
        a[i] = p[n - 1];
    }

    for(a[n - 1] = 1; a[n - 1] <= n; a[n - 1]++) if(a[n - 1] != p[n - 1]) {
        int res = get(a);

        p[res] = a[n - 1];
    }

    out(p);
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();

}