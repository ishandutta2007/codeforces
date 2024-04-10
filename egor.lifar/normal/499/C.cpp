    
#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;


long long x1, y1, x2, y2;
int n;
long long a[100000], b[100000], c[100000];


int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        if ((a[i] * x1 + b[i] * y1 + c[i] > 0LL && a[i] * x2 + b[i] * y2 + c[i] < 0LL) || (a[i] * x1 + b[i] * y1 + c[i] < 0LL && a[i] * x2 + b[i] * y2 + c[i] > 0LL)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}