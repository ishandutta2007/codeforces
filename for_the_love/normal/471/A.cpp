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
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int a[10], cnt[10];
int main(){
    for (int i = 0; i < 6; i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    int p = 0;
    for (int i = 1; i <= 9; i++)
    if (cnt[i] >= 4) p = i;
    if (!p) puts("Alien");
    else{
        if (cnt[p] == 6){
            puts("Elephant");
            return 0;
        }
        int flag = 0;
        for (int i = 1; i <= 9; i++)
        if (i != p && cnt[i]){
            if (cnt[i] == 2) flag = 1;
        }
        if (!flag) puts("Bear"); else puts("Elephant");
    }
}