#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define MN 2000000
#define INF 1000000000
using namespace std;

/*
Observation1:
 take differential, then an operation turns into +1, -1 at two positions with distance k
Observation2: 
 get the gcd d=(n,k), then divide into independent subsequences.
 reorder each subsequences by a[x], a[x+k], a[x+2k], ..., a[x+(n/d-1)k]
 One operation is imposed on (cyclically) consecutive pairs, just like moving objects
Observation3:
 By determine the amount to move from first to second, then we now the whole operation scheme
 An extra requirement: the first element is equal to 0
 With a DP this takes O(nm^2) time -> d subsequences, each contributing m elements
Observation4:
 Contribution of each element is like a abs function \/ with period m, with minimum at some point
 Each subsequence -> sum of this function
 Only check the maximum and minimum of abs function! Reduce contribution of one subsequence to O(n/d) elements
Final Sol:
 Divide and Conquer
 You never want to merge two dp array. Better just add in single elements.
*/

int n, m, nd, D, K, fe, a[MN + 5], b[MN + 5], ans = INF, F[MN + 5], G[MN + 5];
bool c[MN + 5];
vector<pair<int, int> > v[MN + 5], V[MN + 5];
inline int gcd(int x, int y) { return y ? gcd(y, x % y) : x;}
inline int next(int x, int y) { return (x += y) > n ? x - n : x; }
inline int normalize (int x) { return ((x % m) + m) % m; }
inline int m_cost(int x) { return min(x, m - x); }
inline int opposite(int x) { return x == 0 ? 0 : m - x; }
inline void T(int &x, int y) { y < x ? x = y : 0; }

void ins(vector<int> &f, int id) {
    for (int i = 0; i < m; ++i) F[i] = INF, G[i] = f[i];
    for (int i = 0; i < v[id].size(); ++i) {
        int con = v[id][i].first, cost = v[id][i].second;
        for (int j = 0; j < m; ++j) {
            T(F[con], G[j] + cost);
            if (++con >= m) con -= m;
        }
    }
    for (int i = 0; i < m; ++i) f[i] = F[i];
}

void Solve(int l, int r, vector<int> &f) {
    if (l == r) {
        for (int i = 0; i < V[l].size(); ++i) {
            ans = min(ans, V[l][i].second + f[opposite(V[l][i].first)]);
        }
        return;
    }
    int mid = l + r >> 1;
    vector<int> fr = f;
    for (int i = l; i <= r; ++i) {
        ins(i <= mid ? fr : f, i);
    }
    Solve(l, mid, f);
    Solve(mid + 1, r, fr);
}

int main() {
    scanf("%d%d%d", &n, &m, &K); D = gcd(n, K); nd = n / D;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    if (K == 1) {
        int res = 0;
        for (int i = 1; i <= n; ++i) res += m_cost(a[i]);
        printf("%d", res);
        return 0;
    }
    fe = a[1]; int le = a[n];
    for (int i = n; i; --i) {
        a[i] = a[i] - a[i - 1];
    }
    a[1] = a[1] - le;
    for (int i = 1; i <= D; ++i) {
        int j = i, k = 0;
        do {
            b[++k] = a[j];
            c[k] = j == 1 || (j > n - K + 1);
            j = next(j, K);
        } while (j != i);
        int cost, special, contribution, val;
        for (j = 0; j < m; ++j) {   
            b[nd] -= j;
            cost = m_cost(j); contribution = (i > 1 ? -j : 0); special = 0; val = j;
            for (k = 1; k < nd; ++k) {
                val = normalize(val + b[k]);
                if (val == 0 || val == m / 2) special = 1;
                if (c[k]) contribution -= val;
                cost += m_cost(val);
                // printf("%d %d %d c = %d b[k]=%d val become %d cost = %d\n", i, j, k, c[k], b[k], val, m_cost(val));
            }
            // printf("%d %d val=%d cost=%d contribution=%d special=%d\n", i, j, val, cost, contribution, special);
            if (normalize(b[nd] + val) != 0) return 0 * puts("-1");
            if (j == 0 || val == 0 || j == m / 2 || val == m / 2) special = 1;
            b[nd] += j;
            contribution = normalize(contribution);
            V[i].push_back(make_pair(contribution, cost));
            if (special) v[i].push_back(make_pair(contribution, cost));
        }
    }
    vector<int> f;
    f.resize(m, INF); f[fe] = 0;
    Solve(1, D, f);
    cout << (ans < INF ? ans : -1);
    return 0;
}