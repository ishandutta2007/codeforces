#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

int get_number(char c) {
    if (c == 'A') return 0;
    else if (c == 'T') return 1;
    else if (c == 'G') return 2;
    else return 3;
}

const int N = 1e5 + 7;
const int Shift = 11;
const int Index_in_shift = 11;
const int Alpha = 4;

int f[Alpha][Shift][Index_in_shift][N];

void inc(int alpha, int shift, int index_in_shift, int ind, int delta) {
    for (int i = ind; i < N; i = i | (i + 1)) {
        f[alpha][shift][index_in_shift][i] += delta;
    }
}

int get(int alpha, int shift, int index_in_shift, int r) {
    int sum = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
        sum += f[alpha][shift][index_in_shift][i];
    }
    return sum;
}

int sum(int alpha, int shift, int index_in_shift, int l, int r) {
    return get(alpha, shift, index_in_shift, r) - get(alpha, shift, index_in_shift, l - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        int cur_alpha = get_number(s[i]);
        for (int shift = 1; shift <= 10; ++shift) {
            inc(cur_alpha, shift, i % shift, i + 1, 1);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            char c;
            int x;
            cin >> x >> c;
            --x;
            int cur_alpha = get_number(c);
            for (int shift = 1; shift <= 10; ++shift) {
                inc(cur_alpha, shift, x % shift, x + 1, 1);
            }
            cur_alpha = get_number(s[x]);
            for (int shift = 1; shift <= 10; ++shift) {
                inc(cur_alpha, shift, x % shift, x + 1, -1);
            }
            s[x] = c;
        }
        else {
            int l, r;
            string e;
            cin >> l >> r >> e;
            ll ans = 0;
            for (int i = 0; i < e.size(); ++i) {
                ans += sum(get_number(e[i]), e.size(), (i + l - 1) % e.size(), l, r);
            }
            cout << ans << endl;
        }
    }
}