#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 9;

int cnt[1000555];

int main() {
    int n, x, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 0; i < 1000050; i++){
        cnt[i + 1] += cnt[i] / 2, cnt[i] &= 1;
        ans += cnt[i];
    }
    printf("%d\n", ans);






}