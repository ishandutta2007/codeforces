#include <bits/stdc++.h>

using namespace std;
   
#define int long long

const int MAXN = 20;

int c[MAXN][MAXN];

void precalc() {
    for (int i = 0; i < MAXN; ++i) {
        c[i][0] = 1;
    }
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j < MAXN; ++j) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

int get1(int len) {
    int ans = 0;
    for (int i = 0; i <= 2; ++i) {
        int add = 9 * c[len - 1][i];
        for (int j = 0; j < i; ++j) add *= 9;
        ans += add;
    }
    return ans;
}

int get2(int len, int have) {
    int ans = 0;
    for (int i = 0; i <= 3 - have; ++i) {
        int add = c[len][i];
        for (int j = 0; j < i; ++j) add *= 9;
        ans += add;
    }
    return ans;
}

int get(int n) {    
    string s = to_string(n);
    int ans = 0;

    int len = s.size();
    for (int i = 1; i < len; ++i) {
        ans += get1(i);
    }

    for (int f = 1; f < s[0] - '0'; ++f) {
        ans += get2(len - 1, 1);    
    }

    int cnt = 1;
    for (int i = 1; i < len; ++i) {
        for (int j = 0; j < s[i] - '0'; ++j) {
            ans += get2(len - i - 1, cnt + (bool)j);
        }
        cnt += (bool)(s[i] - '0');
    }

    return ans;
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int l, r;
        cin >> l >> r;
        cout << get(r + 1) - get(l) << '\n';
    }   

    return 0;
}