#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, a, b, c, d;
vector<pair<ll, int> > ord;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        ord.emplace_back(- (a + b + c + d), i + 1);
    }
    sort(ord.begin(), ord.end());

    for(int i = 0; i < n; i++) {
        if(ord[i].second == 1) printf("%d\n", i + 1);
    }
    return 0;
}