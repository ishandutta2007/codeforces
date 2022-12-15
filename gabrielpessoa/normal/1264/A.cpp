#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int ms = 2e6+5;

int a[ms];

main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int last = a[0];
        int cnt = 1;
        vi v;
        for(int i = 1; i < n; i++) {
            if(a[i] == last) cnt++;
            else {
                v.push_back(cnt);
                last = a[i];
                cnt = 1;
            }
        }
        v.push_back(cnt);
        vi newv;
        int cur = 0;
        int g = 0, s = 0, b = 0;
        for(int a : v) {
            if(cur + a + cur + a > n) break;
            cur += a;
            if(g == 0) g += a;
            else if(g >= s) s += a;
            else b += a;
        }
        if(g > 0 && s > 0 && b > 0 && s > g && b > g) {
            cout << g << ' ' << s << ' ' << b << '\n';
        } else {
            cout << "0 0 0" << '\n';
        }
    }
}