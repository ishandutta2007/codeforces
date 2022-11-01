#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n;
ll ans, a, b, x, bst;

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%lld", &x);
        //x = i;

        if(x == 0) {
            printf("1 1\n");
            continue;
        }

        a = 0;
        for(ll N = sqrt(x); N <= 40000 && !a; N++) {
            ll divi = N*N - x;
            if(divi <= 0) continue;

            divi = round(sqrt(divi));
            if(divi * divi != (N*N - x)) continue;

            if((N/2) < divi) break;

            for(int m = N / (divi+1) + 1; m <= N/divi; m++) {
                a = N;
                b = m;
                break;
            }
        }

        if(a) printf("%lld %lld\n", a, b);
        else printf("-1\n");
    }
    return 0;
}