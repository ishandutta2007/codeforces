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
const int N = 1e2 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int main(){
    int n, t;
    scanf("%d%d", &n, &t);
    if (n == 1){
        if (t == 10) puts("-1");
        else printf("%d\n", t);
        return 0;
    }
    int ten = 1;
    for (int i = 1; i < n; i++) ten = ten * 10 % t;
    int ans = -1;
    for (int i = 0; i < 10; i++)
    if ((i + ten) % t == 0){
        ans = i;
        break;
    }
    if (ans == -1) puts("-1");
    else{
        printf("1");
        for (int i = 2; i < n; i++)
            printf("0");
        printf("%d", ans);
    }
}