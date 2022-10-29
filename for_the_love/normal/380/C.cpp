#pragma  comment(linker, "/STACK:36777216")
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 7;
const int M = 1e5 + 7;
struct Pnode{
    int l, r, b;
} p[M];

char s[N];
int n, m, b[N], ans[M];
stack <int> Z;

bool cmp(Pnode a, Pnode b){return a.r < b.r;}


inline int lowbit(int x){return x & -x;}
int Q(int x){int ret = 0; for(; x; x -= lowbit(x)) ret += b[x]; return ret;}
void Add(int x){for(; x <= n; x += lowbit(x)) b[x]++;}
int Query(int x, int y){return Q(y) - Q(x - 1);}
int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%d%d", &p[i].l, &p[i].r);
        p[i].b = i;
    }
    sort(p, p + m, cmp);
    int j = 0;
    for (int i = 1; i <= n; i++){
        if (s[i] == '(') Z.push(i);
        else if (!Z.empty()){
            int k = Z.top();
            Add(k);
            Z.pop();
        }
        while (j < m && p[j].r == i){
            ans[p[j].b] = Query(p[j].l, p[j].r);
            j++;
        }
    }

    for (int i = 0; i < m; i++) printf("%d\n", ans[i] << 1);
}