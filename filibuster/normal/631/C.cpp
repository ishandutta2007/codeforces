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
const int K = 10;

/*
*/


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pii> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i].f >> b[i].s;
    }
//cout << "grd" << endl;
    vector<int> mx(m + 1);
    mx[m] = m;
    mx[m - 1] = m - 1;
    for(int i = m - 2; i >= 0; i--) {
        mx[i] = (b[mx[i + 1]].s > b[i].s ? mx[i + 1] : i);
    }
//cout << mx[0] << endl;
    vector<int> c = a;//cout << "grd" << endl;
    sort(c.begin(), c.begin() + b[mx[0]].s);
//cout << "grd" << endl;
    int l = 0, r = b[mx[0]].s;
    int i = mx[0];
    while(i < m) {
        int j = mx[i + 1];
        int x = (j == m ? 0 : b[j].s);

//        cout << i << endl;

        int cur = b[i].s - 1;
        while(r - l > x) {
            if(b[i].f == 1) {
                r--;
                a[cur] = c[r];
            } else {
                a[cur] = c[l];
                l++;
            }
            cur--;
        }
        i = j;
    }

    for(auto x : a)
        cout << x << ' ';
}