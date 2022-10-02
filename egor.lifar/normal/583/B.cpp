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


int n;
int a[1001];
bool b[1001];


int main() {   
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int t = 0;
    int sum = 0;
    while (true) {
        bool bbb = true;
        bool bb1 = true;
        for (int j = t; j < n; j++) {
            if (!b[j] && a[j] <= sum) {
                sum++;
                t = j;
                if (bb1) {
                    ans++;
                }
                bb1 = false;
                b[j] = true;
                bbb = false;
            }   
        }
        bool bb = true;
        for (int j = t - 1; j >= 0; j--) {
            if (!b[j] && a[j] <= sum) {
                sum++;
                t = j;
                b[j] = true;
                if (bb) {
                    ans++;
                }
                bb = false;
                bbb = false;
            }   
        }
        if (bbb) {
            break;
        }
    }
    cout << ans - 1 << endl;
    return 0;
}