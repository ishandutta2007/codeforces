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


int n, k;
vector< pair<int, int> > v;
int b[1002][1002];


int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int s = 0;
        for (int j = 1; j <= n; j++) {
            if (!b[j][i] && j != i) {
                v.push_back(make_pair(i, j));
                s++;
                b[i][j] = true;
            }
            if (s == k) {
                break;
            }
        }
        if (v.size() < i * k) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << n * k << endl;
    for (int i = 0; i < v.size(); i++) {
        printf("%d %d\n", v[i].first, v[i].second);
    }
    return 0;
}