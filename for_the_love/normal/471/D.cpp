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
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int next[N], s[N], t[N], a[N], b[N];

void get_next(int t[], int n){
    int j = 1, k = 0;
    while (j <= n){
        if (!k || t[j] == t[k]){
            j++, k++;
            next[j] = k;
        }else k = next[k];
    }
}
int Kmp(int s[], int t[], int n, int m){
    int i = 1, j = 1, ret = 0;
    while (i <= n){
        if (!j || s[i] == t[j]){
            i++, j++;
        }else j = next[j];
        if (j == m) ret++;
    }
    return ret;
}
int main(){
    int n, w;
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    n--;
    for (int i = 1; i <= n; i++) s[i] = a[i] - a[i - 1];
    for (int i = 0; i < w; i++) scanf("%d", &a[i]);
    if (w == 1){
        printf("%d\n", n + 1);
        return 0;
    }
    w--;
    for (int i = 1; i <= w; i++) t[i] = a[i] - a[i - 1];
    t[++w] = INF;
    get_next(t, w);
    //for (int i = 1; i <= w + 1; i++) printf("%d ", next[i]);
    printf("%d\n", Kmp(s, t, n, w));
}