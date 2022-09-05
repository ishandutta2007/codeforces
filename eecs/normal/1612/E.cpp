#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m[maxn], k[maxn], cnt[maxn][21];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &m[i], &k[i]), cnt[m[i]][k[i]]++;
    }
    int mx = 0, num = 0;
    vector<int> ans;
    for (int i = 1; i <= 25; i++) {
        vector<pair<int, int>> V;
        for (int j = 1; j <= 200000; j++) {
            int s = 0;
            for (int k = 1; k <= 20; k++) s += cnt[j][k] * min(k, i);
            V.emplace_back(s, j);
        }
        sort(V.begin(), V.end(), greater<pair<int, int>>());
        int s = 0;
        for (int j = 0; j < i; j++) s += V[j].first;
        if (1LL * mx * i <= 1LL * s * num) {
            mx = s, num = i, ans.clear();
            for (int j = 0; j < i; j++) ans.push_back(V[j].second);
        }
    }
    printf("%d\n", num);
    for (int x : ans) printf("%d ", x);
    return 0;
}