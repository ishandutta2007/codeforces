#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


const int Mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 200500;
vector<int> e[MAXN];
int a[MAXN], b[MAXN];
long long W[MAXN];
int used[MAXN];
long long path[MAXN];
const int MAXM = 62;
vector<long long> q;
vector<long long> paths;


void dfs(int x, int p) {
    used[x] = true;
    paths.push_back(path[x]);
    for (int e : e[x]) {
        int y = a[e] ^ b[e] ^ x;
        if (y == p) {
            continue;
        }
        if (!used[y]) {
            path[y] = path[x] ^ W[e];
            dfs(y, x);
        } else {
            q.push_back(path[x] ^ path[y] ^ W[e]);
        }
    }
}


int cnt[MAXM][2];
int steps[MAXN];
bool has1[MAXM];


int getAns(int x) {
    q.clear();
    paths.clear();
    dfs(x, -1);
    int uk = 0;
    for (int j = 0; j < MAXM; j++) {
        int p = -1;
        for (int i = uk; i < (int)q.size(); i++) {
            if ((q[i] >> j) & 1LL) {
                p = i;
                break;
            }
        }
        if (p == -1) {
            continue;
        }
        swap(q[p], q[uk]);
        for (int i = uk + 1; i < (int)q.size(); i++) {
            if ((q[i] >> j) & 1LL) {
                q[i] ^= q[uk];
            }
        }
        uk++;
    }
    q.resize(uk);
    for (int i = 0; i < MAXM; i++) {
        has1[i] = 0;
        for (long long p : q) {
            has1[i] |= ((p >> i) & 1LL);
        }
    }
    memset(cnt, 0, sizeof(cnt));
    int ans = 0;
    for (long long p : paths) {
        for (int j = 0; j < MAXM; j++) {
            int ot = (p >> j) & 1LL;
            for (int gt = 0; gt < 2; gt++) {
                int add = has1[j] ? steps[(int)q.size() - 1] : ((gt + ot) & 1) ? steps[(int)q.size()] : 0;
                add = 1LL * add * steps[j] % Mod;
                ans = (1LL * cnt[j][gt] * add + ans) % Mod;
            }
        }
        for (int j = 0; j < MAXM; j++) {
            cnt[j][(p >> j) & 1LL]++;
        }
    }
    return ans;
}


int n, m;


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &a[i], &b[i], &W[i]);
        a[i]--;
        b[i]--;
        e[a[i]].push_back(i);
        e[b[i]].push_back(i);
    }
    int ans = 0;
    steps[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        steps[i] = steps[i - 1] * 2;
        if (steps[i] >= Mod) {
            steps[i] -= Mod;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            ans = (ans + getAns(i)) % Mod;
        }
    }
    printf("%d\n", ans);
    return 0;
}