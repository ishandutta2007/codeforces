#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll k, x, cur, sum;
vector<ll> ans;

int main() {
    scanf("%lld", &k);
    x = 1000000 - (k % 2000);

    for(int i = 0; i + 2 < 2000; i++) {
        if(i % 2) ans.push_back(-1);
        else ans.push_back(1);
    }
    ans.push_back(-1);
    ans.push_back(x);

    sum = x - 1;
    cur = sum * 2000;

    assert(cur - (x + k) >= 0);
    assert((cur - (x + k)) % 2000 == 0);
    ll reduce = (cur - (x + k)) / 2000;
    ans[1998] -= reduce;

    printf("2000\n");
    for(int i = 0; i < 2000; i++)
        printf("%lld ", ans[i]);

    //cerr << endl << (sum - reduce) * 2000 << endl;
    return 0;
}