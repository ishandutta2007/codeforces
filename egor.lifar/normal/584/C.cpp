#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>


using namespace std;


int n, t;
string a, b;
string cc;


int main() {   
    cin >> n >> t;
    cin >> a >> b;
    cc.resize(n);
    vector<int> v;
    vector<int> v1;
    int c = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            c++;
            v.push_back(i);
        } else {
            c1++;
            v1.push_back(i);
        }
    }
    if (t >= c1) {
       // cout << "opa" << endl;
        for (int i = 0; i < (int)v1.size(); i++) {
            for (char aa = 'a'; aa <= 'z'; aa++) {
                if (aa != a[v1[i]] && aa != b[v1[i]]) {
                    cc[v1[i]] = aa;
                    break;
                }
            }
        }
        t -= c1;
        if (t > c) {
            cout << -1 << endl;
            return 0;
        }
        for (int i = 0; i < (int)v.size(); i++) {
            if (i + 1 <= t) {
                for (char aa = 'a'; aa <= 'z'; aa++) {
                    if (aa != a[v[i]] && aa != b[v[i]]) {
                        cc[v[i]] = aa;
                        break;
                    }
                }
            } else {
                cc[v[i]] = a[v[i]];
            }
        }
        cout << cc << endl;
        return 0;
    }
    int j = -1;
   // cout << c1 << endl;
    for (int i = 0; i < c1 - c1 % 2; i++) {
        if (i % 2 == 0) {
            if (t >= c1 - i && t <= c1 - i + c) {
                j = i;
                break;
            }
        }
        if (i % 2 == 0) {
            t--;
            cc[v1[i]] = a[v1[i]];
        } else {
            cc[v1[i]] = b[v1[i]];
        }
    }
    //cout << t << endl;
    if (t >= c1 % 2 && t <= c + c1 % 2 && j == -1) {
        j = c1 - c1 % 2;
    }
    if (j == -1) {
        cout << j << endl;
        return 0;
    }
    for (int i = j; i < c1; i++) {
        for (char aa = 'a'; aa <= 'z'; aa++) {
            if (aa != a[v1[i]] && aa != b[v1[i]]) {
                cc[v1[i]] = aa;
                t--;
                break;
            }
        }
    }
    for (int i = 0; i < (int)v.size(); i++) {
            if (t > 0) {
                t--;
                for (char aa = 'a'; aa <= 'z'; aa++) {
                    if (aa != a[v[i]] && aa != b[v[i]]) {
                        cc[v[i]] = aa;
                        break;
                    }
                }
            } else {
                cc[v[i]] = a[v[i]];
            }
    }
    cout << cc << endl;
    return 0;
}