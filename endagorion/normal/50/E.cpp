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

long long floor(long long a, long long b) {
    if (a >= 0) {
        return a / b;
    } else {
        return -((-a - 1) / b) - 1;
    }
}

long long ceil(long long a, long long b) {
    return -floor(-a, b);
}

struct TEvent {
    bool open;
    int x;

    TEvent(bool _open, int _x)
        : open(_open)
        , x(_x) {
    }

    bool operator<(TEvent &ev) const {
        return (x < ev.x) || (x == ev.x && open && !ev.open);
    }
};

int main() {
    int n, m;
    fin >> n >> m;
    
    long long ans = 0;

    vector< TEvent > events;
    for (long long b = 1; b <= n; ++b) {
        if (b * b <= m) {
            ans += 2 * b * b - 2 * b;
            events.push_back(TEvent(true, -2 * b + 1));
            events.push_back(TEvent(false, -1));
        } else {
            ans += 2 * m;
            int low = (int)ceil(sqrt(1.0 * b * b - m));
            int high = (int)floor(sqrt(1.0 * b * b - 1));
            ans -= 2 * (high - low + 1);
            if (low <= high) {
                events.push_back(TEvent(true, -b - high));
                events.push_back(TEvent(false, -b - low));
                events.push_back(TEvent(true, -b + low));
                events.push_back(TEvent(false, -b + high));
            }
        }
    }
    
    sort(events.begin(), events.end());
    int open = 0;
    int begin;
    for (size_t i = 0; i < events.size(); ++i) {
        if (events[i].open) {
            if (open == 0) {
                begin = events[i].x;
            }
            ++open;
        } else {
            --open;
            if (open == 0) {
                ans += events[i].x - begin + 1;
            }
        }
    }

    fout << ans << '\n';
    return 0;
}