#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 111111;
const int INF = 1e9 * 2 + 7;
int n, l, r, ql, qr, s[N], w[N];


int Calc(int l, int r){
    if (l == r) return 0;
    if (l > r) return (l - r - 1) * ql;
    else return (r - l - 1) * qr;
}
int main(){
    while (cin >> n >> l >> r >> ql >> qr){
        for (int i = 1; i <= n; i++){
            cin >> w[i];
            s[i] = s[i - 1] + w[i];
            //ans += w[i];
        }
        int ans = INF;
        for (int i = 0; i <= n; i++)
            ans = min(ans, s[i] * l + (s[n] - s[i]) * r + Calc(i, n - i));
        cout << ans << endl;
    }
}