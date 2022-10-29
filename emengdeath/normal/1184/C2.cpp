#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
using namespace std;
const int N = 1e6 + 1;
int f[N * 20], tag[N * 20];
int n, r;
struct node{
    int x, ly, ry;
    bool is_del;
    node(int X = 0, int LY = 0, int RY = 0, bool IS_DEL = 0){
        x = X;
        ly = LY;
        ry = RY;
        is_del = IS_DEL;
    }
};
vector<node> a;
bool cmp(const node& a , const node &b){
    return a.x < b.x ||(a.x == b.x && a.is_del);
}
void ins(int l, int r, int s, int ll, int rr , int v){
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        tag[s] += v;
        f[s] += v;
        return;
    }
    ins(l, (l + r) /2 , s + s, ll, rr, v);
    ins((l + r) /2  + 1 , r, s + s + 1, ll, rr, v);
    f[s] = max(f[s + s], f[s + s  +1]) + tag[s];
}
int main() {
    scanf("%d %d", &n, &r);
    for (int i = 1; i <= n ; i ++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        int u, v;
        u = x + y;
        v = x - y;
        a.push_back(node(u - r, v - r, v + r, 0));
        a.push_back(node(u + r + 1, v - r, v + r, 1));
    }
    sort(a.begin(), a.end(), cmp);
    int ans = 1;
    for (auto u:a)
        if (u.is_del){
            ins(0, 4e6, 1, u.ly + 2000000, u.ry + 2000000, -1);
        } else {
            ins(0, 4e6, 1, u.ly + 2000000, u.ry + 2000000, 1);
            ans = max(ans, f[1]);
        }
    printf("%d\n",ans);
    return 0;
}