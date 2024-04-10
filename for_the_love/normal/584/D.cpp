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

#define REP(i, n) for (int i=0;i<n;++i)
#define ECH(it, A) for (__typeof(A.begin()) it=A.begin(); it != A.end(); ++it )

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e2 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

bool check(int a){
    if (a == 1) return 0;
    for (int i = 2; i * i <= a; i++)
    if (a % i == 0) return 0;
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    if (check(n)){
        printf("%d\n%d\n", 1, n);
        return 0;
    }
    for (int a = 2; ;a++){
        int t = check(n - a);
        if (!t) continue;
        if (check(a)){
            printf("%d\n%d %d\n", 2, a, n - a);
            return 0;
        }
        for (int b = 2; b <= a / 2; b++)
        if (check(b) && check(a - b)){
            printf("%d\n%d %d %d\n", 3, n - a, b, a - b);
            return 0;
        }
    }

}