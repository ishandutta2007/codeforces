    #include <bits/stdc++.h>
     
    using namespace std;
    #define ll long long
    #define pb push_back
    #define F first
    #define S second
    const int mod = 1e9 + 7, A = 1e3 + 2;
    int n, m;
    bool taken[52];
    vector<string> all(52);
    vector<pair<int, int>> jokers;
    vector<vector<string>> in, tmp;
    void input() {
     cin >> n >> m;
     in.resize(n, vector<string>(m));
     tmp.resize(n, vector<string>(m));
     for (int i = 0; i < n; i++) {
     for (int j = 0; j < m; j++)
     cin >> in[i][j];
     }
    }
    void pre() {
     string rank = "23456789TJQKA", type = "CDHS";
     int ptr = 0;
     for (int i = 0; i < 13; i++) {
     for (int j = 0; j < 4; j++, ptr++) {
     all[ptr].pb(rank[i]);
     all[ptr].pb(type[j]);
     }
     }
     for (int i = 0; i < n; i++) {
     for (int j = 0; j < m; j++) {
     tmp[i][j] = in[i][j];
     if (in[i][j] == "J1" || in[i][j] == "J2")
     jokers.pb({i, j});
     else {
     for (int ind = 0; ind < 52; ind++) {
     if (in[i][j] == all[ind])
     taken[ind] = 1;
     }
     }
     }
     }
    }
    bool validate(vector<vector<string>> &v, pair<int, int> &x1, pair<int, int> &x2) {
     vector<pair<int, int>> valid;
     for (int i = 0; i < n - 2; i++) {
     for (int j = 0; j < m - 2; j++) {
     set<char> ranks;
     for (int r = i; r < i + 3; r++) {
     for (int c = j; c < j + 3; c++)
     ranks.insert(v[r][c][0]);
     }
     if (ranks.size() == 9)
     valid.pb({i, j});
     }
     }
     if (valid.empty())
     return 0;
     pair<int, int> mni = {1e2, 0}, mnj = {0, 1e2};
     pair<int, int> mxi = {-1, 0}, mxj = {0, -1};
     for (auto x : valid) {
     if (mni.F > x.F) mni = x;
     if (mnj.S > x.S) mnj = x;
     if (mxi.F < x.F) mxi = x;
     if (mxj.S < x.S) mxj = x;
     }
     if (mxi.F - mni.F >= 3) {
     x1 = mxi, x2 = mni;
     return 1;
     }
     if (mxj.S - mnj.S >= 3) {
     x1 = mxj, x2 = mnj;
     return 1;
     }
     return 0;
    }
     
    void solved(pair<int, int> &p1, pair<int, int> &p2) {
     cout << "Solution exists.\n";
     if (jokers.size() == 0)
     cout << "There are no jokers.\n";
     if (jokers.size() == 1)
     cout << "Replace " << in[jokers[0].F][jokers[0].S] << " with " << tmp[jokers[0].F][jokers[0].S] << ".\n";
     if (jokers.size() == 2) {
     if (in[jokers[0].F][jokers[0].S] == "J2") {
     swap(in[jokers[0].F][jokers[0].S], in[jokers[1].F][jokers[1].S]);
     swap(tmp[jokers[0].F][jokers[0].S], tmp[jokers[1].F][jokers[1].S]);
     }
     cout << "Replace " << in[jokers[0].F][jokers[0].S] << " with " << tmp[jokers[0].F][jokers[0].S]
     << " and " << in[jokers[1].F][jokers[1].S] << " with " << tmp[jokers[1].F][jokers[1].S] << ".\n";
     }
     cout << "Put the first square to (" << p1.F + 1 << ", " << p1.S + 1 << ").\n";
     cout << "Put the second square to (" << p2.F + 1 << ", " << p2.S + 1 << ").\n";
     exit(0);
    }
    void generate(int ind) {
     if (ind == (int)jokers.size()) {
     pair<int , int> p1, p2;
     if (validate(tmp, p1, p2))
     solved(p1, p2);
     return;
     }
     for (int i = 0; i < 52; i++) {
     if (!taken[i]) {
     taken[i] = 1;
     tmp[jokers[ind].F][jokers[ind].S] = all[i];
     generate(ind + 1);
     taken[i] = 0;
     }
     }
    }
    int main() {
     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     input();
     pre();
     generate(0);
     cout << "No solution.\n";
     return 0;
     }