#include <bits/stdc++.h>
using namespace std;
 
const int N = 18;
string s;
int a[1<<N], v[1<<N], tmp[1<<N];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n >> s;
    assert(s.size() == (1<<n));
 
    iota(a, a+(1<<n), 0);
    sort(a, a+(1<<n), [&](int i, int j){ return s[i] < s[j]; });
    for (int i = 1; i < 1<<n; i++)
        v[a[i]] = v[a[i-1]] + (s[a[i]] != s[a[i-1]] ? 1 : 0);
 
    for (int k = 1; k < 1<<n; k <<= 1) {
        auto cmp = [&](int i, int j){
            return v[i] == v[j] ? v[i^k] < v[j^k] : v[i] < v[j];
        };
        sort(a, a+(1<<n), cmp);
        for (int i = 1; i < 1<<n; i++)
            tmp[a[i]] = tmp[a[i-1]] + (cmp(a[i-1], a[i]) ? 1 : 0);
        copy(tmp, tmp+(1<<n), v);
    }
 
    for (int i = 0; i < 1<<n; i++)
        cout << s[i^a[0]];
    cout << "\n";
}