#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

struct DSF {
    vector<size_t> parents;

    explicit DSF(size_t n) : parents(n)  {
        for (size_t i = 0; i < n; ++i) {
            parents[i] = i;
        }
    }

    size_t find(size_t n) {
        if (parents[n] != n) {
            parents[n] = find(parents[n]);
        }

        return parents[n];
    }

    void union_(size_t r1, size_t r2) {
        r1 = find(r1);
        r2 = find(r2);
        parents[r1] = r2;
    }
};

int main() {
    ios::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    DSF dsf(n);
    for (size_t i = 0; i < m; ++i) {
        size_t j;
        cin >> j;
        if (j == 0) {
            continue;
        }

        vector<size_t> nodes(j);
        for (size_t k = 0; k < j; ++k) {
            cin >> nodes[k];
            nodes[k]--;
        }

        for (size_t k = 0; k < j - 1; ++k) {
            dsf.union_(nodes[k], nodes[k + 1]);
        }
    }

    vector<size_t> sizes(n);
    for (size_t i = 0; i < n; ++i) {
        sizes[dsf.find(i)]++;
    }

    for (size_t i = 0; i < n; ++i) {
        cout << sizes[dsf.find(i)] << ' ';
    }

    cout << '\n';

    return 0;
}