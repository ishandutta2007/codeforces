#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m;
ll ans, a[MN], b[MN], min1 = 10, min2 = 10, freq1[MN], freq2[MN];
//char s[MN]; string str;

int main() {
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        freq1[a[i]]++;
        min1 = min(min1, a[i]);
    }

    for(int i=0; i<m; i++) {
        scanf("%lld", &b[i]);
        freq2[b[i]]++;
        min2 = min(min2, b[i]);
    }

    for(int i = 1;; i++) {
        int d = i / 10, u = i % 10;
        if(freq1[d] || freq1[u])
        if(freq2[d] || freq2[u]) {
            printf("%d\n", i);
            break;
        }

    }

    return 0;
}