#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> p(50 + 1);
    for(int& x : a) cin >> x;
    for(int i = n - 1; i >= 0; i -= 1) p[a[i]] = i;
    for(int i = 0, t; i < q; i += 1){
        cin >> t;
        cout << p[t] + 1 << " ";
        for(int j = 1; j <= 50; j += 1) if(j != t and p[j] < p[t]) p[j] += 1;
        p[t] = 0;
    }
    return 0;
}