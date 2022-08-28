#include <bits/stdc++.h>
using namespace std;
int check(int x) {
    stringstream d;
    char s[20];
    d << x;
    d >> s;
    int cnt = strlen(s);
    sort(s, s + cnt);
    if(unique(s, s + cnt) - s != cnt) return 0;
    return 1;
}
int main() {
    int l, r;
    cin >> l >> r;
    for(int i = l; i <= r; i++) {
        if(check(i)) return cout << i << endl, 0;
    }
    return cout << -1 << endl, 0;
}