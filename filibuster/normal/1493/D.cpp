#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;

/*
4 5
0 1
1 2
2 3
3 4

1 6
4 4
*/

int d[N];
vector<int> p;

int n;
int a[N];

map<int, int> mp[N];
int cnt[N];

int g = 1;

void recalc(int i) {
    while(cnt[i] == n) {
        g = g * 1ll * i % M;
        for(int j = 0; j < n; j++) {
            mp[j][i]--;
            if(mp[j][i] == 0)
                cnt[i]--;
        }
    }
}

void recalc() {
    for(auto i : p) {
        recalc(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < N; i++) {
//        cout << i << endl;
        if(d[i] == 0) {
            d[i] = i;
            p.push_back(i);
            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    d[j] = i;
        }
    }

    int q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while(x > 1) {
//            cout << x << ' ' << d[x] << endl;
            mp[i][d[x]]++;
            if(mp[i][d[x]] == 1)
                cnt[d[x]]++;
            x /= d[x];
        }
    }

    recalc();

    for(int i = 0; i < q; i++) {
        int j, x;
        cin >> j >> x;

        j--;
        while(x > 1) {
            mp[j][d[x]]++;
            if(mp[j][d[x]] == 1) {
                cnt[d[x]]++;
                recalc(d[x]);
            }
            x /= d[x];
        }

        cout << g << '\n';
    }
}