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


int gcd(int a, int b){if (!b) return a; return gcd(b, a % b);}

bool check(int a, int b, int c, int d){
    if (gcd(a, b) != 1 || gcd(a, c) != 1 || gcd(a, d) != 1 || gcd(b, c) != 1 || gcd(b, d) != 1 || gcd(c, d) != 1) return 1;
    return 0;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", (n * 6 - 1) * k);
    int t = 1;
    for (int i = 1; i <= n; i++){
        int a = t, b = t + 1, c = t + 2, d = t + 4;
        printf("%d %d %d %d\n", a * k, b * k, c * k, d * k);
        t += 6;
    }
}