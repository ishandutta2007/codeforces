#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

    int n;
    cin >> n;
    long long l, r;
    for (int i = 0; i < n; i++){
        cin >> l >> r;
        long long k = 1ll << 60;
        if (l == r){
            cout << l << "\n";
            continue;
        }
        while ((l & k) == (r & k)) k >>= 1;
        if ((r & ((k << 1) - 1)) == ((k << 1) - 1)) cout << r << "\n"; else
        cout << l - (l & (k - 1)) + k - 1 << "\n";
    }

    return 0;
}