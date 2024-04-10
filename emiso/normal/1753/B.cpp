#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll n, a[MN], x;

ll amt[MN];

int main() {
    scanf("%lld %lld", &n, &x);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        amt[a[i]]++;
    }
    
    int ans = 1;
    for (int i = 1; i < x; i++) {
        ll factor = amt[i] / (i + 1);
        amt[i + 1] += factor;
        amt[i] -= factor * (i + 1);

        ans &= (amt[i] == 0);
    }


    puts(ans ? "Yes" : "No");
    return 0;
}