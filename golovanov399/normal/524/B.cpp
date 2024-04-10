#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define x first
#define y second

using namespace std;

int main(){

    int n;
    scanf("%d", &n);
    vector<int> w(n), h(n);
    for (int i = 0; i < n; i++){
        scanf("%d%d", &w[i], &h[i]);
        if (w[i] > h[i])
            swap(w[i], h[i]);
    }
    int ans = 1e9;
    for (int mx = *max_element(all(w)); mx < 1001; mx++){
        int sum = 0;
        for (int i = 0; i < n; i++){
            if (h[i] <= mx)
                sum += w[i];
            else
                sum += h[i];
        }
        ans = min(ans, sum * mx);
    }
    printf("%d\n", ans);

    return 0;
}