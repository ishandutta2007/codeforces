#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n,k;

int main() {
    scanf("%d %d", &n, &k);

    if (k > n || (k == 1 && n != 1)) {
        printf("-1\n");
        return 0;
    }

    char c = 'a';
    int occ = 0;

    while (n > k-occ) {
        printf("%c", c);
        if (c == 'a') {
            occ = max(occ, 1);
            c = 'b';
        }
        else {
            occ = max(occ, 2);
            c = 'a';
        }

        n--;
    }

    for (int i = occ; i < k; i++) printf("%c", 'a'+i);
    printf("\n");
}