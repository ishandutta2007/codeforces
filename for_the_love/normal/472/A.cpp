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

int v[N];
int main(){
    for (int i = 2; i <= 1000000; i++) if (!v[i])
    for (int j = i + i; j <= 1000000; j += i) v[j] = 1;
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    if (v[i] && v[n - i]){
        printf("%d %d\n", i, n - i);
        break;
    }
}