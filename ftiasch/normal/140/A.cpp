#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-9;

int n, R, r;

int main() {
    scanf("%d%d%d", &n, &R, &r);
    if (n == 1) {
        puts(r <= R? "YES": "NO");
    } else if (n == 2) {
        puts(2 * r <= R? "YES": "NO");
    } else {
        double angle = PI / n;
        double max = R * sin(angle) / (1 + sin(angle));
        puts(r <= max + EPS? "YES": "NO");
    }
    return 0;
}