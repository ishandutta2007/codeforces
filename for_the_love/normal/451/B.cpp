#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
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
typedef pair <int, int> PI;

const DB eps = 1e-6;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


int n, a[N];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 1, x, y, cnt = 0, flag = 0;
    a[n + 1] = INF;
    for (int i = 2; i <= n; i++){
        if (a[i] > a[i - 1]){
            if (i - l > 1){
                x = l, y = i - 1;
                cnt++;
                if (a[i - 1] < a[l - 1] || a[l] > a[i]) flag = 1;
            }
            l = i;
        }
    }
    if (n - l > 0){
        x = l, y = n;
        cnt++;
        if (a[n] < a[l - 1]) flag = 1;
    }
    if (flag) puts("no");
    else if (!cnt) printf("yes\n1 1\n"); else if (cnt == 1) printf("yes\n%d %d\n", x, y); else puts("no");
}