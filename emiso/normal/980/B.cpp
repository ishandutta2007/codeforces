#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, k, a[110][110];

int main() {
    scanf("%lld %lld", &n, &k);

    puts("YES");
    for(int i = 0; i < n; i++) printf("."); puts("");
    if(k % 2 == 0) {
        for(int i = 0; i < n; i++) {
            if(i > 0 && i <= k/2) printf("#");
            else printf(".");
        } puts("");

        for(int i = 0; i < n; i++) {
            if(i > 0 && i <= k/2) printf("#");
            else printf(".");
        } puts("");
    } else {
        if(k >= n) {
            int l = (k - n + 2);
            k = n - 2;
            for(int i = 0; i < n; i++) {
                if(i >= (n-k)/2 && i < (n+k)/2) printf("#");
                else printf(".");
            } puts("");

            printf(".");
            for(int i = 0; i < l/2; i++) printf("#");
            for(int i = 0; i < n - l - 2; i++) printf(".");
            for(int i = 0; i < l/2; i++) printf("#");
            printf(".");
            puts("");
        }
        else {
            for(int i = 0; i < n; i++) {
                if(i >= (n-k)/2 && i < (n+k)/2) printf("#");
                else printf(".");
            } puts("");

            for(int i = 0; i < n; i++) printf("."); puts("");
        }
    }
    for(int i = 0; i < n; i++) printf("."); puts("");
    return 0;
}