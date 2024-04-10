#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;



LL Calc(LL x){
    if (x > 1e7) return 1e18;
    return x * (x + 1) / 2 * 3;
}

int main(){
    LL n;
    cin >> n;
    if (n % 3 == 0){
        LL l = 1, r = n, ans = 0;
        while (l <= r){
            LL mid = l + r >> 1;
            if (Calc(mid * 3) <= n + mid * 3){
                ans = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        cout << ans <<endl;
    }else if (n % 3 == 2){
        LL l = 1, r = n, ans = 0;
        while (l <= r){
            LL mid = l + r >> 1;
            if (Calc(mid * 3 - 2) <= n + mid * 3 - 2){
                ans = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        cout << ans <<endl;
    }else{
        LL l = 1, r = n, ans = 0;
        while (l <= r){
            LL mid = l + r >> 1;
            if (Calc(mid * 3 - 1) <= n + mid * 3 - 1){
                ans = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        cout << ans <<endl;
    }


}