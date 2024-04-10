#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int v;
int d[10];
pair<int, int> p = make_pair(1000000, 0);


int main() {
    cin >> v;
    for (int i = 1; i <= 9; i++) {
        cin >> d[i];
        p = min(p, make_pair(d[i], i));
    }
    int s = v / p.first;
    v = v % p.first;
    vector<int> ans;
    for (int i = 0; i < s; i++) {
        ans.push_back(p.second);
    }
    for (int i = 0; i < s; i++) {
        v += p.first;
        for (int j = 9; j >= 1; j--) {
            if (v >= d[j]) {
                ans[i] = j;
                v -= d[j];
                break;
            }
        }
    }
    for (int i = 0; i < s; i++) {
        cout << ans[i];
    }
    if (s == 0) {
        cout << -1 << endl;
    }
    cout << endl;
    return 0;
}