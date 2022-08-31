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
    vector<pair<int, int> > l(N);
    for (int i = 0; i < N; ++i) {
        fin >> l[i].first;
        l[i].second = i;
    }
    sort(l.begin(), l.end());
    vector< vector<string> > rest(1001);
    rest[0].push_back("");
    vector<string> ans(N);
    bool ok = true;
    for (size_t i = 0; i < l.size(); ++i) {
        int c = l[i].first;
        while (c >= 0 && rest[c].empty()) {
            --c;
        }
        if (c < 0) {
            ok = false;
            break;
        }
        for (int j = c; j < l[i].first; ++j) {
            rest[j + 1].push_back(rest[j].back() + '1');
            rest[j + 1].push_back(rest[j].back() + '0');
            rest[j].pop_back();
        }
        ans[l[i].second] = rest[l[i].first].back();
        rest[l[i].first].pop_back();
    }

    if (ok) {
        fout << "YES\n";
        for (int i = 0; i < N; ++i) {
            fout << ans[i] << '\n';
        }
    } else {
        fout << "NO\n";
    }

	return 0;
}