#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

map <int, int>::iterator it;
map <int, int> S;
int n, m, i, t, a[100005], b[100005], v[100005], ans[100005], cnt, num, j;
int cmp(int a, int b){return a > b;}
int main(){
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++){
        scanf("%d", &b[i]);
        S[-b[i]]++;
    }
    sort(a + 1, a + n + 1, cmp);
    for (i = 1; i <= n; i++){
        t = m - a[i];
        it = S.upper_bound(-t);
        if (it != S.end()){
            ans[++cnt] = a[i] - it->first;
            v[i] = 1;
            it->second--;
            if (it->second == 0) S.erase(it->first);
        }
    }
    num = 0;
    for (i = 1; i <= n; i++)
    if (S[-b[i]]){
        S[-b[i]]--;
        b[++num] = b[i];
    }
    sort(b + 1, b + num + 1, cmp);
    int t = 0;
    for (i = 1; i <= n; i++)
    if (!v[i]) a[++t] = a[i];


    for (i = 1; i <= num; i++) ans[++cnt] = (a[i] + b[i]) % m;
    sort(ans + 1, ans + n + 1, cmp);
    for (i = 1; i <= n; i++) printf("%d ", ans[i]);
}