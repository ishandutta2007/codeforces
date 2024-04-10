//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

/*
1
8 5
2 1 7 4
4 2

*/

//int d[N];
//vector<int> p;

li a[N];
li st[LOGN][N];
int max2[N];

li get(int l, int r) {
    int len = max2[r - l];

    return __gcd(st[len][l], st[len][r - (1 << len)]);
}

void solve() {
    int n;
    cin >> n;

//    vector<li> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }


    for(int i = 0; i < n - 1; i++)
        st[0][i] = abs(a[i + 1] - a[i]);

    for(int i = 1; i < LOGN; i++) {
        for(int j = 0; j + (1 << i) < n; j++)
            st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
    }



    int ans = 1;

    for(int i = 0; i < n - 1; i++) {
        int l = i, r = n;
        while(r - l > 1) {
            int m = (l + r) / 2;

            li res = get(i, m);
            if(res != 1)
                l = m;
            else
                r = m;
        }

        ans = max(ans, l - i + 1);
    }

    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    max2[1] = 0;
    for(int i = 2; i < N; i++) {
        max2[i] = max2[i / 2] + 1;
    }

//    for(int i = 2; i < N; i++) {
//        if(d[i] == 0) {
//            p.push_back(i);
//            d[i] = i;
//
//            if(i * 1ll * i < N)
//                for(int j = i * i; j < N; j += i)
//                    d[j] = i;
//        }
//    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();

}