/* &*#()&*#)&E*F& */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;
const int INF = 1e9 + 7;
const int N = 3e5 + 5;
struct Pnode{
    int b, c, bel;
} p[N];
struct Heap{
    int a, b;
    bool operator < (const Heap & A) const{return a > A.a;}
} x;
struct Tnode{
    int a, b;
} t[N], q[N];
int n, m, s, res[N], res1[N];



priority_queue<Heap> H;

bool cmp(Pnode a, Pnode b){return a.b > b.b;}
bool cmp2(Tnode a, Tnode b){return a.a > b.a;}
bool check(int mid){
    while (!H.empty()) H.pop();
    int cnt = 0, now = 1;
    for (int i = 1; i <= m; i += mid) q[++cnt] = t[i];
    int l = 1;
    long long sum = 0;
    while (now <= cnt){
        while (l <= n){
            if (p[l].b < q[now].a) break;
            x.a = p[l].c;
            x.b = p[l].bel;
            H.push(x);
            l++;
        }
        if (H.empty()) return 0;
        x = H.top(); H.pop();
        if (sum + x.a > s) return 0;
        sum += x.a;
        for (int i = (now - 1) * mid + 1; i <= min(m, now * mid); i++) res1[t[i].b] = x.b;
        now++;
    }
    for (int i = 1; i <= m; i++) res[i] = res1[i];
    return 1;
}

int main(){
    //scanf("%d%d%d", &n, &m, &s);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) cin >> t[i].a;
    for (int i = 1; i <= m; i++) t[i].b = i;
    for (int i = 1; i <= n; i++) p[i].bel = i;
    for (int i = 1; i <= n; i++) cin >> p[i].b;
    for (int i = 1; i <= n; i++) cin >> p[i].c;
    sort(p + 1, p + n + 1, cmp);
    sort(t + 1, t + m + 1, cmp2);
    int l = 1, r = m, ans = 0;
    while (l <= r){
        int mid = l + r >> 1;
        if (check(mid)){
            ans = 1;
            r = mid - 1;
        }else l = mid + 1;
    }
    if (ans){
        puts("YES");
        for (int i = 1; i <= m; i++) printf("%d ", res[i]);
    }else puts("NO");
}