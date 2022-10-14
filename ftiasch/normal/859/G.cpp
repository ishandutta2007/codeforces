#include <cmath>
#include <cstdio>
#include <vector>

const int N = 100000;

char s[N + 1];
double a[N];

int main()
{
    int n;
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++ i) {
        a[i] = s[i] - '0';
    }
    std::vector<int> factors;
    int tmp = n;
    for (int p = 2; p <= n; ++ p) {
        if (tmp % p == 0) {
            factors.push_back(n / p);
            while (tmp % p == 0) {
                tmp /= p;
            }
        }
    }
    for (auto l : factors) {
        for (int offset = 0; offset < l; ++ offset) {
            double avg = 0.;
            for (int i = offset; i < n; i += l) {
                avg += a[i];
            }
            avg /= n / l;
            for (int i = offset; i < n; i += l) {
                a[i] -= avg;
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < n; ++ i) {
        ok &= fabs(a[i]) < 1e-9;
    }
    puts(ok ? "YES" : "NO");
}