#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    if (a < b) swap(a, b);
    printf("%d %d\n", b, (a - b) / 2);
}