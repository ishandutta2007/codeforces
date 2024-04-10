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

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

int main() {
	fout.precision(10);
	fout << fixed;

    int N;
    fin >> N;
    vector< vector<int> > plays;
    for (int k = 0; (1 << k) < N; ++k) {
        plays.resize(k + 1);
        for (int i = 0; i < N; ++i) {
            if (i & (1 << k)) {
                plays[k].push_back(i + 1);
            }
        }
    }

    fout << plays.size() << '\n';
    for (int k = 0; k < plays.size(); ++k) {
        fout << plays[k].size();
        for (size_t i = 0; i < plays[k].size(); ++i) {
            fout << ' ' << plays[k][i];
        }
        fout << '\n';
    }

	return 0;
}