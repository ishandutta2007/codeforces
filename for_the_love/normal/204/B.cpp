#include <map>
#include <set>
#include <cmath>
#include <queue>
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
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


map <int, int> :: iterator it;


map <int, int> S1, S2, S3;

int main(){
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &x, &y);
        S1[x]++; S2[y]++;
        if (x == y) S3[x]++;
    }
    int ans = INF;
    for (it = S1.begin(); it != S1.end(); it++){
        int x = it -> first;
        if (max(0, (n + 1) / 2 - it -> second) <= (S2[x] - S3[x])) ans = min(ans, max(0, (n + 1) / 2 - it -> second));
    }
    for (it = S2.begin(); it != S2.end(); it++){
        int x = it -> first;
        if (max(0, (n + 1) / 2 - S1[x]) <= (S2[x] - S3[x])) ans = min(ans, max(0, (n + 1) / 2 - S1[x]));
    }
    if (ans == INF) puts("-1");
    else  cout << ans << endl;

}