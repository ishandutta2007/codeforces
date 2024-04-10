#include <bits/stdc++.h>

using namespace std;

int n, k, m, a[50], sum;
vector<int> tk;

int main() {
    scanf("%d %d %d", &n, &k, &m);
    for(int i=0; i<k; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    } sort(a, a + k, greater<int>());

    int p = 0, cur, tm;
    for(int fin = 0; fin <= n && m >= sum * fin; fin++) {
        tk.clear();
        cur = (k + 1) * fin;
        tm = m - sum * fin;

        for(int i=0; i<k; i++)
            for(int j=fin; j<n; j++)
                tk.push_back(a[i]);

        while(!tk.empty() && tm >= tk.back()) {
            cur++;
            tm -= tk.back();
            tk.pop_back();
        }

        p = max(p, cur);
    }

    printf("%d\n", p);
    return 0;
}