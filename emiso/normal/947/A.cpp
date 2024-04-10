#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, ans, a[MN];

vector<bool> isp(MN, 1);
vector<int> divi(MN);
vector<int> primos;

void crivo() {
    for(int i = 2; i < MN; i++) {
        if(isp[i]) {
            primos.push_back(i);
            divi[i] = 1; // or i?
            for(int j = 2 * i; j < MN; j += i) {
                isp[j] = 0;
                divi[j] = i;
            }
        }
    }
}

ll x2, p2, x1, p1, x0 = INT_MAX;

int main() {
    crivo();
    scanf("%lld", &x2);

    p2 = divi[x2];
    for(x1 = x2 - p2 + 1; x1 <= x2; x1++) {
        p1 = divi[x1];
        x0 = min(x0, x1 - p1 + 1);
    }

    printf("%lld\n", max(x0, 0LL));
    return 0;
}