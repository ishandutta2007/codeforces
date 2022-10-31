#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN], ac0[MN], ans;

map<int, int> fst, lst;

int main() {
    scanf("%d", &n);

    fst[0] = 0; lst[0] = 0;
    for(int i=1; i<=n; i++) {
        scanf("%1d", &a[i]);
        ac0[i] = (a[i] == 0) + ac0[i-1];

        int bal = i - 2*ac0[i];
        if(!fst.count(bal)) fst[bal] = i;
        lst[bal] = i;
    }

    for(auto x : lst) {
        ans = max(ans, x.second - fst[x.first]);
    }

    assert(ans % 2 == 0);
    printf("%d\n", ans);
    return 0;
}