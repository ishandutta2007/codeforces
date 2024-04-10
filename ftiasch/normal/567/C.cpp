#include <cstdio>
#include <iostream>
#include <map>

const int N = 200000;

int a[N], p[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    std::map <long long, int> count;
    for (int i = 0; i < n; ++ i) {
        p[i] = 0;
        if (a[i] % k == 0) {
            p[i] = count[a[i] / k];
        }
        count[a[i]] ++;
    }
    long long result = 0;
    count.clear();
    for (int i = n - 1; i >= 0; -- i) {
        result += (long long)p[i] * count[(long long)a[i] * k];
        count[a[i]] ++;
    }
    std::cout << result << std::endl;
    return 0;
}