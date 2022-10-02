#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>


using namespace std;


int n, m;
map<pair<int, int>, bool> d;


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        d[make_pair(a - 1, b - 1)] = true;
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i);
        int j = i;
        while (j > 0 && d[make_pair(v[j - 1], v[j])]) {
            swap(v[j - 1], v[j]);
            j--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}