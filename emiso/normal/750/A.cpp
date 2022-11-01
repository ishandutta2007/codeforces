#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int main() {
    int n, k, p = 0;
    scanf("%d %d",&n ,&k);

    k = 240 - k;
    while(k >= (p+1)*5 && p < n) {
        k -= (p+1)*5;
        p++;
    }

    printf("%d\n",p);
    return 0;
}