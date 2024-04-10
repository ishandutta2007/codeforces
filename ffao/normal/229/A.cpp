#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;

int tally[10000];
int th[10000];
int a[10000];

int main() {
    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++) {
        int f = -1;
        for (int j = 0; j < C; j++) {
            scanf(" %c", &a[j]);
            a[j]-='0';

            th[j] = 10000000;
            if (a[j] == 1 && f == -1) f = j;
        }

        if (f == -1) {
            printf("-1\n");
            return 0;
        }

        th[f] = 0;
        int t = f;
        for (int j = (f+1)%C; j != f; j = (j+1)%C ) {
            if (a[j] == 1) t = j; 

            th[j] = min(th[j], (j-t+C)%C);
        }

        t = f;
        for (int j = (f-1+C)%C; j != f; j = (j-1+C)%C ) {
            if (a[j] == 1) t = j; 
            th[j] = min(th[j], (t-j+C)%C);
        }

        for (int j = 0; j < C; j++) tally[j] += th[j];
    }

    printf("%d\n", *min_element(tally,tally+C));
}