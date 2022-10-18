//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        string s;
        cin >> s;
        int index = min_element(all(s)) - s.begin();
        char a = s[index];
        s.erase(index, 1);
        cout << a << ' ' << s << '\n';
    }
}