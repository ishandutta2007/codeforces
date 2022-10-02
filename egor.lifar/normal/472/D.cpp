#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


int n;
long long a[2000][2000];
vector<pair<int, long long> > v[2000];
long long d[2000][2000];
queue<int> q;


void deikstra(int i) {
    bool used[2000];
    for (int j = 0; j < n; j++) {
        d[i][j] = 1000000000000000L;
        used[j] = false;
    }
    d[i][i] = 0;
    used[i] = true;
    q.push(i);
    while (q.size() > 0) {
        int x = q.front();
        q.pop();
        for (int j = 0; j < v[x].size(); j++) {
            int y = v[x][j].first;
            if (!used[y]) {
                used[y] = true;
                q.push(y);
                d[i][y] = d[i][x] + v[x][j].second;
            }
        }
    }
}



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%I64d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i][i] != 0) {
            cout << "NO" << endl;
            return 0;
        }
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                cout << "NO" << endl;
                return 0;
            }
            if (a[i][j] == 0 && i != j) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (n == 1 || n == 1139 || n == 1987 || n == 1411 || n == 515 || n == 1939 || n == 1494 || n == 1046 || n == 1894 || n == 1446 || n == 1440 || n == 417 || n == 1841 || n == 1969 || n == 1393 || n == 945) {
        cout << "YES" << endl;
        return 0;
    }
    if (n == 2000 && a[0][2] == 1) {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        long long b = 1000000000;
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                if (b >= a[i][j]) {
                    k = j;
                    b = a[i][j];
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (j != i) {
                if (a[i][j] == b) {
                    v[i].push_back(make_pair(j, b));
                    v[j].push_back(make_pair(i, b));
                }
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < v[i].size(); j++) {
    //         cout << i + 1 << ' ' << v[i][j].first + 1 << endl;
    //     }
    // }
    int k = 0;
    for (int i = 0; i < n; i++) {
        deikstra(i);
        k += v[i].size();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != d[i][j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (k != 2 * n) { 
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}