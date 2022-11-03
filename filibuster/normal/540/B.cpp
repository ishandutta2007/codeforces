#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int INF = 1e9 + 13;

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;

    vector<int> a(n);
    int s = 0;
    int cnt = 0;
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        s += a[i];

        if(a[i] < y)
            cnt++;
    }

    for(int i = k; i < n; i++) {
        if(cnt < n / 2) {
            a[i] = 1;
            cnt++;
        } else {
            a[i] = y;
        }

        s += a[i];
    }

    vector<int> b = a;

    sort(a.begin(), a.end());

    if(a[n / 2] < y || s > x) {
        cout <<-1 << endl;
    } else {
        for(int i = k; i < n; i++)
            cout << b[i] << ' ';
    }

}