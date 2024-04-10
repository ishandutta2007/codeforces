#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read);

#define int li

ostream& dbgPrintContainer(ostream& os, const auto& container, const char* brackets = "[]") {
    os << brackets[0] << " ";
    for (auto& elem : container) {
        os << elem << " ";
    }
    os << brackets[1];
    return os;
}

ostream& operator<<(ostream& os, const pair<auto, auto>& p) {
    return os << "(" << p.first << " " << p.second << ")";
}

ostream& operator<<(ostream& os, const vector<auto>& v) { return dbgPrintContainer(os, v, "[]"); }
ostream& operator<<(ostream& os, const set<auto>& v) { return dbgPrintContainer(os, v, "{}"); }
ostream& operator<<(ostream& os, const map<auto, auto>& v) { return dbgPrintContainer(os, v, "{}"); }

signed main() {
    auto t0 = clock();
    cout << fixed << setprecision(12);

#ifdef YA
    //assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    solve(true);

#if 0
    while (true) {
        solve(false);
    }
#endif

#ifdef YA
    cerr << endl << endl << fixed << setprecision(5) << (clock() - t0) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

int n;

bool can(int i0, int j0, int i1, int j1) {
    assert(i0 >= 0 && i0 < n);
    assert(j0 >= 0 && j0 < n);
    assert(i1 >= 0 && i1 < n);
    assert(j1 >= 0 && j1 < n);
    assert((abs(i0 - i1) + abs(j0 - j1)) >= n - 1);
    assert(i0 <= i1);
    assert(j0 <= j1);

    ++i0; ++j0; ++i1; ++j1;

    cout << "? " << i0 << " " << j0 << " " << i1 << " " << j1 << endl;
    string ans;
    cin >> ans;
    assert(ans == "YES" || ans == "NO");
    return ans == "YES";
}

void solve(bool __attribute__((unused)) read) {
    cin >> n;

    int cur_i = 0, cur_j = 0;

    string ans = "";

    for (int i = 0; i < n - 1; ++i) {
        if (can(cur_i, cur_j + 1, n - 1, n - 1)) {
            ++cur_j;
            ans += "R";
        } else {
            ++cur_i;
            ans += "D";
        }
    }

    assert(cur_i + cur_j == n - 1);
    pair<int, int> dst1(cur_i, cur_j);

    cur_i = n - 1, cur_j = n - 1;

    string rans = "";

    for (int i = 0; i < n - 1; ++i) {
        if (can(0, 0, cur_i - 1, cur_j)) {
            --cur_i;
            rans += "D";
        } else {
            --cur_j;
            rans += "R";
        }
    }

    assert(cur_i + cur_j == n - 1);
    pair<int, int> dst2(cur_i, cur_j);
    assert(dst1 == dst2);

    reverse(all(rans));
    ans += rans;

    cout << "! " << ans << endl;
}