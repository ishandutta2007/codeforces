#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>


using namespace std;


const int MaxN = 1010;
pair<long long, long long> a[10];
pair<long long, long long> v[MaxN];
bool ans[MaxN];
int used[MaxN];
int r[10];
int num = 0;
vector<int> g[10][MaxN];


bool operator <(pair<long long, long long> a, pair<long long, long long> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}


pair<long long, long long> operator -(pair<long long, long long> a, pair<long long, long long> b) {
    a.first -= b.first;
    a.second -= b.second;
    return a;
}


long long operator *(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first * b.second - a.second * b.first;
}


long long Dist(pair<long long, long long> a) {
    return a.first * a.first + a.second * a.second;
}


pair<long long, long long> gg;


bool cmp(int a, int b) {
    return Dist(v[a] - gg) < Dist(v[b] - gg);
}


vector<int> f;
int k, n;


bool res(int pos, int d) {
    r[f[pos]] = num;
    if ((int)g[f[pos]][d].size() >= k) {
        return false;
    }
    int h = 0;
    for (int i = 0; i < (int)g[f[pos]][d].size(); i++) {
        if (used[g[f[pos]][d][i]] != num) {
            while (h < k && r[f[h]] == num) {
                h++;
            }
            if (h == k) {
                return false;
            }
            if (!res(h, g[f[pos]][d][i])) {
                return false;
            }
        }
    }
    used[d] = num;
    return true;
}


int main() {
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        scanf("%I64d %I64d", &a[i].first, &a[i].second);
    }
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d", &v[i].first, &v[i].second);
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t < n; t++) {
                if (t != j && (a[i] - v[j]) * (a[i] - v[t]) == 0 && ((a[i] < v[t] && v[t] < v[j]) || (v[j] < v[t] && v[t] < a[i]))) {
                    g[i][j].push_back(t);
                }
                if ((int)g[i][j].size() >= k) {
                    break;
                }
            }
            gg = a[i];
            sort(g[i][j].begin(), g[i][j].end(), cmp);
        }
    }
    for (int i = 0; i < k; i++) {
        f.push_back(i);
    }
    while (true) {
        for (int i = 0; i < n; i++) {
            num++;
            res(0, i);
            if (used[i] == num) {
                ans[i] = true;
            }
        }
        if (!next_permutation(f.begin(), f.end())) {
            break;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}