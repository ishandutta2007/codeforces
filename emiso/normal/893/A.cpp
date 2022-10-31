#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, x, a1 = 1, a2 = 2, a3 = 3, flag = 1;
ll ans, a[MN];

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        if(x != a1 && x != a2) flag = 0;
        if(x == a1) swap(a2, a3);
        else if(x == a2) swap(a1, a3);
    }

    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}