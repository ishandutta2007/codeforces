#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN], r2, r4, k;
map<int, int> grp;

int main() {
    scanf("%d %d", &n, &k);
    r2 = 2 * n;
    r4 = n;

    for(int i=0; i<k; i++) {
        scanf("%d", &a[i]);
        grp[a[i]]++;
    }

    while(!grp.empty()) {
        if(r2 == 0 && r4 == 0) {
            puts("NO");
            return 0;
        }

        int x = (*grp.rbegin()).first;
        //printf("%d %d %d %d %d\n", x, r2, r4, grp[x], grp.size());

        grp[x]--;
        if(grp[x] == 0) grp.erase(x);


        if(r4) {
            if(x >= 3) {
                r4--;
                if(x > 4) grp[x - 4]++;
            }
            else {
                if(x == 2) {
                    r4--;
                    if(!grp.empty()) {
                        int z = (*grp.begin()).first;
                        grp[z]--;
                        if(grp[z] == 0) grp.erase(z);
                        else if(z == 2) grp[z-1]++;
                    }

                } else {
                    r4--;

                    if(!grp.empty()) {
                        int z = (*grp.rbegin()).first;
                        grp[z]--;
                        if(z == 0) grp.erase(z);
                    }
                }
            }
        } else {
            r2--;
            if(x > 2) grp[x - 2]++;
        }

    }

    printf("YES\n");
    return 0;
}