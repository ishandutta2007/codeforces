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

int gcd(int x, int y){
    while (y > 0){
        x %= y;
        swap(x, y);
    }
    return x;
}

int main(){

    int n, k;
    cin >> n >> k;
    cout << (6 * (n - 1) + 5) * k << "\n";
    for (int i = 0; i < n; i++){
        cout << (6 * i + 1) * k << " " << (6 * i + 3) * k << " " << (6 * i + 5) * k << " " << (6 * i + 2) * k << "\n";
    }

    return 0;
}