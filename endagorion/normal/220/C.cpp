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

    int N;
    fin >> N;
    vector<int> a(N), b(N), pa(N), pb(N);
    for (int i = 0; i < N; ++i) {
        fin >> a[i];
        --a[i];
        pa[a[i]] = i;
    }
    for (int i = 0; i < N; ++i) {
        fin >> b[i];
        --b[i];
        pb[b[i]] = i;
    }

    vector<int> d(N, N + 1);
    multiset<int> inc, dec;
    vector< vector<int> > match(N);
    for (int i = 0; i < N; ++i) {
        if (pa[i] < pb[i]) {
            inc.insert(pb[i] - pa[i]);
        } else {
            dec.insert(pa[i] - pb[i]);
        }
    }

    vector<int> res(N);
    for (int i = 0; i < N; ++i) {
        int ans = N;
        if (!inc.empty()) {
            ans = *inc.begin() + i;
        }
        if (!dec.empty()) {
            ans = min(ans, *dec.begin() - i);
        }
        //fout << ans << '\n';
        res[(N - i) % N] = ans;
        while (!dec.empty() && *dec.begin() == i) {
            dec.erase(dec.begin());
            inc.insert(-i);
        }
        int shift = b[N - i - 1];
        inc.erase(inc.find(pb[shift] - pa[shift]));
        dec.insert(N - pb[shift] + pa[shift]);
    }

    for (int i = 0; i < N; ++i) {
        fout << res[i] << '\n';
    }

	return 0;
}