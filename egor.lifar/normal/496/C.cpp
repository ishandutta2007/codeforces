#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string.h>
#include <cmath>
#include <algorithm>


using namespace std;



int n, m;
string s[101];
int ans = 1000;


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        vector<pair<int, int> > v;
        int l = 0;
        int k = 1;
        bool b = true;
        for (int j = 1; j < n; j++) {
            if (s[j][i] < s[j - 1][i]) {
                b = false;
            }
            if (s[j][i] == s[j - 1][i]) {
                k++;
            } else {
                v.push_back(make_pair(l, l + k - 1));
                l = j;
                k = 1;
            }
        }
        if (!b) {
            continue;
        }
      //  cout << i << endl;
        v.push_back(make_pair(l, l + k - 1));
        //cout << v.size() << endl;
        int ans1 = i;
        for (int j = i + 1; j < m; j++) {
            b = true;
            for (int k = 0; k < (int)v.size(); k++) {
                //cout << v[k].first << ' ' << v[k].second << endl;
                for (int g = v[k].first + 1; g <= v[k].second; g++) {
                    if (s[g][j] < s[g - 1][j]) {
                        b = false;
                    }
                }
            }
            //cout << j << ' ' << b << endl;
            //cout << v.size() << endl;
            if (!b) {
                ans1++;
            } else {
                vector<pair<int, int> > v1;
                for (int k = 0; k < (int)v.size(); k++) {
                    int t = 1;
                    int l = v[k].first;
                    for (int g = v[k].first + 1; g <= v[k].second; g++) {
                        if (s[g][j] == s[g - 1][j]) {
                            t++;
                        } else {
                            v1.push_back(make_pair(l, l + t - 1));
                            t = 1;
                            l = g;
                        }
                    }
                    v1.push_back(make_pair(l, l + t - 1));
                }
                v = v1;
            }
        }
        ans = min(ans, ans1);
    }
    ans = min(ans, m);
    cout << ans << endl;
    return 0;
}