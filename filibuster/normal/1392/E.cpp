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


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = (i % 2 == 1 ? 0 : i + j);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
//            cout << (1ll << a[i][j]) << ' ';
            cout << (i % 2 == 1 ? 0 : (i + j == 0 ? 0 : (1ll << (i + j - 1)))) << ' ';
        }
        cout << endl;
    }

    int q;
    cin >> q;

    while(q--) {
        li k;
        cin >> k;

        cout << 1 << ' ' << 1 << endl;
        int i = 0, j = 0;
        while(i < n - 1 || j < n - 1) {
            int ind = i + j;
            if(i % 2 == 0) {
                if(k & (1ll << ind)) {
                    j++;
                } else {
                    i++;
                }
            } else {
                if(k & (1ll << ind)) {
                    i++;
                } else {
                    j++;
                }
            }
            cout << i + 1 << ' ' << j + 1 << endl;
        }
    }

}