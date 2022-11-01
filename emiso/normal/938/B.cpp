#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, best = INT_MAX;
ll ans, a[MN], prize[MN], cnt;
//char s[MN]; string str;

int main() {
    scanf("%lld", &n);

    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        prize[a[i]] = 1;
    }

    for(int i = 1; i < MN; i++) {
        cnt += prize[1 + i];
        cnt += prize[1000000 - i];

        if(cnt >= n) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}