#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>


using namespace std;


#define eps 0.0000001


double a, d;
int n;

        
int main() {
    cin >> a >> d;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double k = i * d;
        long long l = (long long)(k / a);
        if (l * a < k + eps) {
            l++;
        }
        if (l % 4 == 1) {
            printf("%.10lf %.10lf\n", 0.0 + k - (l - 1) * a, 0.0);
        }
        if (l % 4 == 2) {
            printf("%.10lf %.10lf\n", a, 0.0 + k - (l - 1) * a);
        }
        if (l % 4 == 3) {
            printf("%.10lf %.10lf\n", a - k + (l - 1) * a, a);
        }
        if (l % 4 == 0) {
            printf("%.10lf %.10lf\n", 0.0, a - k + (l - 1) * a);
        }
    }
    return 0;
}