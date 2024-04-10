#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAXC = 17575;
const int SIGMA = 26;

int vc[1 + MAXC];
char home[10], s[10];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d\n%s", &n, home + 1);
    int from = SIGMA * SIGMA * (home[1] - 'A') + SIGMA * (home[2] - 'A') + home[3] - 'A';
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        int x = SIGMA * SIGMA * (s[1] - 'A') + SIGMA * (s[2] - 'A') + s[3] - 'A';
        int y = SIGMA * SIGMA * (s[6] - 'A') + SIGMA * (s[7] - 'A') + s[8] - 'A';
        if (x == from)
            vc[y]++;
        else
            vc[x]++;
    }
    for (int i = 0; i <= MAXC; i++)
        if (vc[i] % 2) {
            printf("contest\n");
            return 0;
        }
    printf("home\n");
    return 0;
}