#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, m, X1, X2, Y;

vector<int> verti, hori;

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &X1);
        verti.push_back(X1);
    }
    verti.push_back(1000000000);
    sort(verti.begin(), verti.end());

    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &X1, &X2, &Y);
        if(X1 == 1) hori.push_back(X2);
    }
    sort(hori.begin(), hori.end());

    int ans = n + m, idx = 0;
    for(int i = 0; i < (int)verti.size(); i++) {
        while(idx < (int)hori.size() && hori[idx] < verti[i]) idx++;
        ans = min(ans, i + ((int)hori.size() - idx));
    }
    ans = min(ans, (int) hori.size());

    printf("%d\n", ans);
    return 0;
}