#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

long long ans, n, m, a[155555];
int main(){
    cin >> n >> m;
    a[0] = 1;
    for (int i = 1; i <= m; i++){
        cin >> a[i];
        if (a[i] < a[i - 1]) ans += a[i] + n - a[i - 1];
        else ans += a[i] - a[i - 1];
    }
    cout << ans << endl;
}