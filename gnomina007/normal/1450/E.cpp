#include <random>
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#include <bitset>
#include<queue>
#include<ctime>
#include<unordered_map>

using namespace std;


using ll = long long;
using ull = unsigned long long;

using ld = long double;

const int mod = 998244353;
//const int mod = 1e9 + 7;

int sum(int a, int b) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }
    return c;
}

int dif(int a, int b) {
    int c = a - b;
    if (c < 0) {
        c += mod;
    }
    return c;
}

int mlt(int a, int b) {
    ll c = a * 1LL * b;
    return c % mod;
}

int ibit(int n, int i) {
    return ((n >> i) & 1);
}


void outp2(vector<vector<int>> &ou, string s = " ") {
    cerr << s << endl;
    for (int i = 0; i < ou.size(); i++) {
        for (int j = 0; j < ou[i].size(); j++) {
            cerr << ou[i][j] << ' ';
        }
        cerr << '\n';
    }
}

int bp(int x, int y) {
    if (y == 0) {
        return 1;
    }
    int a = 0;
    if (!(y % 2)) {
        a = bp(x, y / 2);
    }
    return (y % 2) ? mlt(bp(x, y - 1), x) : mlt(a, a);
}

int obr(int x) {
    return bp(x, mod - 2);
}

const int maxn = 2e5 + 2;
int fact[maxn], ofact[maxn];

void prec() {
    fact[0] = 1;
    ofact[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = mlt(fact[i - 1], i);
    }
    //cerr << "sdsds" << endl;
    ofact[maxn - 1] = obr(fact[maxn - 1]);
    for (int i = maxn - 2; i > 0; i--) {
        ofact[i] = mlt(ofact[i + 1], i + 1);
    }
}

int c(int a, int b) {
    return ((a <= b) && (a >= 0)) ? mlt(fact[b], mlt(ofact[a], ofact[b - a])) : 0;
}

void dfs(vector<vector<int>> &matr, vector<int> &colors, int v, int c) {
    colors[v] = c;
    for (int i = 0; i < matr[v].size(); i++) {
        if (matr[v][i] != 1e7 && colors[i] == -1)
            dfs(matr, colors, i, c ^ 1);
    }
}

void solve(istream &cin = std::cin, ostream &cout = std::cout) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matr(n, vector<int>(n, 1e7));
    vector<int> colors(n, -1);
    //   -    
    for (int i = 0; i < m; i++) {
        int t, x, y;
        cin >> x >> y >> t;
        x--;
        y--;
        if (t == 0) {
            matr[x][y] = 1;
            matr[y][x] = 1;
        } else {
            matr[x][y] = -1;
            matr[y][x] = 1;
        }
    }
    dfs(matr, colors, 0, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (matr[i][j] != 1e7 && (colors[i] == colors[j])) {
              //  cout << i << ' ' << j << endl;
                cout << "NO";
                return;
            }
        }
    vector<vector<int>> dists = matr;
    for (int i = 0; i < n; i++)
        dists[i][i] = 0;
    for (int h = 0; h < n; h++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dists[i][j] = min(dists[i][j], dists[i][h] + dists[h][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (dists[i][i] < 0) {
            cout << "NO" << '\n';
            return;
        }
    int ci = 0, cj = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dists[i][j] > dists[ci][cj]) {
                ci = i;
                cj = j;
            }
        }
    }
    cout << "YES" << '\n';
    cout << dists[ci][cj] << '\n';
    for (int i = 0; i < n; i++)
        cout << dists[ci][cj] - dists[ci][i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    auto st = clock();

        ifstream fin("../input.txt");
        do
        {
            solve(fin);

            cout << "===" << endl;

            string str;
            while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
        } while (fin);

        cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
    solve();
#endif

    return 0;
}