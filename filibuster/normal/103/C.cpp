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

int main() {
    li n, k;
    int q;
    cin >> n >> k >> q;

    string s = "";
    for(int i = 0; i < q; i++) {
        li x;
        cin >> x;

        x--;

        if(k == 1) {
            s += (x == n - 1 ? 'X' : '.');
        } else if(k * 2 < n) {
            if(x <= n - k * 2)
                s += '.';
            else {
                if((n - 2 * k) % 2 == 1) {
                    s += ((n - x) % 2 == 0 || x == n - 1 ? 'X' : '.');
                } else {
                    s += ((n - x) % 2 == 0 ? '.' : 'X');
                }
            }
//            if(x == n - 1)
//                s += ((n - 2 * k) % 2 == 0 ? '.' : 'X');
//            else if(x == n - 2)
//                s += ((n - 2 * k) % 2 == 0 ? 'X' : '.');
//            else
//                s += ((n - x) % 2 == 0 ? '.' : 'X');
        } else {
            if(x < (n - k) * 2)
                s += (x % 2 == 0 ? '.' : 'X');
            else
                s += 'X';
        }
//        cout << s[s.size() - 1] << endl;
    }
    cout << s << endl;
}