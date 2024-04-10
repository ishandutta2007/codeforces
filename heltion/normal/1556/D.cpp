#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int gor(int i, int j) {
    cout << "or " << i << " " << j << endl;
    int x;
    cin >> x;
    return x;
}
int gand(int i, int j) {
    cout << "and " << i << " " << j << endl;
    int x;
    cin >> x;
    return x;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int oAB = gor(1, 2), oBC = gor(2, 3), oAC = gor(1, 3);
    int aAB = gand(1, 2), aBC = gand(2, 3), aAC = gand(1, 3);
    int oo = oAB | oBC, aa = oAB & oAC;
    vector<int> v(n + 1);
    v[1] = (oo - oBC) | aAB | aAC;
    v[2] = oAB - v[1] + aAB;
    v[3] = oAC - v[1] + aAC;
    for (int i = 4; i <= n; i += 1) {
        int o = gor(1, i), a = gand(1, i);
        v[i] = o - v[1] + a;
    }
    //for (int i : v) cout << i << " ";
    sort(v.begin(), v.end());
    cout << "finish " << v[k] << endl;
    return 0;
}