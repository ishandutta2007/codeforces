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
string s;
int l[3000];
int r[3000];
bool b[3000];


int main() {
    cin >> n;
    cin >> s;
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            j = i;
        }
        if (s[i] == 'L') {
            l[i] = j;
        }
    }
    j = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'L') {
            j = i;
        }
        if (s[i] == 'R') {
            r[i] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            if (r[i] == -1) {
                for (int j = i; j < n; j++) {
                    b[j] = true;
                }
            } else {
                for (int j = i; j <= r[i]; j++) {
                    b[j] = true;
                }
                if ((r[i] - i + 1) % 2 == 1) {
                    b[(i + r[i]) / 2 + 1] = false;
                }
            }
        } else {
            if (s[i] == 'L') {
                if (l[i] == -1) {
                    for (int j = 0; j <= i; j++) {
                        b[j] = true;
                    }
                } else {
                    for (int j = i; j >= l[i]; j--) {
                        b[j] = true;
                    }
                    if ((i - l[i] + 1) % 2 == 1) {
                        b[(l[i] + i) / 2 + 1] = false;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!b[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;//
}