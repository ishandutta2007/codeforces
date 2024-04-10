#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

double ans;

int main() {
    int H, M, h, d, c, n;
    scanf("%d %d", &H, &M);
    scanf("%d %d %d %d", &h, &d, &c, &n);

    int howmany = h / n + (h % n != 0);
    ans = c * howmany;

    int diff = (H >= 20) ? 0 : (20 - H) * 60 - M;
    h += d * diff;
    howmany = h / n + (h % n != 0);

    ans = min(ans, 0.8 * c * howmany);

    printf("%.9f\n", ans);

    return 0;
}