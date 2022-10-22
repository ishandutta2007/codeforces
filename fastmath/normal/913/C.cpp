#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <random>
#include <time.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;
#define int long long

const int LG = 40;
const int INF = 2e18 + 7;

int a[LG];

signed main(){  
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < LG; ++i){
        a[i] = INF;
    }

    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i){
        cin >> a[i];     
    }

    for (int i = 1; i < LG; ++i){
        a[i] = min(a[i], a[i - 1] * 2);
    }

    int ans = 0;
    for (int i = 0; i < LG; ++i){
        if ((l >> i) & 1){
            ans += a[i];
        }
    }

    for (int i = LG - 1; i >= 1; --i){
        int new_ans = 0;
        for (int j = LG - 1; j >= i; --j){
            if ((l >> j) & 1){
                new_ans += a[j];
            }
        }
        new_ans += a[i];
        ans = min(ans, new_ans);
    }

    cout << ans << '\n';
    return 0;
}