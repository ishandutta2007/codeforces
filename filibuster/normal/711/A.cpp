#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*

*/


//int s[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool fl = false;
    for(int i = 0; i < n; i++) {
        if(a[i][0] == a[i][1] && a[i][0] != 'X') {
            a[i][0] = a[i][1] = '+';
            fl = true;
            break;
        }
        if(a[i][3] == a[i][4] && a[i][3] != 'X') {
            a[i][3] = a[i][4] = '+';
            fl = true;
            break;
        }

    }

    if(!fl) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for(auto x : a)
            cout << x << endl;
    }
}