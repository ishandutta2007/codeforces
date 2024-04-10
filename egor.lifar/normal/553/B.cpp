#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>



using namespace std;


int c[55];
int n;
long long l;
long long d[51];


int main() {
    cin >> n >> l;
    d[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            d[i] = 1;
            continue;
        }
        if (i == 2) {
            d[i] = 2;
            continue;
        } 
        d[i] = 2LL * d[i - 2] + d[i - 3];
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i + 1);
    }   
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = n; i >= 1; i-= 2) {
        if ((int)v.size() == 1) {
            cout << v[0] << endl;
            return 0;
        }
        if ((int)v.size() == 0) {
            return 0;
        }
        pair<int, int> p = make_pair(v[0], v[1]);
        if (i >= 2 && d[i - 2] < l) {
            l -= d[i - 2];
            if (i >= 3 && d[i - 3] < l) {
                l -= d[i - 3];
                p = make_pair(v[1], v[0]);
            } else {
                if (i >= 3) {
                    p = make_pair(v[0], v[2]);
                } else {
                    p = make_pair(v[1], v[0]);
                }
            }
        }
       // cout << l << endl;
        cout << p.first << endl;
        cout << p.second << endl;
        vector<int> v1;
        for (int j = 0; j < (int)v.size(); j++) {
            if (v[j] != p.first && v[j] != p.second) {
                v1.push_back(v[j]);
            //    cout << v[j] << ' ';
            }
        }
     //   cout << endl;
        v = v1;
    }
    return 0;
}