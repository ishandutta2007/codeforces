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

    int n;
    cin >> n;

    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        a |= x;
    }

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        b |= x;
    }

    cout << a + b << endl;
}