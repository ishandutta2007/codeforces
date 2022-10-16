#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;

const int MAXC = 100000;

vector<int> x[1 + MAXC], y[1 + MAXC];

long long getCnt(vector<int> &v) {
    sort(v.begin(), v.end());
    long long suff = 0;
    for (auto it : v) {
        suff += it;
    }
    long long pref = 0, ans = 0;
    for (int i = 0; i < v.size(); i++) {
        int it = v[i];
        suff -= it;
        ans += 1LL * it * i - pref + suff - 1LL * it * (v.size() - i - 1);
        pref += it;
    }
    return ans / 2;
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int c;
            cin >> c;
            x[c].push_back(i);
            y[c].push_back(j);
        }
    }
    long long ans = 0;
    for (int c = 1; c <= MAXC; c++) {
        ans += getCnt(x[c]);
        ans += getCnt(y[c]);
    }
    cout << ans << "\n";
    return 0;
}