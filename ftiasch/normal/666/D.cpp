#include <cassert>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>

const long long BOUND = 1e15;

const long long DELTA_X[] = {-1, 0, 0, 1};
const long long DELTA_Y[] = {0, -1, 1, 0};

long long x[4], y[4], xx[4], yy[4], x_low[2], x_high[2], y_low[2], y_high[2], X[2], Y[2];

void update_range(long long& low, long long& high, long long dx, long long x0, long long max_t)
{
    if (dx < 0) {
        low = std::max(low, x0 - max_t);
        high = std::min(high, x0);
    } else if (dx == 0) {
        low = std::max(low, x0);
        high = std::min(high, x0);
    } else {
        low = std::max(low, x0);
        high = std::min(high, x0 + max_t);
    }
}

std::pair<long long, long long> solve(long long* low, long long* high)
{
    long long sol_lo = std::max(1LL, low[1] - high[0]);
    long long sol_hi = high[1] - low[0];
    return {sol_lo, sol_hi};
}

bool check(long long max_t)
{
    for (int d0 = 0; d0 < 4; ++ d0) {
        for (int d1 = 0; d1 < 4; ++ d1) {
            for (int d2 = 0; d2 < 4; ++ d2) {
                for (int d3 = 0; d3 < 4; ++ d3) {
                    int d[4] = {d0, d1, d2, d3};
                    std::vector<long long> c(4);
                    std::iota(c.begin(), c.end(), 0);
                    do {
                        x_low[0] = x_low[1] = y_low[0] = y_low[1] = -1e18;
                        x_high[0] = x_high[1] = y_high[0] = y_high[1] = 1e18;
                        for (long long i = 0; i < 4; ++ i) {
                            long long x_id = c[i] >> 1;
                            long long y_id = c[i] & 1;
                            update_range(x_low[x_id], x_high[x_id], DELTA_X[d[i]], x[i], max_t);
                            update_range(y_low[y_id], y_high[y_id], DELTA_Y[d[i]], y[i], max_t);
                        }
                        bool valid = true;
                        valid &= x_low[0] <= x_high[0];
                        valid &= x_low[1] <= x_high[1];
                        valid &= y_low[0] <= y_high[0];
                        valid &= y_low[1] <= y_high[1];
                        if (!valid) {
                            continue;
                        }
                        auto range_x = solve(x_low, x_high);
                        auto range_y = solve(y_low, y_high);
                        if (std::max(range_x.first, range_y.first) <= std::min(range_x.second, range_y.second)) {
                            long long l = std::max(range_x.first, range_y.first);
                            X[0] = std::max(x_low[0], x_low[1] - l);
                            X[1] = X[0] + l;
                            Y[0] = std::max(y_low[0], y_low[1] - l);
                            Y[1] = Y[0] + l;
                            for (long long i = 0; i < 4; ++ i) {
                                long long x_id = c[i] >> 1;
                                long long y_id = c[i] & 1;
                                xx[i] = X[x_id];
                                yy[i] = Y[y_id];
                            }
                            return true;
                        }
                    } while (std::next_permutation(c.begin(), c.end()));
                }
            }
        }
    }
    return false;
}

void work()
{
    for (long long i = 0; i < 4; ++ i) {
        std::cin >> x[i] >> y[i];
    }
    long long low = 0;
    long long high = BOUND;
    while (low < high) {
        long long middle = low + high >> 1;
        if (check(middle)) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }
    if (check(high)) {
        std::cout << high << std::endl;
        for (long long i = 0; i < 4; ++ i) {
            std::cout << xx[i] << " " << yy[i] << std::endl;
        }
    } else {
        puts("-1");
    }
}

int main()
{
    long long t;
    std::cin >> t;
    while (t --) {
        work();
    }
}