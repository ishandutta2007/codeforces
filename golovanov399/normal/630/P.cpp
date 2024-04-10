#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, r;
    cin >> n >> r;
    cout << setprecision(10) << fixed;
    double pi = acos(-1);
    cout << n * 0.5 * r * r * sin(2 * pi / n) - n * sin(pi / n) * r * sin(pi / n) * r * tan(pi / 2 - 1.5 * (pi / n));
    
    return 0;
}