#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, min_odd = 9999999, max_odd = -9999999, tot, a;
//char s[MN]; string str;

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d",&a);
        if(a < 0) {
            if(a % 2) max_odd = max(max_odd, a);
            continue;
        }

        tot += a;
        if(a % 2) min_odd = min(min_odd, a);
    }

    if(tot % 2 == 0) tot = max(tot - min_odd, tot + max_odd);
    printf("%d\n", tot);
    return 0;
}