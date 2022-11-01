#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a, ans, k, reserva, resp = -1;
//char s[MN]; string str;

int main() {
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%d",&a);
        if(a < 8) {
            a += reserva;
            reserva = 0;
        }
        int g = min(a, 8);
        if(a > 8) {
            reserva += (a - g);
        }
        ans += g;

        if(ans >= k && resp == -1) {
            resp = i + 1;
        }
    }

    printf("%d\n", resp);
    return 0;
}