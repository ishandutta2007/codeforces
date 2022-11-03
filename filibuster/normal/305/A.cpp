#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int N = 2e5 + 13;
const int M = 1e9 + 7;

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b;
    for(int i = 0; i < n; i++)
        if(a[i] == 0)
            b.push_back(0);

    for(int i = 0; i < n; i++)
        if(0 < a[i] && a[i] < 10) {
            b.push_back(a[i]);
            break;
        }

    for(int i = 0; i < n; i++)
        if(10 <= a[i] && a[i] < 100 && (a[i] % 10 == 0 || b.empty() || b.back() == 0)) {
            b.push_back(a[i]);
            break;
        }

    for(int i = 0; i < n; i++)
        if(100 == a[i]) {
            b.push_back(a[i]);
            break;
        }

    cout << b.size() << endl;
    for(auto x : b)
        cout << x << ' ';
}