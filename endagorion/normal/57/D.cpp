#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector< string > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector< int > rows(n), cols(m), brows(n, -1), bcols(m, -1);
    long long total = 0;
    double res = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') {
                ++rows[i];
                ++cols[j];
                ++total;
            } else {
                brows[i] = j;
                bcols[j] = i;
            }
        } 
    }

    res /= (total * total);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res += 1.0 * rows[i] * rows[j] * abs(i - j) / (total * total);
        }
        if (brows[i] == -1) {
            continue;
        }
        int k = i;
        int maxb = -1;
        while (k < n && brows[k] > maxb) {
            res += 4.0 * brows[i] * (m - brows[k] - 1) / (total * total);
            maxb = brows[k];
            ++k;
        }
        k = i - 1;
        maxb = brows[i];
        while (k >= 0 && brows[k] > maxb) {
            res += 4.0 * brows[i] * (m - brows[k] - 1) / (total * total);
            maxb = brows[k];
            --k;
        }
        
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            res += 1.0 * cols[i] * cols[j] * abs(i - j) / (total * total);
        }
        if (bcols[i] == -1) {
            continue;
        }
        int k = i;
        int maxb = -1;
        while (k < m && bcols[k] > maxb) {
            res += 4.0 * bcols[i] * (n - bcols[k] - 1) / (total * total);
            maxb = bcols[k];
            ++k;
        }
        k = i - 1;
        maxb = bcols[i];
        while (k >= 0 && bcols[k] > maxb) {
            res += 4.0 * bcols[i] * (n - bcols[k] - 1) / (total * total);
            maxb = bcols[k];
            --k;
        }        
    }

    printf("%.10lf\n", res);
    
    return 0;
}