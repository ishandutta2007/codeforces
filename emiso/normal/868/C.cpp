#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, k, a[100100][5], can[33], flag = 0;

int main() {
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++) {
        int num = 0, mult = 1;
        for(int K=0; K<k; K++) {
            scanf("%d", &a[i][K]);
            num = num * 2 + a[i][K];
        }

        assert(num < 16);
        can[num]++;
    }

    if(can[0]) flag = 1;
    for(int i = 0; i < 17; i++) {
        for(int j = 0; j < 17; j++) {
            if(i & j) continue;
            if(can[i] && can[j]) flag = 1;
        }
    }

    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}