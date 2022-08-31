#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

#ifndef ONLINE_JUDGE

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);
FILE *file_in = fopen("input.txt", "rt");
FILE *file_out = fopen("output.txt", "wt");

#else

#define fin cin
#define fout cout
#define file_in stdin
#define file_out stdout

#endif

struct TTarget {
    long long x, y, t;
    double p;

    TTarget(long long _x = 0, long long _y = 0, long long _t = 0, double _p = 0.0)
        : x(_x)
        , y(_y)
        , t(_t)
        , p(_p)
    {
    }

    bool reach(const TTarget &tar) const {
        return (x - tar.x) * (x - tar.x) + (y - tar.y) * (y - tar.y) <= (t - tar.t) * (t - tar.t);
    }

    bool operator<(const TTarget &tar) const {
        return t < tar.t;
    }
};

int main() {
    int n;
    fin >> n;
    vector< TTarget > targets(n);
    for (int i = 0; i < n; ++i) {
        fin >> targets[i].x >> targets[i].y >> targets[i].t >> targets[i].p;
    }

    sort(targets.begin(), targets.end());
    vector< double > ans(n, 0.0);
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        ans[i] = max(ans[i], targets[i].p);
        result = max(result, ans[i]);
        for (int j = i + 1; j < n; ++j) {
            if (targets[i].reach(targets[j])) {
                ans[j] = max(ans[j], ans[i] + targets[j].p);
            }
        }
    }

    fprintf(file_out, "%.10lf\n", result);
    return 0;
}