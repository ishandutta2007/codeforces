#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <time.h>

using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    for (int x = 0; a * x <= n; ++x){
        if ((n - a * x) % b == 0){
            int y = (n - a * x) / b;

            for (int i = 0; i < x; ++i){
                for (int j = i * a; j < i * a + a - 1; ++j){
                    cout << j + 2 << ' ';
                }
                cout << i * a + 1 << ' ';
            }

            int add = x * a;

            for (int i = 0; i < y; ++i){
                for (int j = i * b; j < i * b + b - 1; ++j){
                    cout << add + j + 2 << ' ';
                }
                cout << add + i * b + 1 << ' ';
            }

            cout << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}