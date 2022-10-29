#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m, cnt[1001], x;

int main(){
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++){
        int mx = -1, p;
        for (int j = 0; j < m; j++){
            scanf("%d", &x);
            if (x > mx){
                mx = x;
                p = j;
            }
        }
        cnt[p]++;
    }

    int mx = -1, p;
    for (int i = 0; i < m; i++)
    if (cnt[i] > mx){
        mx = cnt[i];
        p = i;
    }
    printf("%d\n", p + 1);


}