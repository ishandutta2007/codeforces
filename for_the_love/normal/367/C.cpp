#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2222222;

struct Pnode{
    int a, b;
} p[N];



bool cmp(Pnode a, Pnode b){return a.b > b.b;}


int main(){
    int n, m, ans;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &p[i].a, &p[i].b);
    sort(p + 1, p + m + 1, cmp);
    for (long long i = 1; i <= m; i++){
        if (i % 2 == 1){
            if (i * (i - 1) / 2 + 1 <= n) ans = i;
        }else{
            if (i * (i - 2) / 2 + i <= n) ans = i;
        }
    }
    long long ret = 0;
    for (int i = 1; i <= ans; i++) ret += p[i].b;
    cout << ret << endl;
}