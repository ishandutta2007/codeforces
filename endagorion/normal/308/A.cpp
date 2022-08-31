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
#include <sstream>
#include <algorithm>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

ll a[3000010];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, T, L;
    scanf("%d%d%d", &N, &L, &T);
    L *= 2;
    T *= 2;
    for (int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = 2LL * x;
        a[i + N] = L + a[i];
        a[i + 2 * N] = 2LL * L + a[i];
    }

    double ans = 0;
    if (T >= L / 2) {
        ans += 0.25 * N * (N - 1) * (T / (L / 2));
        T %= L / 2;
    }

    int r = 0;
    for (int i = 0; i < N; ++i) {
        while (a[r + 1] <= a[i] + 2LL * T) {
            ++r;
        }
        ans += 0.25 * (r - i);
    }
    printf("%.10lf", ans);

    return 0;
}