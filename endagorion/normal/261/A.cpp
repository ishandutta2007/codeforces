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

    int M;
    fin >> M;
    vector<int> sk(M);
    int toSk = 1e9;
    for (int i = 0; i < M; ++i) {
        int x;
        fin >> x;
        toSk = min(toSk, x);
    }
    int N;
    fin >> N;
    vector<int> pr(N);
    for (int i = 0; i < N; ++i) {
        fin >> pr[i];
    }
    sort(pr.rbegin(), pr.rend());
    int ans = 0, csk = 0, t = 0, l = 0;
    for (int i = 0; i < N; ++i) {
        if (l > 0) {
            --l;
            continue;
        }
        ans += pr[i];
        ++t;
        if (t == toSk) {
            t = 0;
            l = 2;            
        }
    }
    fout << ans << '\n';

	return 0;
}