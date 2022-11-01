#include <algorithm>
#include <ctime>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 1;

mt19937 rnd(time(nullptr));

vector<int> dsu;
vector<int> val;

void Merge(int u, int v) {
    dsu[u] = dsu[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    vector<int> arr;
    vector<pair<pair<int, int>, int>> queries;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            arr.push_back(x);
        } else {
            int x, y;
            cin >> x >> y;
            queries.emplace_back(make_pair(x, y), arr.size());
        }
    }
    dsu.resize(MAX_N + 1);
    val.resize(MAX_N + 1);
    iota(dsu.begin(), dsu.end(), 0);
    iota(val.begin(), val.end(), 0);
    for (int i = (int) arr.size() - 1; i >= 0; --i) {
        while (!queries.empty() && queries.back().second - 1 >= i) {
            int x = queries.back().first.first;
            int y = queries.back().first.second;
            Merge(x, y);
            queries.pop_back();
        }
        arr[i] = val[dsu[arr[i]]];
    }
    for (int x : arr) {
        cout << x << ' ';
    }
    return 0;
}