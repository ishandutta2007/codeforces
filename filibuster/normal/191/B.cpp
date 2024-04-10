#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 1e5 + 13;
const int B = 350;
const int A = 26;
const int LOGN = 20;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, k;
    cin >> n >> k;

    li b;
    cin >> b;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> c(n - 1);
    for(int i = 0; i < n - 1; i++)
        c[i] = a[i];

    sort(c.rbegin(), c.rend());

    li sum = 0;
    for(int i = 0; i < k - 1; i++) {
        sum += c[i];
    }

    for(int i = 0; i < n - 1; i++) {
        li s = sum;
        if(a[i] > c[k - 1]) {
            s += c[k - 1] - a[i];
        }

        if(a[i] + s > b) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << n << endl;
}