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

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; ;i++){
        for (int j = 1; j <= i; j++)
            sum += j;
        if (sum > n){
            printf("%d\n",i - 1);
            return 0;
        }
    }
}