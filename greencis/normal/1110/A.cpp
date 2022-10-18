#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    int b, k, x;
    cin >> b >> k;
    int cur = 0;
    for (int i = 0; i < k; ++i) {
        cin >> x;
        cur = cur * b + x;
        cur %= 2;
    }
    cout << (cur ? "odd" : "even");
}