#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;

/*
*/

//void solve() {
//
//}


bool isin(vector<int> a) {
    cout << "? " << a.size() << ' ';
    for(int x : a)
        cout << x << ' ';
    cout << endl;
    string res;
    cin >> res;

    return (res[0] == 'Y');
}

bool check(int x) {
    cout << "! " << x << endl;

    string res;
    cin >> res;

    if(res[1] == ')')
        exit(0);
    return false;
}

void solve2(vector<int> a1, vector<int> a2);

void solve(vector<int> a) {
    if(a.size() == 1) {
        check(a[0]);
        return;
    }

    int m = a.size() / 2;

    vector<int> a1(m), a2(a.size() - m);
    for(int i = 0; i < m; i++) {
        a1[i] = a[i];
    }

    for(int i = m; i < a.size(); i++) {
        a2[i - m] = a[i];
    }

    {
        bool rs1 = isin(a1);
        bool rs2 = isin(a1);

        if(rs1 == rs2) {
            if(rs1)
                solve(a1);
            else
                solve(a2);
            return;
        } else {
            if(rs2) {
                swap(a1, a2);
            }
        }
    }

    solve2(a1, a2);
}

void solve2(vector<int> a1, vector<int> a2) {
    if(a1.size() == 1 && a2.size() == 1) {
        check(a1[0]);
        check(a2[0]);
        assert(false);
        return;
    }

    int m1 = (a1.size() == 1 ? 1 : a1.size() * 2 / 3);

    vector<int> a11(m1), a12(a1.size() - m1);
    for(int i = 0; i < m1; i++) {
        a11[i] = a1[i];
    }

    for(int i = m1; i < a1.size(); i++) {
        a12[i - m1] = a1[i];
    }

    bool rs1 = isin(a11);
    if(rs1) {
        a1 = a11;
    } else {
        vector<int> b;
        for(int x : a12)
            b.push_back(x);
        for(int x : a2)
            b.push_back(x);
        solve(b);
        return;
    }

    solve2(a2, a1);
}

mt19937 rnd(time(0));

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1) {
        check(n);
        return 0;
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        a[i] = i + 1;

    for(int i = 0; i < n; i++)
        swap(a[i], a[rnd() % (i + 1)]);

    solve(a);

//    int t = 1;
//    cin >> t;
//
//    while(t--) {
//        solve();
//    }
}