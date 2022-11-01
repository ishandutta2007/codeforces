#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN], ans, k;
//char s[MN]; string str;

int main() {
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    } sort(a, a + n);

    for(int i=0; i<n; i++) {
        while(a[i] > 2 * k) {
            ans++;
            k *= 2;
        }
        k = max(k, a[i]);
    }

    printf("%d\n", ans);
    return 0;
}