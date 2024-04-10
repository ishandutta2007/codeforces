#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, a[100010], b[100010];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0, suml = a[0], sumr = b[0], ans = 0;
    while(i < n || j < m) {
        while(suml != sumr) {
            if(suml < sumr) {
                suml += a[++i];
            }
            if(suml > sumr) {
                sumr += b[++j];
            }
        }
        ans++;
        i++;
        j++;
        if(i < n) suml = a[i];
        if(j < m) sumr = b[j];
    }
    printf("%d\n", ans);

    return 0;
}