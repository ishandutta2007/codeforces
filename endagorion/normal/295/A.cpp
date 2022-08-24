#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;


int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    vector<long long> l(M), r(M), d(M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d", &l[i], &r[i], &d[i]);
        --l[i]; --r[i];
    }
    vector<long long> s(M + 1);
    for (int i = 0; i < K; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        ++s[x];
        --s[y];
    }
    for (int i = 1; i < M; ++i) {
        s[i] += s[i - 1];
    }
    vector<long long> s2(N + 1);
    for (int i = 0; i < M; ++i) {
        d[i] *= s[i];
        s2[l[i]] += d[i];
        s2[r[i] + 1] -= d[i];
    }

    for (int i = 1; i < N; ++i) {
        s2[i] += s2[i - 1];
    }
    for (int i = 0; i < N; ++i) {
        printf("%I64d ", a[i] + s2[i]);
    }
    printf("\n");

	return 0;
}