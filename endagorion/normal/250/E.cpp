#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

int main() {
	fout.precision(10);
	fout << fixed;

    int N, M;
    fin >> N >> M;
    vector<string> f(N);
    for (int i = 0; i < N; ++i) {
        fin >> f[i];
        f[i] = '#' + f[i] + '#';
    }
    int h = 0, l = 1, r = 1, x = 1, d = 1;
    long long ans = 0;
    while (h + 1 < N) {     
        int x;
        if (d == 1) {
            x = r;
        } else {
            x = l;
        }
        while (h + 1 < N && f[h + 1][x] == '.') {
            ++h;
            ++ans;
            if (d == 1) {
                l = r;
            } else {
                r = l;
            }
        }
        if (h + 1 == N) {
            break;
        }
        if (f[h][l - 1] == '#' && f[h][r + 1] == '#') {
            break;
        }

        if (d == 1) {
            if (f[h][r + 1] == '.') {
                ++r;
                ++ans;
            } else {
                d = -1;
                if (f[h][r + 1] == '+') {
                    f[h][r + 1] = '.';
                }
                ans += r - l + 1;
            }            
        } else {
            if (f[h][l - 1] == '.') {
                --l;
                ++ans;
            } else {
                d = 1;
                if (f[h][l - 1] == '+') {
                    f[h][l - 1] = '.';
                }
                ans += r - l + 1;
            }
        }
    }

    if (h + 1 == N) {
        fout << ans << '\n';
    } else {
        fout << "Never\n";
    }

	return 0;
}