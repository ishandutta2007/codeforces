#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 4000 + 13;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);


    vector<int> a(6);
    int ans= 0;
    for(int i = 0; i < 6; i++) {
        cin >> a[i];
//        ans += a[i] * a[i];
    }

    ans += (a[0] + a[1]) * (a[2] + a[1]) - a[1] * a[1];
    ans += (a[3] + a[4]) * (a[5] + a[4]) - a[4] * a[4];

//    int d = abs(a[0] - a[1]);
//    ans -= d * d * 2;
    cout << ans;


}