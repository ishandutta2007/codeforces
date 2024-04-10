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
const int N = 1e4 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
struct Pnode{
    int a, b;
} p[N];
int n;

bool cmp(Pnode a, Pnode b){
    if (a.a == b.a) return a.b < b.b;
    return a.a < b.a;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &p[i].a, &p[i].b);
    sort(p, p + n, cmp);
    int last = 0;
    for (int i = 0; i < n; i++)
    if (p[i].b >= last) last = p[i].b; else last = p[i].a;
    printf("%d\n", last);
}