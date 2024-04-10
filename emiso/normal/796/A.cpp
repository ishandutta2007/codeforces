#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, k, p, ans = 100000;
//char s[MN]; string str;

int main() {
    scanf("%d %d %d",&n ,&m, &k);

    for(int i=1; i<=n; i++) {
        scanf("%d",&p);
        if(p != 0 && p <= k) {
            ans = min(ans, abs(i - m));
        }
    }

    printf("%d\n", ans * 10);
    return 0;
}