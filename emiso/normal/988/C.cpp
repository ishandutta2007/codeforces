#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int k, x, sum[MN], n;
vector<int> seq[MN];
map<int, vector<pair<int, int> > > possib;

int main() {
    scanf("%d", &k);

    for(int i = 0; i < k; i++) {
        scanf("%d", &n);
        for(int j = 0; j < n; j++) {
            scanf("%d", &x);
            seq[i].push_back(x);
            sum[i] += x;
        }
    }

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < seq[i].size(); j++) {
            vector<pair<int, int> > &v = possib[sum[i] - seq[i][j]];
            if(v.empty() || v.back().first != i)
            v.push_back({i, j});
        }
    }

    for(auto &p : possib) {
        if(p.second.size() > 1) {
            printf("YES\n");
            printf("%d %d\n", p.second[0].first + 1, p.second[0].second + 1);
            printf("%d %d\n", p.second[1].first + 1, p.second[1].second + 1);
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}