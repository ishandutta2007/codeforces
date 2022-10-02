#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>


using namespace std;


int n, m;
pair<int, int> x[100000];
int l[100000], r[100000];
int a[100000];


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
    }
    sort(x, x + n);
    for (int i = 0; i < n; i++) {
        a[x[i].second] = i % 2;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}