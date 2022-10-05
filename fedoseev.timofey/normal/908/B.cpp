#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;

vector <vector <char>> mapp;
string seq;
int si, sj;
int n, m;

int good(int i, int j) {
    if (!((0 <= i && i < n) && (0 <= j && j < m))) return 0;
    if (mapp[i][j] == '#') return 0;
    if (mapp[i][j] == 'E') return 1;
    return 2;
}

bool check(vector <pair <int, int>> &turns) {
    int ti = si;
    int tj = sj;
    for (auto t : seq) {
        int num = t - '0';
        ti += turns[num].first;
        tj += turns[num].second;
        int res = good(ti, tj);
        if (res == 1) return true;
        else if (res == 0) return false;
    }
    return false;
}

int main() {
    cin >> n >> m;
    mapp.resize(n);
    for (int i = 0; i < n; ++i) mapp[i].resize(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mapp[i][j];
            if (mapp[i][j] == 'S') {
                si = i;
                sj = j;
            }
        }
    }
    cin >> seq;
    vector <pair <int, int>> turns(4);
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int h = 0; h < 4; ++h) {
                    set <int> ck;
                    ck.insert(i);
                    ck.insert(j);
                    ck.insert(k);
                    ck.insert(h);
                    if (ck.size() != 4) continue;
                    turns[i] = {-1, 0};
                    turns[j] = {1, 0};
                    turns[k] = {0, -1};
                    turns[h] = {0, 1};
                    if (check(turns)) {
                        ++ans;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}