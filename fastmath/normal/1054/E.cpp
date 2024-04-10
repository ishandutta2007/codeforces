#include <bits/stdc++.h>

using namespace std;

const int MAXN = 307;

int n, m;
deque <bool> a[MAXN][MAXN], b[MAXN][MAXN];
void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string tmp;
            cin >> tmp;
            for (char e : tmp) a[i][j].push_back(e == '1');
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string tmp;
            cin >> tmp;
            reverse(tmp.begin(), tmp.end());
            for (char e : tmp) b[i][j].push_back(e == '1');
        }
    }   
}

struct Op { int x1, y1, x2, y2; };

vector <Op> solve(deque <bool> a[MAXN][MAXN]) {
    vector <Op> ans;
    for (int i = 1; i < m; ++i) {
        while (!a[0][i].empty()) {
            ans.push_back({0, i, 0, 0});
            a[0][0].push_front(a[0][i].back());
            a[0][i].pop_back();
        }   
    }
    for (int i = 1; i < n; ++i) {
        while (!a[i][0].empty()) {
            ans.push_back({i, 0, 0, 0});
            a[0][0].push_front(a[i][0].back());
            a[i][0].pop_back();
        }
    }
    while (!a[0][0].empty()) {
        if (!a[0][0].back()) {
            ans.push_back({0, 0, 0, 1});
            a[0][1].push_front(0);
            a[0][0].pop_back();
        }
        else {
            ans.push_back({0, 0, 1, 0});
            a[1][0].push_front(1);
            a[0][0].pop_back();
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            while (!a[i][j].empty()) {
                if (!a[i][j].back()) {
                    ans.push_back({i, j, 0, j});
                    a[i][j].pop_back();
                    a[0][j].push_front(0);
                }
                else {
                    ans.push_back({i, j, i, 0});
                    a[i][j].pop_back();
                    a[i][0].push_front(1);
                }
            }
        }
    }
    for (int i = 2; i < m; ++i) {
        while (!a[0][i].empty()) {
            ans.push_back({0, i, 0, 1});
            a[0][1].push_front(0);
            a[0][i].pop_back();
        }
    }
    for (int i = 2; i < n; ++i) {
        while (!a[i][0].empty()) {
            ans.push_back({i, 0, 1, 0});
            a[1][0].push_front(1);
            a[i][0].pop_back();
        }
    }
    return ans;
}

void print(deque <bool> a[MAXN][MAXN], vector <Op> t) {
    for (auto e : t) {
        a[e.x2][e.y2].push_front(a[e.x1][e.y1].back());
        a[e.x1][e.y1].pop_back();
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (auto e : a[i][j]) cout << e;
            cout << ' ';
        }
        cout << '\n';
    }   
}

void print() {
    auto tmp1 = solve(a);
    auto tmp2 = solve(b);    
    cout << tmp1.size() + tmp2.size() << '\n';                                                                              
    for (auto e : tmp1) cout << e.x1 + 1 << ' ' << e.y1 + 1 << ' ' << e.x2 + 1 << ' ' << e.y2 + 1 << '\n';
    cout << '\n';
    reverse(tmp2.begin(), tmp2.end());
    for (auto e : tmp2) cout << e.x2 + 1 << ' ' << e.y2 + 1 << ' ' << e.x1 + 1 << ' ' << e.y1 + 1 << '\n';
}   

signed main() {
    //freopen("input.txt", "r", stdin);    

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    print();

    return 0;;
}