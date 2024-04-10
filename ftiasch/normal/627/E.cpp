#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

const int N = 3000 + 2;

int prev[N], next[N], sum[N];
std::pair<int, int> points[N];
std::vector<int> events[N];

int length(int p)
{
    int l = points[next[p]].first - points[p].first;
    assert(l >= 0);
    return l;
}

int tmp_lengths[N];

int main()
{
    int r, c, n, k;
    scanf("%d%d%d%d", &r, &c, &n, &k);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", &points[i].first, &points[i].second);
    }
    std::sort(points, points + n);
    points[n].first = 0;
    points[n + 1].first = r + 1;
    for (int i = 0; i < n; ++ i) {
        events[points[i].second].push_back(i);
    }
    long long result = (long long)r * (r + 1) / 2 * c * (c + 1) / 2;
    for (int left = 1; left <= c; ++ left) {
        prev[n] = next[n] = n + 1;
        prev[n + 1] = next[n + 1] = n;
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; ++ i) {
            if (points[i].second >= left) {
                prev[i] = prev[n + 1];
                next[prev[n + 1]] = i;
                next[i] = n + 1;
                prev[n + 1] = i;
                sum[points[i].first] ++;
            }
        }
        int pairs = 0;
        for (int i = 1, j = 0; i <= r; ++ i) {
            sum[i] += sum[i - 1];
            while (sum[i] - sum[j] >= k) {
                j ++;
            }
            pairs += i - j;
        }
        for (int right = c; right >= left; -- right) {
            result -= pairs;
            for (int e : events[right]) {
                memset(tmp_lengths, 0, sizeof(*tmp_lengths) * k);
                for (int i = 0, p = e; i < k; ++ i) {
                    p = prev[p];
                    tmp_lengths[k - 1 - i] = length(p);
                    if (p >= n) {
                        break;
                    }
                }
                for (int i = 0, p = e; i < k; ++ i) {
                    if (p >= n) {
                        break;
                    }
                    pairs += tmp_lengths[i] * length(p);
                    p = next[p];
                }
                next[prev[e]] = next[e];
                prev[next[e]] = prev[e];
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}