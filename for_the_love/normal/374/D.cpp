#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1111111;

int t[N * 4], a[N], b[N], v[N];

#define lx x + x
#define rx lx + 1
void Add(int x, int l, int r, int a, int b){
    if (l == r){
        t[x] += b;
        return;
    }
    int mid = l + r >> 1;
    if (a <= mid) Add(lx, l, mid, a, b); else Add(rx, mid + 1, r, a, b);
    t[x] = t[lx] + t[rx];
}
int Find(int x, int l, int r, int k){
    if (l == r) return l;
    int mid = l + r >> 1;
    if (k <= t[lx]) return Find(lx, l, mid, k);
    else return Find(rx, mid + 1, r, k - t[lx]);
}
queue <int> Q;
int main(){
    //freopen("in.txt", "r", stdin);
    int n, m, cnt = 0, x;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        if (x == -1){
            for (int j = 1; j <= m; j++){
                if (t[1] < a[j]) break;
                else{
                    int p = Find(1, 1, 1000000, a[j]);
                    v[p] = 1;
                    Q.push(p);
                }
            }
            while (!Q.empty()){
                int p = Q.front(); Q.pop();
                Add(1, 1, 1000000, p, -1);
            }
        }else{
            Add(1, 1, 1000000, ++cnt, 1);
            b[cnt] = x;
        }
    }
    int flag = 0;
    for (int i = 1; i <= cnt; i++)
    if (!v[i]) flag = 1;
    if (!flag) puts("Poor stack!"); else for (int i = 1; i <= cnt; i++) if (!v[i]) printf("%d", b[i]);
}