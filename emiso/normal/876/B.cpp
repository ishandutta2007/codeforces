#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, k, m;
ll ans, a[MN], freq[MN];

int main() {
    scanf("%d %d %d", &n, &k, &m);

    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        freq[a[i] % m]++;
    }

    for(int i = 0; i < m; i++)
        if(freq[i] >= k) {
            puts("Yes");
            for(int j = 0, q = 0; q < k; j++)
                if(a[j] % m == i) {
                    printf("%lld ", a[j]);
                    q++;
                }
            return 0;
        }

    puts("No");
    return 0;
}