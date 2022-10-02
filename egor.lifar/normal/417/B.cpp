#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


map< pair<int, int> , bool> m;
int n, x[100001], k[100001];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> k[i];
    }
    for (int i = 0; i < n; i++) {
        if (x[i] != 0) {
            if (!m[make_pair(x[i] - 1, k[i])]) {
                cout << "NO" << endl;
                return 0;
            }
        }
        m[make_pair(x[i], k[i])] = true;
    }
    cout << "YES" << endl;
    return 0;
}