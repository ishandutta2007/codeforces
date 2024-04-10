#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, ans, a[MN], flag;

int main() {
    scanf("%lld", &n);

    for(int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i=1; i<=n; i++) {
        if(a[a[a[i]]] == i) flag = 1;
    }

    printf("%s\n", flag ? "YES" : "NO");
    return 0;
}