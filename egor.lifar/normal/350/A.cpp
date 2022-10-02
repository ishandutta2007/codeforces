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


int a[1000], b[1000];

 
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int ans = max(a[n - 1], a[0] * 2);
    if (ans >= b[0]) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}