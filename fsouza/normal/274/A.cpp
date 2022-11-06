#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

#define MAXN 100000

typedef long long lint;

using namespace std;

int A[MAXN];

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    sort(A, A+n);

    const int maxv = A[n-1];

    if (k == 1) {
        printf("%d\n", n);
    } else {
        set<int> ret;

        for (int i = n-1; i >= 0; i--) {
            int v = A[i];
            int ok = 1;
            
            lint v2 = (lint)v*(lint)k;
            while (v2 <= (lint)maxv) {
                if (ret.find((int)v2) != ret.end()) {
                    ok = 0;
                    break;
                }
//              v2 *= (lint)k;
                break;
            }

            if (ok)
                ret.insert(v);
        }

        printf("%d\n", (int)ret.size());
    }

    return 0;
}