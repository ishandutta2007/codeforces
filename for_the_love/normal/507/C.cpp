#include <set>
#include <map>
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
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

LL h, n, a[N];

int main(){
    cin >> h >> n;
    LL t = n;
    a[0] = 0;
    for (int i = h; i >= 1; i--){
        a[i] = t & 1;
        t = (t + 1) / 2;
    }
    LL ans = 0;
    for (int i = 1; i <= h; i++){
        if (a[i] == a[i - 1]) ans += (1LL << (h - i + 1)) - 1;
        ans++;
    }

    cout << ans << endl;
}