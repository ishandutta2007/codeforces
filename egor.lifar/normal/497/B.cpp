#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string.h>
#include <cmath>
#include <algorithm>


using namespace std;



int n;
int a[100001];
int d[100001];
int d1[100001];
vector<pair<int, int> > v;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] = (i > 0 ? d[i - 1]: 0);
        d1[i] = (i > 0 ? d1[i - 1]: 0);
        if (a[i] == 1) {
            d[i]++;
        } else {
            d1[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int k = 0;
        int k1 = 0;
        int j = -1;
        bool b = true;
        while (j + 1 < n) {
            int l = j + 1;
            int r = n - 1;
            while (l != r) {
               // cout << l << ' ' << r << endl;
                //cout << i << endl;
                int m = (l + r) / 2;
                if (d[m] - (j >= 0 ? d[j]: 0) < i) {
                    l = m + 1;
                } else {
                    if (d[m] - (j >= 0 ? d[j]: 0) == i) {
                        r = m;
                    } else {
                        r = m - 1;
                    }
                }
            }
           // cout << 'a' << endl;
            int l1 = j + 1;
            int r1 = n - 1;
            while (l1 != r1) {
              // cout << l1 << ' ' << r1 << endl;
             //   cout << i << endl;
                int m = (l1 + r1) / 2;
                if (d1[m] - (j >= 0 ? d1[j]: 0) < i) {
                    l1 = m + 1;
                } else {
                    if (d1[m] - (j >= 0 ? d1[j]: 0) == i) {
                        r1 = m;
                    } else {
                        r1 = m - 1; 
                    }        
                }
            }
         //cout << l1 << ' ' << i << endl;
            if (d1[l] - (j >= 0 ? d1[j]: 0) < i && d[l] - (j >= 0 ? d[j]: 0) < i) {
                b = false;
                break;
            }
            if (l <= l1 && d[l] - (j >= 0 ? d[j]: 0) >= i) {
                k++;
                j = l;
            } else {
                k1++;
                j = l1;
            }
           // cout << j << endl;
        }
      //  cout << i << ' ' << b << endl;
      // cout << k1 << ' ' << i << endl;
        if (b) {
            if (k > k1 && a[n - 1] == 2) {
                continue;
            }
            if (k < k1 && a[n - 1] == 1) {
                continue;
            }
            if (k != k1) {
                //cout << i << ' ' << max(k, k1) << endl;
                v.push_back(make_pair(max(k, k1), i));
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    return 0;
}