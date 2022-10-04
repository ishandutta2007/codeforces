#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> mem = {
1,
1,
5,
1,
21,
1,
85,
73,
341,
89,
1365,
1,
5461,
4681,
21845,
1,
87381,
1,
349525,
299593,
1398101,
178481,
5592405,
1082401
};

const int N = (1 << 25) + 7;

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int ans[N];

void prec() {
    int cnt = 0;
    ans[2] = 3;
    int nxt = 4;
    for (int i = 2; i < N; ++i) {
        if (i + 1 == nxt) {
            ans[i] = mem[cnt];
            ++cnt;
        }
        else {
            if (i == nxt) nxt *= 2;
            ans[i] = nxt - 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> q;
    prec();
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}