#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n;

int main() {
    scanf("%lld", &n); n++;

    if(n == 1) printf("0\n");
    else if(n % 2) printf("%lld\n", n);
    else printf("%lld\n", n / 2);
    return 0;
}