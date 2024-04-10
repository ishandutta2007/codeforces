#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, c;
ll ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%d", &n);

    for(int i=1; i<n; i++) {
        if((n - i) % i == 0) c++;
    }

    printf("%d\n", c);
    return 0;
}