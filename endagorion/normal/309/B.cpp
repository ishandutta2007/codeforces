#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int tr[20][1000001];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, R, C;
    cin >> N >> R >> C;
    vector<string> s(N);
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }
    int r = 0;
    int S = -1;
    for (int i = 0; i < N; ++i) {
        if (r < i) {
            r = i;
            S = -1;
        }
        while (r < N && S + 1 + s[r].size() <= C) {
            S += 1 + s[r].size();
            ++r;
        }
        tr[0][i] = r;
        S -= 1 + (int)s[i].size();
    }
    tr[0][N] = N;
    for (int j = 1; j < 20; ++j) {
        for (int i = 0; i <= N; ++i) {
            if (tr[j - 1][i] == N) {
                tr[j][i] = N;
            } else {
                tr[j][i] = tr[j - 1][tr[j - 1][i]];
            }
        }
    }

    int b = -1;
    int c = 0;
    for (int i = 0; i < N; ++i) {
        int t = i;
        for (int j = 19; j >= 0; --j) {
            if (R & (1 << j)) {
                t = tr[j][t];
            }
        }
        if (t - i > c) {
            b = i;
            c = t - i;
        }
    }

    if (b == -1) {
        return 0;
    }

    for (int i = 0; i < R; ++i) {
        int e = tr[0][b];
        for (int j = b; j < e; ++j) {
            if (j != b) {
                cout << ' ';
            }
            cout << s[j];
        }
        cout << '\n';
        b = e;
    }

    return 0;
}