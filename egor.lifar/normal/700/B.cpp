#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
 
 
using namespace std;
 

int n, k;
bool good[200001];
vector<int> v[200001];
int d[200001];
bool used[200001];
long long sum = 0;


void dfs(int u) {
    used[u] = 1;
    for (int i = 0; i < (int)v[u].size(); i++) {
        int h = v[u][i];
        if (!used[h]) {
            dfs(h);
            sum += min(d[h], 2 * k - d[h]);
            d[u] += d[h];
        }
    }
    d[u] += good[u];
}


int main() {
    cin >> n >> k;
    for (int i = 0; i < 2 * k; i++) {
        int a;
        scanf("%d", &a);
        a--;
        good[a] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0);
    cout << sum << endl;
    return 0;
}