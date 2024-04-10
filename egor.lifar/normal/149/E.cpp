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
#include <cstring>
#include <cmath>


using namespace std;


int n;
string s;
string a[101001];
int z[101001];
int z3[101001];
int z1[101001];
int z2[101001];
int d[101001];


int main() {
    cin >> s;
    n = (int)s.size();
   // cout << s << endl;
    int m;
    cin >> m;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        string s1;
        s1 = a[i] + "*" + s + "*";
        int n1 = (int)s1.size();
        for (int j = 0; j < n1; j++) {
            z[j] = 0;
            z1[j] = 0;
            z2[j] = 0;
            z3[j] = 0;
            d[j] = 0;
        }
        z[0] = 0;
        int l = 0, r = 0;
        for (int i1 = 1; i1 < n1; i1++) {
            z[i1] = max(0, min(r - i1, z[i1 - l]));
            while (s1[i1 + z[i1]] == s1[z[i1]]) {
                z[i1]++;
            }
            if (i1 + z[i1] >= r) {
                l = i1;
                r = i1 + z[i1];
            }
        //cout << z[i] << endl;
         }//
        for (int j = (int)a[i].size() + 1; j < n1 - 1; j++) {
            z3[j - (int)a[i].size() - 1] = z[j];
        }
        s1 = s;
        reverse(s1.begin(), s1.end());
        string s2 = a[i];
        reverse(s2.begin(), s2.end());
        s1 = s2 + "*" + s1 + "*";
        z1[0] = 0;
        l = 0, r = 0;
        for (int i1 = 1; i1 < n1; i1++) {
            z1[i1] = max(0, min(r - i1, z1[i1 - l]));
            while (s1[i1 + z1[i1]] == s1[z1[i1]]) {
                z1[i1]++;
            }
            if (i1 + z1[i1] >= r) {
                l = i1;
                r = i1 + z1[i1];
            }
        //cout << z[i] << endl;
         }//
        for (int j = (int)a[i].size() + 1; j < n1 - 1; j++) {
            z2[n - (j - (int)a[i].size() - 1) - 1] = z1[j];
        }
        if ((int)a[i].size() < 2) {
            continue;
        }
        // for (int j = 0; j < n; j++) {
        //     cout << z3[j] << ' ';
        // }
        // cout << endl;
        for (int j = n - 1; j >= 0; j--) {
          //  cout << p3[j] << ' ';
            d[j] = max((j < n - 1 ? d[j + 1]: 0), z2[j]);
        }       
     //   cout << endl;
        for (int j = 0; j < n; j++) {
            if (j + (int)a[i].size() - 1 >= n) {
                continue;
            }
            if (z3[j] >= 1 && d[j + (int)a[i].size() - 1] >= max(1, (int)a[i].size() - z3[j])) {
                ans++;
            //    cout << i + 1 << endl;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}