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
const int A = 513;

int di[] = {0, 1, -1, 0};
int dj[] = {1, 0, 0, -1};
/*
*/

mt19937 rnd(5443);

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int mn = INF, cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < mn) {
            mn = a[i];
            cnt = 1;
        } else if(a[i] == mn) {
            cnt++;
        }
    }

    cout << n - cnt << endl;
}

int main() {


    int t = 1;
    cin >> t;

    while(t--)
        solve();
}