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
using namespace std::chrono;

const int MAXN = 100000;

int v[1 + MAXN];
struct Group {
    int val;
    int freq;
    int pos;

    bool operator < (const Group &other) const {
        return freq < other.freq;
    }
};
Group vn[1 + MAXN], wn[1 + MAXN];
int where[1 + MAXN], cnt[1 + MAXN], sum[1 + MAXN];

void update(int freq, int pos, int sgn, int g) {
    for (; pos <= g; pos += (pos & -pos)) {
        cnt[pos] += sgn;
        sum[pos] += freq * sgn;
    }
}

int query(int k, int g) {
    int step, ans = 0;
    for (step = 1; step <= g; step *= 2);
    for (int i = 0; step != 0; step /= 2) {
        if (i + step <= g && k >= sum[i + step]) {
            i += step;
            k -= sum[i];
            ans += cnt[i];
        }
    }
    return ans;
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        map<int, int> f;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            f[v[i]]++;
        }
        int g = 0;
        for (auto it : f) {
            g++;
            vn[g] = wn[g] = {it.first, it.second, g};
        }
        for (int i = 1; i <= g; i++) {
            cnt[i] = sum[i] = 0;
        }
        sort(vn + 1, vn + g + 1);
        for (int i = 1; i <= g; i++) {
            where[vn[i].pos] = i;
            update(vn[i].freq, i, 1, g);
        }
        int answer = g - query(k, g);  // mex == 0
        for (int mex = 1, holes = 0, total = n, i = 1; mex <= n; mex++) {
            if (i <= g && wn[i].val == mex - 1) {
                total -= wn[i].freq;
                update(wn[i].freq, where[i], -1, g);
                i++;
            } else {
                holes++;
            }
            if (holes > k) {
                break;
            }
            if (holes >= total) {
                answer = 0;
                break;
            }
            answer = min(answer, (g - i + 1) - query(k, g));
        }

        cout << answer << "\n";
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}