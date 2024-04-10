#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

vector <int> a;

vector <int> ans;

vector <int> rec(vector <int> a, int itr = 0) {
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    if (itr == 22) {
        return vector <int>(22);
    }
    if (a.empty()) {
        return vector <int>();
    }
    bool ok = 1;
    for (auto &t : a) {
        ok &= (t % 2 == 0);
    }
    if (ok) {
        vector <int> res;
        for (auto &t : a) {
            if (t / 2) res.push_back(t / 2);
        }
        return rec(res, itr + 1);
    }
    else {
        vector <int> res(100);
        for (int v : {-1, 1}) {
            vector <int> tmp;
            for (auto &t : a) {
                if (t % 2 == 0) {
                    if (t / 2) {
                        tmp.push_back(t / 2);
                    }
                }
                else {
                    if ((t - v) / 2) {
                        tmp.push_back((t - v) / 2);
                    }
                }
            }
            vector <int> cur = rec(tmp, itr + 1);
            cur.push_back(v * (1 << itr));
            if (cur.size() < res.size()) {
                res = cur;
            }
        }
        return res;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> ans = rec(a, 0);
    cout << ans.size() << '\n';
    for (auto t : ans) {
        cout << t << ' ';
    }
}