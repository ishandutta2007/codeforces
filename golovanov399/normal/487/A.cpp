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

int f(int a, int b){
    return (a + b - 1) / b;
}

int main(){

    int h[2], a[2], d[2];
    int H, A, D;
    for (int i = 0; i < 2; i++){
        cin >> h[i] >> a[i] >> d[i];
    }
    cin >> H >> A >> D;
    int mn = 0;
    if (a[0] - d[1] <= 0){
        mn += (d[1] - a[0] + 1) * A;
        a[0] = d[1] + 1;
    }
    int ans = mn + max(0, a[1] - d[0]) * D;
    for (int i = 0; i < a[1] - d[0]; i++){
        for (int j = 0; j * A < ans; j++){
            int x = f(h[1], a[0] - d[1] + j) * (a[1] - d[0] - i) + 1;
            if (x < h[0]) x = h[0];
            ans = min(ans, i * D + j * A + (x - h[0]) * H + mn);
            if (f(h[1], a[0] - d[1] + j) < f(h[0], a[1] - d[0] - i))
                break;
        }
    }
    if (a[1] <= d[0]){
        ans = min(ans, mn);
    }
    cout << ans << "\n";

    return 0;
}