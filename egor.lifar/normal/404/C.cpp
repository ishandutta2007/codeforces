#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>


using namespace std;


map<int, int> m;
int n, k;
int s = -1;
int j = 0;
vector<int> v[100000]; 
int s1 = 0;
vector<int> v1[100000];

 
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m[a]++;
        v1[a].push_back(i);
        s = max(s, a);
    }
    if (m[0] > 1 || m[0] == 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= s; i++) {
        if (k == 1 && i != 1) {
            cout << -1 << endl;
            return 0;
        }
        if (m[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
        j = 0;
        int k1 = 0;
        for (int g = 0; g < m[i]; g++) {
            k1++;
            if (k1 <= k - 1 || (i - 1 == 0 && k1 <= k)) {
                s1++;
                v[v1[i - 1][j]].push_back(v1[i][g]);
            } else {
                j++;
                if (j >= m[i - 1]) {
                    cout << -1 << endl;
                    return 0;
                }
                k1 = 1;
                s1++;
                v[v1[i - 1][j]].push_back(v1[i][g]);
            }
        }

    }
    cout << s1 << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << i + 1 << ' ' << v[i][j] + 1 << endl;
        }
    }
    return 0;
}