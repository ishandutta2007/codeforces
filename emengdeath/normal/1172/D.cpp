#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
using namespace std;
const int N = 1e4;
int n;
int a[N], aa[N], b[N], bb[N];
struct node{
    int x, y, xx, yy;
    node(int X = 0, int Y = 0, int XX = 0, int YY = 0) {
        x = X, y= Y, xx = XX, yy = YY;
    }
};
vector<node> ans;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++) {
        int x;
        scanf("%d",&x);
        aa[i] = x;
        a[x] = i;
    }
    for (int i = 1; i <= n ; i ++) {
        int x;
        scanf("%d",&x);
        b[x] = i;
        bb[i] = x;
    }
    for (int i = 1; i <= n ; i ++) {
        node u = node(i, b[i], a[i], i);
        if (b[i] == i && a[i] == i) continue;
        ans.push_back(u);
        int y = b[i], x = a[i], yy = bb[i], xx = aa[i];
        aa[a[xx] = x] = xx;
        bb[b[yy] = y] = yy;
    }
    printf("%d\n", ans.size());
    for (auto u:ans)
        printf("%d %d %d %d\n", u.x, u.y, u.xx, u.yy);
    return 0;
}