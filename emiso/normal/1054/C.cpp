#include <bits/stdc++.h>

#define MN 1010

using namespace std;
typedef long long ll;

int n, ans, l[MN], r[MN], manyl, manyr, tot, mark[MN];

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }

    for(int j = n; j > 0; j--) {
        manyl = 0; manyr = tot;
        for(int i = 0; i < n; i++) {
            if(mark[i]) manyl++, manyr--;
            else if(l[i] == manyl && r[i] == manyr) {
                mark[i] = j;
                tot++;
            }
        }
    }

    if(tot < n) printf("NO\n");
    else {
        printf("YES\n");
        for(int i = 0; i < n; i++)
            printf("%d ", mark[i]);
    }
    return 0;
}