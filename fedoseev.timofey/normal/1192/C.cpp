#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int L = 11;
 
vector <string> S[L];
 
const int md = 998244353;
 
void add(int &a, int b) {
    a += b;
    if (a >= md) {
        a -= md;
    }
}
 
int mul(int a, int b) {
    return ((ll)a * b) % md;
}
 
int ans = 0;
 
const int N = 65;
 
int dp1[N][N], dp2[N][N][N], dp3[N][N][N], dp4[N][N][N][N];
 
void clear() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp1[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                dp2[i][j][k] = dp3[i][j][k] = 0;
                for (int t = 0; t < N; ++t) {
                    dp4[i][j][k][t] = 0;
                }
            }
        }
    }
}
 
void solve(const vector <string> &a) {
    clear();
    vector <char> dif;
    for (string s : a) {
        dif.push_back(s.front());
        dif.push_back(s.back());
    }
    sort(dif.begin(), dif.end());
    dif.resize(unique(dif.begin(), dif.end()) - dif.begin());
    int cnt = dif.size();
    for (string s : a) {
        int fr = lower_bound(dif.begin(), dif.end(), s.front()) - dif.begin();
        int sc = lower_bound(dif.begin(), dif.end(), s.back()) - dif.begin();
        ++dp1[fr][sc];
    }
 
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            for (int k = 0; k < cnt; ++k) {
                add(dp2[i][j][k], mul(dp1[i][j], dp1[j][k]));
            }
        }
    }
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            for (int k = 0; k < cnt; ++k) {
                for (int t = 0; t < cnt; ++t) {
                    add(dp3[i][k][t], mul(dp2[i][j][k], dp1[j][t]));
                }
            }
        }
    }
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            for (int k = 0; k < cnt; ++k) {
                for (int t = 0; t < cnt; ++t) {
                    if (i != j && i != k && i != t && j != k && j != t && k != t) continue;
                    add(ans, mul(dp3[i][j][k], mul(dp3[i][j][t], mul(dp3[i][k][t], dp3[j][k][t]))));
                }
            }
        }
    }
    for (int i = 0; i < cnt; ++i) {
        for (int j = i + 1; j < cnt; ++j) {
            for (int k = j + 1; k < cnt; ++k) {
                for (int t = k + 1; t < cnt; ++t) {
                    add(ans, mul(24, mul(dp3[i][j][k], mul(dp3[i][j][t], mul(dp3[i][k][t], dp3[j][k][t])))));
                }
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        S[(int)s.size()].push_back(s);
        reverse(s.begin(), s.end());
        S[(int)s.size()].push_back(s);
    }
    for (int i = 3; i < L; ++i) {
        sort(S[i].begin(), S[i].end());
        S[i].resize(unique(S[i].begin(), S[i].end()) - S[i].begin());
        if (!S[i].empty()) solve(S[i]);
    }
    cout << ans << '\n';
}