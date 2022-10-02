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

 
string s[1000];
set< pair<int, int> > s1;
bool b[1000][1000];


int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'S') {
                s1.insert(make_pair(i, j));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        bool t = true;
        for (int j = 0; j < n; j++) {
            if (s1.find(make_pair(j, i)) != s1.end()) {
                t = false;
                break;
            }
        }
        if (t) {
            ans += n;
            for (int j = 0; j < n; j++) {
                b[j][i] = true;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        bool t = true;
        for (int i = 0; i < m; i++) {
            if (s1.find(make_pair(j, i)) != s1.end()) {
                t = false;
                break;
            }
        }
        if (t) {
            int k = m;
            for (int i = 0; i < m; i++) {
                if (b[j][i]) {
                    k--;
                }
            }
            ans += k;
        }
    }
    cout << ans << endl;
    return 0;
}