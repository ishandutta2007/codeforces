#include <bits/stdc++.h>

#define MN 100100

using namespace std;
typedef long long ll;

int n, k, a[MN], b[MN], used[256];
vector<int> g;

int main() {
    scanf("%d %d", &n, &k);

    g.push_back(0);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        int idx = upper_bound(g.begin(), g.end(), a[i]) - g.begin();
        idx--;

        if(g[idx] + k - 1 < a[i]) {
            int j;
            for(j = a[i]; j > a[i]-k; j--)
                if(used[j]) break;
            g.push_back(j + 1);


            sort(g.begin(), g.end());
            g.resize(unique(g.begin(), g.end()) - g.begin());
        }

        idx = upper_bound(g.begin(), g.end(), a[i]) - g.begin();
        idx--;

        b[i] = g[idx];
        used[a[i]] = 1;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}