#include <bits/stdc++.h>

using namespace std;

int n, w[110];

int main() {
    scanf("%d", &n);
    for(int i=0; i<2*n; i++) {
        scanf("%d", &w[i]);
    } sort(w, w + 2*n);

    int ans = 99999999;
    for(int i = 0; i < 2*n; i++) {
        for(int j = i+1; j < 2*n; j++) {
            vector<int> we;
            for(int k = 0; k < 2*n; k++) {
                if(k != i && k != j) we.push_back(w[k]);
            }

            int best = 0;
            for(int k = 1; k < we.size(); k += 2) {
                best += abs(we[k] - we[k-1]);
            }

            ans = min(ans, best);
        }
    }

    printf("%d\n", ans);
}