#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    long long n;
    cin >> n;
    if (n == 1) cout << 1;
    else
    if (n == 2) cout << 2;
    else
    if (n % 2 == 0){
        long long ans = 0;
        ans = max(n * (n-1) * (n-2) / 2, (n-1) * (n-2) * (n-3));
        if (n % 3 != 0) ans = max(ans, n * (n-1) * (n-3));
        cout << ans;
    }
    else cout << n * (n-1) * (n-2);
}