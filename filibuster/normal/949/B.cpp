#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*

*/

li get(li n, li i) {
//    cout << n << ' ' << i << endl;
    if(i % 2 == 1) {
        return (i + 1) / 2;
    }

    li ind;
    if(n % 2 == 1)
        ind = (i == 2 ? n / 2 : i / 2 - 1);
    else
        ind = i / 2;

    return get(n / 2, ind) + (n + 1) / 2;
}

void solve() {
    li n, q;
    cin >> n >> q;

    for(int i = 0; i < q; i++) {
        li x;
        cin >> x;

        cout << get(n, x) << endl;
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}