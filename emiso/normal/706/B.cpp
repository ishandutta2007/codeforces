#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

int main() {
    int n,q,x,m;
    vector<int> prices;
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d",&x);
        prices.push_back(x);
    }
    sort(prices.begin(),prices.end());

    scanf("%d",&q);

    for(int i=0; i<q; i++) {
        scanf("%d",&m);
        printf("%d\n",upper_bound(prices.begin(),prices.end(),m) - prices.begin());
    }
    return 0;
}