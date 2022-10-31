#include <bits/stdc++.h>

#define MN 100100
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

int iscap[MN];

int main() {
    int n, k, id;
    long long res = 0, sum = 0, c[MN], sum_cap = 0;
    scanf("%d %d",&n,&k);

    for(int i=1; i<=n; i++) {
        scanf("%lld",&c[i]);
        sum += c[i];
        if(i > 1) res += (1LL * c[i] * c[i-1]);
    }
    res += (1LL * c[1] * c[n]);

    for(int i=0;i<k;i++) {
        scanf("%d",&id);
        iscap[id] = 1;

        long long sum_comp = (sum - c[id] - sum_cap);

        if(id > 1 && !iscap[id-1]) sum_comp -= c[id-1];
        else if(id == 1 &&!iscap[n]) sum_comp -= c[n];

        if(id < n && !iscap[id+1]) sum_comp -= c[id+1];
        else if(id == n && !iscap[1]) sum_comp -= c[1];


        res += (c[id] * sum_comp);

        sum_cap += c[id];
    }

    printf("%lld\n",res);
    return 0;
}