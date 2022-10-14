#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

const int N = 5000;

int n, m, a[N], b[N];
std::set <int> bads;
std::vector <std::pair <int, int> > factors[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < m; ++ i) {
        scanf("%d", b + i);
        bads.insert(b[i]);
    }
    {
        int tmp = a[0];
        for (int d = 2; d * d <= tmp; ++ d) {
            while (tmp % d == 0) {
                factors[0].push_back(std::make_pair(d, bads.count(d) ? -1 : 1));
                tmp /= d;
            }
        }
        if (tmp > 1) {
            factors[0].push_back(std::make_pair(tmp, bads.count(tmp) ? -1 : 1));
        }
    }
    for (int i = 1; i < n; ++ i) {
        int tmp = a[i];
        for (auto& p : factors[i - 1]) {
            if (tmp % p.first == 0) {
                tmp /= p.first;
                factors[i].push_back(p);
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; ++ i) {
        int tmp = a[i];
        for (int j = 0; j < m; ++ j) {
            while (tmp % b[j] == 0) {
                result --;
                tmp /= b[j];
            }
        }
        for (int d = 2; d * d <= tmp; ++ d) {
            while (tmp % d == 0) {
                result ++;
                tmp /= d;
            }
        }
        if (tmp > 1) {
            result ++;
        }
    }
    int delta = 0;
    for (int i = n - 1; i >= 0; -- i) {
        int sum = -delta;
        for (auto &p : factors[i]) {
            sum += p.second;
        }
        if (sum < 0) {
            result -= sum * (i + 1);
            delta += sum;
        }
    }
    printf("%d\n", result);
    return 0;
}