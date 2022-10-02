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
 

using namespace std;


int n;
int a[3001];
int d[9000001];


int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                cnt++;
            }
        }
    }
    for (int i = 0; i <= cnt; i++) {
        if (i == 0) {
            d[i] = 0;
        } else {
            if (i == 1) {
                d[i] = 1;
            } else {
                d[i] = d[i - 2] + 4;
            }
        }
    }
    cout << d[cnt] << endl;
    return 0;
}