#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int n,x,a[1005],sum,res;

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];    
    }
    if (sum < 0) sum = -sum;
    res = sum / x;
    if (sum % x) ++res;
    cout << res;
    
    return 0;
}