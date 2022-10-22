#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    int n, p, l, r;
    cin >> n >> p >> l >> r;
    if (l == 1 && r == n){
         cout << "0\n";
         return 0;
    }

    if (l == 1){
        cout << abs(r - p) + 1 << '\n';
        return 0;
    }

    if (r == n){
        cout << abs(l - p) + 1 << '\n';
        return 0;
    }

    if (p < l){
        cout << (r - p) + 2 << '\n';
        return 0; 
    }

    if (r < p){
        cout << (p - l) + 2 << '\n';
        return 0;
    }

    int r1 = p - l;
    int r2 = r - p;
    cout << r - l + min(r1, r2) + 2 << '\n';

    return 0;
}