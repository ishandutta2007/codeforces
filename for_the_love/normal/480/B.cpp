#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
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

int n, l, x, y, a[N];
map <int, int> S;
int main(){
    int f1 = 0, f2 = 0;
    scanf("%d%d%d%d", &n, &l, &x, &y);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        S[a[i]] = 1;
        if (S[a[i] - x]) f1 = 1;
        if (S[a[i] - y]) f2 = 1;
    }
    if (!f1 && !f2){
        int flag = 0;
        for (int i = 0; i < n; i++){
            if (S[a[i] - x - y]){
                printf("%d\n%d\n", 1, a[i] - x);
                flag = 1;
                break;
            }
            if (S[a[i] - (y - x)] && a[i] + x <= l){
                printf("%d\n%d\n", 1, a[i] + x);
                flag = 1;
                break;
            }
            if (S[a[i] + (y - x)] && a[i] - x >= 0){
                printf("%d\n%d\n", 1, a[i] - x);
                flag = 1;
                break;
            }
        }

        if (!flag){
            puts("2");
            printf("%d %d\n", x, y);
        }
    }else if (f1 && f2) puts("0");
    else{
        printf("%d\n", 1);
        if (!f1) printf("%d\n", x); else printf("%d\n", y);
    }
}