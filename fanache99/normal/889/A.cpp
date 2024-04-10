#include <fstream>
#include <cmath>

using namespace std;

const int MAXN = 200000;

int moment[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, rooms = 1;
    scanf("%d", &n);
    moment[0] = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (!moment[x]) {
            rooms++;
            moment[i] = rooms;
        }
        else {
            moment[x] = 0;
            moment[i] = rooms;
        }
    }
    printf("%d\n", rooms);
    return 0;
}