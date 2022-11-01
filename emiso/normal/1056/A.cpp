#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, ans, a[MN];
set<int> possib, p2, p3;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        p2.clear();
        p3.clear();

        int k;
        scanf("%d", &k);
        while(k--) {
            scanf("%d", &a[i]);
            if(i == 0) possib.insert(a[i]);
            else p2.insert(a[i]);
        }

        if(i) {
            for(int x : possib) {
                if(p2.count(x))
                    p3.insert(x);
                }
            possib = p3;
        }
    }

    for(int x : possib)
        printf("%d ", x);
    return 0;
}