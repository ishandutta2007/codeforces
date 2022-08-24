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

int main() {
    int n;
    fin >> n;
    int minx, miny, maxx, maxy, minsum, maxsum, mindiv, maxdiv;
    minx = miny = minsum = mindiv = 1000000000;
    maxx = maxy = maxsum = maxdiv = -1000000000;
    for (int i = 0; i < n; ++i) {
        int x, y;
        fin >> x >> y;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
        minsum = min(minsum, x + y);
        maxsum = max(maxsum, x + y);
        mindiv = min(mindiv, x - y);
        maxdiv = max(maxdiv, x - y);
    }
    --minx;
    --miny;
    --minsum;
    --mindiv;
    ++maxx;
    ++maxy;
    ++maxsum;
    ++maxdiv;
    int ans = 2 * (maxx - minx) + 2 * (maxy - miny);
    ans -= (maxx + maxy - maxsum);
    ans -= (minsum - (minx + miny));
    ans -= (maxx - miny - maxdiv);
    ans -= (mindiv - (minx - maxy));
    fout << ans << '\n';
        
    return 0;
}