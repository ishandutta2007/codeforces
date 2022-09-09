#include <bits/stdc++.h>
using namespace std;
using LL = long long;
char query1(int i) {
    cout << "? 1 " << i << " " << endl;
    char c;
    cin >> c;
    return c;
}
int query2(int l, int r) {
    cout << "? 2 " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s(n + 1, '0');
    vector<int> v;
    for (int i = 1, c = 0; i <= n; i += 1) {
        int L = -1, R = (int)v.size() - 1;
        while (L < R) {
            int M = (L + R + 1) / 2;
            if (query2(v[M], i) == (int)v.size() - M) L = M;
            else R = M - 1;
        }
        if (L == -1) {
            v.push_back(i);
            s[i] = query1(i);
        }
        else {
            s[i] = s[v[L]];
            v[L] = i;
            ranges::sort(v);
        }
    }
    cout << "! " << s.c_str() + 1 << endl;
    return 0;
}