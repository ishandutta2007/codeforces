#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, k, a[210][210], ac[210][210];
//char s[MN]; string str;


int main() {
    scanf("%d %d %d", &n, &m, &k);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d", &a[j][i]);

    for(int i = 1; i <= 205; i++)
        for(int j = 1; j <= 205; j++)
            ac[j][i] = a[j][i] + ac[j][i-1];


    int ans = 0, op = 0;
    for(int j = 1; j <= m; j++) {
        int bst = 0, bop = 0, co = 0;

        for(int i = 1; i <= n; i++) {
            if(a[j][i] == 0) continue;
            int pont = ac[j][i + k - 1] - ac[j][i - 1];

            if(pont > bst) {
                bst = pont;
                bop = co;
            }
            co++;
        }

        ans += bst; op += bop;
    }

    printf("%d %d\n", ans, op);
    return 0;
}