#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
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
const int N = 1e7 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;





int main(){
    LL a, b, ans = 0;
    cin >> a >> b;
    for (int i = 1; i < b; i++){
        ans += i * a % MOD + i * b % MOD * ((1 + a) * a / 2 % MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}