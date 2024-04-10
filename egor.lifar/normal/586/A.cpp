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
#include <unordered_set>
#include <bitset>


using namespace std;


int n;
int a[100001];
int l1 = 0;

               
int main() {
    cin >> n;
    int l = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            l1 = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            l = i;
        }
        if (l != -1) {
            if (a[i] == 0) {
                if (!(i - l >= 2 || (i < n - 1 && a[i + 1] == 0))) {
                    ans++;
                }
            } else {
                ans++;
            }
        }
        if (i == l1) {
            break;
        }
    }
    cout << ans << endl;
    return 0;   
}