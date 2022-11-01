#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, sz, sum, q, x, l;
vector<ll> s;

int main() {
    scanf("%lld", &n);

    for(int i=0; i<n; i++) {
        scanf("%lld", &q);

        if(q == 1) {
            scanf("%lld", &x);

            if(sz > 0) sum -= s.back();
            else sz++;

            sum += x;
            s.push_back(x);

            while(l < s.size() - 1 && s[l] < (sum + 0.0) / sz) {
                sum += s[l++];
                sz++;
            }
        }

        else if(q == 2) {
            printf("%.9f\n", s.back() - (sum + 0.0) / sz);
        }
    }

    return 0;
}