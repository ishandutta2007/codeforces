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
const int N = int(1e5) + 9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int gao(int n){
    int ret = 0;
    for (int i = 1; i <= n; i++){
        int cnt = 0, x = i;
        while (x){
            x /= 10;
            cnt++;
        }
        ret += cnt;
    }
    return ret;
}


int main() {
    LL n;
    cin >> n;
    LL ans = 0, x = 1, sum = 0;
    while (1){
        if (x * 10 > n){
            ans += n - x + 1;
            break;
        }
        ans += n - x + 1;
        x *= 10;
    }
    cout << ans << endl;
    //cout << gao(n) << endl;
}