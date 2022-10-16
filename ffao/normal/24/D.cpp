// Numeric stability u.u

#include <cstdio> 
#include <complex> 

using namespace std; 

int n, m, r1, c1;

struct val {
    double a, b, c, d;
} ex[1100][1100];

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &r1, &c1);

    if (m == 1) {
        printf("%.15f\n", (double)2*(n-r1));
        return 0;
    }

    for (int row = n-1; row >= 1; row--) { 
        // 2/3 x1 = 1 + 1/3 x2 + 1/3 z1
        ex[row][1].b = 2.0/3.0;
        ex[row][1].c = -1.0/3.0;
        ex[row][1].d = ex[row+1][1].d / 3.0 + 1;
        
        for (int col = 2; col <= m-1; col++) {
            // 3/4 x2 = 1 + 1/4 x1 + 1/4 x3 + 1/4 z2
            ex[row][col].a = -1.0/4.0;
            ex[row][col].b = 3.0/4.0;
            ex[row][col].c = -1.0/4.0;
            ex[row][col].d = ex[row+1][col].d / 4.0 + 1;
        }

        ex[row][m].a = -1.0/3.0;
        ex[row][m].b = 2.0/3.0;
        ex[row][m].d = ex[row+1][m].d / 3.0 + 1;

        for (int col = 1; col <= m; col++) {
            ex[row][col].c /= (ex[row][col].b - ex[row][col].a * ex[row][col-1].c);
            ex[row][col].d = (ex[row][col].d - ex[row][col].a * ex[row][col-1].d) /
                             (ex[row][col].b - ex[row][col].a * ex[row][col-1].c);
        }

        for (int col = m-1; col >= 1; col--) {
            ex[row][col].d -= ex[row][col].c * ex[row][col+1].d;
        }
    }

    
    printf("%.15f\n", ex[r1][c1].d);
}