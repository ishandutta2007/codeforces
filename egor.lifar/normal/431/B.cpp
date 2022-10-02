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


int a[5];
int s[5][5];
long long ans = 0;


int main() {
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> s[i][j];
        }
    }
    do {
        long long t = 0;    
        for (int i = 0; i < 5; i++) {
            int j = i;
            while (j < 4) {
                t += s[a[j] - 1][a[j + 1] - 1] + s[a[j + 1] - 1][a[j] - 1];
                j += 2;
            }
        }
        ans = max(ans, t);
    } while (next_permutation(a, a + 5));
    cout << ans << endl;
    return 0;
}