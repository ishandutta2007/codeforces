#include <cstdio>
#include <cstring>
using namespace std;

int count[3][2];

int main() {
    int n;
    scanf("%d", &n);
    while (n --) {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        count[t][0] += a;
        count[t][1] += b;
    }
    for (int t = 1; t <= 2; ++ t) {
        puts(count[t][0] >= count[t][1] ? "LIVE" : "DEAD");
    }
    return 0;
}