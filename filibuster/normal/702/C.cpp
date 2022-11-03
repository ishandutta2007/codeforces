#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e5 + 13;


/*

*/

int n, m;
int a[N], b[N];

bool is(li r) {
    int j = 0;
    for(int i = 0; i < n; i++) {
        while(j < m && abs(a[i] - b[j]) > r)
            j++;
        if(j == m)
            return false;
    }
    return true;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);

    li l = -1, r = INF;
    while(r - l > 1) {
        li mid = (l + r) / 2;

        if(is(mid))
            r = mid;
        else
            l = mid;
    }

    cout << r << endl;
}