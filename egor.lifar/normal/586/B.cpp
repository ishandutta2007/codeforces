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
int a[2][101];
int b[101];
               
int main() {
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n - 1; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = 1000 * 1000 * 1000;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = 0, sum1 = 0;
            for (int k = 0; k < i; k++) {
                sum += a[0][k];
            }
            sum += b[i];
            for (int k = i; k < n - 1; k++) {
                sum += a[1][k];
            }
            for (int k = 0; k < j; k++) {
                sum1 += a[0][k];
            }
            sum1 += b[j];
            for (int k = j; k < n - 1; k++) {
                sum1 += a[1][k];
            }
            ans = min(ans, sum + sum1);
        }
    }
    cout << ans << endl;
    return 0;   
}